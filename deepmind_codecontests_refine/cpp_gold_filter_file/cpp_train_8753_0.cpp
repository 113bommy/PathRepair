#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const long long N = 1e5 + 5, M = 1e9 + 7;
long long c[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, i, j, k, m, sm, sm2 = 0, x, y;
  cin >> n >> k >> sm;
  j = (n - 1) * k;
  if (k > sm || j < sm) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  x = n - 1;
  y = k;
  j = 1;
  while (y--) {
    if (k + x <= sm) {
      if (j == 1) {
        cout << x + 1 << ' ';
        j = x + 1;
      } else {
        cout << 1 << ' ';
        j = 1;
      }
      sm -= x;
      k--;
    } else {
      x = sm - k + 1;
      k--;
      if (j == 1) {
        cout << j + x << ' ';
        j = j + x;
      } else {
        cout << j - x << ' ';
        j = j - x;
      }
      if (j - 1 > 0) {
        long long fl = -1;
        while (k--) {
          if (fl == -1)
            cout << j - 1 << ' ';
          else
            cout << j << ' ';
          fl *= -1;
        }
      } else {
        long long fl = -1;
        while (k--) {
          if (fl == -1)
            cout << j + 1 << ' ';
          else
            cout << j << ' ';
          fl *= -1;
        }
      }
      return 0;
    }
  }
}
