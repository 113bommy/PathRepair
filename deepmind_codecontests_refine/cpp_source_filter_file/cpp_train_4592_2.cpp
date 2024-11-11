#include <bits/stdc++.h>
using namespace std;
long long n, m, i1;
long long cont = 0;
int main() {
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    if (x - y != 1) {
      cout << "NO" << endl;
    } else {
      long long p = x + y, s = 0;
      for (long long j = 2; j < sqrt(p); ++j) {
        if (p % j == 0) {
          s = 1;
          break;
        }
      }
      if (s == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
