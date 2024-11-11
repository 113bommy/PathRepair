#include <iostream>

int main() {
    using namespace std;

    int a, b, c, d, e;
    int k;

    cin >> a >> b >> c >> d >> e >> k;
    cout << (e - a) > k ? ":(" : "Yay!" << endl;
}