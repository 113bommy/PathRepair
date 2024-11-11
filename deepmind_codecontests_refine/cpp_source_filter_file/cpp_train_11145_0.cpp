#include <iostream>
using namespace std;

void primeFactorize(int n) {
    for (int i = 2;i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            cout << ' ' << i;
        }
    }
    if (n != 1) {
        cout << ' ' << n;
    }
}
int main() {
    int n;
    cin >> n;
    cout << n << ':';
    prime_fac(n);
    cout << endl;
}