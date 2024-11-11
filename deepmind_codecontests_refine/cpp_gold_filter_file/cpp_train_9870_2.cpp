#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < 13) b /= 2;
    if (a < 6) b = 0;
    cout << b << endl;
}