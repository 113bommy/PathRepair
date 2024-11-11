#include <bits/stdc++.h>
using namespace std;
long long Min(long long i, long long j) { return i < j ? i : j; }
long long Max(long long i, long long j) { return i > j ? i : j; }
int main() {
  long long a, b, c, d, e, i, j, k, l, m, n;
  while (cin >> n >> m) {
    cout << 1 + m - 1 + n - 1 << endl;
    cout << n << ' ' << m << endl;
    b = n - 1;
    a = m - 1;
    int b_n = 1;
    while (b && a) {
      if (b_n == 1) {
        cout << b << ' ' << m << endl;
        b--;
        b_n = 0;
      } else {
        cout << n << ' ' << a << endl;
        a--;
        b_n = 1;
      }
    }
    if (b == 0) {
      while (a) {
        cout << n << ' ' << a << endl;
        a--;
      }
    } else {
      while (b) {
        cout << b << ' ' << m << endl;
        b--;
      }
    }
  }
  return 0;
}
