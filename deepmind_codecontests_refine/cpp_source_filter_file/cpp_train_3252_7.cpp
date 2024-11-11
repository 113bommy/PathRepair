#include <bits/stdc++.h>
using namespace std;
int M = 1000000007;
int main() {
  int q = 1;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    int i = 0;
    while (pow(4, i) - 1 < n) i++;
    long long t1 = pow(4, i - 1) - 1;
    long long t = n - t1;
    t = (t + 2) / 3;
    long long a = t1 + t;
    long long b = 0;
    long long x = a;
    int temp = 1;
    int r[] = {0, 2, 3, 1};
    while (x) {
      b += temp * r[x % 4];
      x /= 4;
      temp *= 4;
    }
    long long c = a ^ b;
    switch (n % 3) {
      case 1:
        cout << a;
        break;
      case 2:
        cout << b;
        break;
      case 0:
        cout << c;
        break;
    }
    cout << endl;
  }
  return 0;
}
