#include <iostream>
using namespace std;

class FlatPlane {
private:
    int x, y;

public:
    FlatPlane() {
        x = 0;
        y = 0;
    }

    virtual void input() {}
    virtual float Area(int a) { return 0; }
    virtual float Circumference(int a) { return 0; }
    virtual void checkSize() { return; }


    void setX(int a) {
        this->x = a;
    }

    void setY(int a) {
        this->y = a;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Circle : public FlatPlane {
public:
    void input() {
        int r;
        cout << "Insert radius: ";
        cin >> r;
        setX(r);
    }

    float Area(int r) {
        return 3.14159 * r * r;
    }

    float Circumference(int r) {
        return 2 * 3.14159 * r;
    }

    void checkSize() {
        float circumference = Circumference(getX());
        cout << "Circle Area = " << Area(getX()) << endl;
        cout << "Circumference = " << circumference << endl;
        cout << "The size of the circle is ";
        if (circumference > 40)
            cout << "Large" << endl;
        else if (circumference < 20)
            cout << "Medium" << endl;
        else if (circumference < 10)
            cout << "Small" << endl;
        cout << endl;
    }
};

class Rectangle : public FlatPlane {
public:
    void input() {
        int l, w;
        cout << "Enter length: ";
        cin >> l;
        setX(l);
        cout << "Enter width: ";
        cin >> w;
        setY(w);
    }

    float Area(int l, int w) {
        return l * w;
    }

    float Perimeter(int l, int w) {
        return 2 * (l + w);
    }

    void checkSize() {
        float perimeter = Perimeter(getX(), getY());
        cout << "Area of Rectangle = " << Area(getX(), getY()) << endl;
        cout << "Perimeter of Rectangle = " << perimeter << endl;
        cout << "Rectangle Size: ";
        if (perimeter > 40)
            cout << "Large" << endl;
        else if (perimeter < 20)
            cout << "Medium" << endl;
        else if (perimeter < 10)
            cout << "Small" << endl;
        cout << endl;
    }
};

int main() {
    char repeat;
    do {
        int choice;
        cout << "1. Circle\n";
        cout << "2. Rectangle\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Circle circle;
            circle.input();
            circle.checkSize();
            break;
        }
        case 2: {
            Rectangle rectangle;
            rectangle.input();
            rectangle.checkSize();
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "Do you want to repeat the program? (Y/N): ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
