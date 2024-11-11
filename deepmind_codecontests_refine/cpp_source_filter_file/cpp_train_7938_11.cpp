#include <bits/stdc++.h>
using namespace std;
long long powe(long long n, long long m) {
  if (m == 0) return 1;
  long long t = powe(n, m / 2);
  if (m % 2 == 0) return (t * t);
  return (((t * t)) * n);
}
long long mpowe(long long n, long long m, long long MOD) {
  if (m == 0) return 1;
  long long t = mpowe(n, m / 2, MOD);
  t %= MOD;
  if (m % 2 == 0) return (t * t) % MOD;
  return (((t * t) % MOD) * n) % MOD;
}
long long logtwo(long long n) {
  if (n == 1) return 0;
  if (n == 0) return -1;
  return logtwo(n / 2) + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  cout << x << " " << y << endl;
  for (int i = x; i <= n; i++) {
    if ((i - x) % 2 == 0) {
      for (int j = 1; j <= m; j++) {
        if (!(i == x && j == y)) {
          cout << i << " " << j << endl;
        }
      }
    } else {
      for (int j = m; j >= 1; j--) {
        if (!(i == x && j == y)) {
          cout << i << " " << j << endl;
        }
      }
    }
  }
  for (int i = 1; i < x; i++) {
    if ((i + n) % 2 == 0) {
      for (int j = 1; j <= m; j++) {
        if (!(i == x && j == y)) {
          cout << i << " " << j << endl;
        }
      }
    } else {
      for (int j = m; j >= 1; j--) {
        if (!(i == x && j == y)) {
          cout << i << " " << j << endl;
        }
      }
    }
  }
}
