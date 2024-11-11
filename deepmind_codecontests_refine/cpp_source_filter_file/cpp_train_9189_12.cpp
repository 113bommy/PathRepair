#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long mod = 998244353, inf = 1e18;
const long long g = 3;
template <class T>
void Mul(T &x, T y) {
  x = x * y % mod;
}
template <class T>
void Add(T &x, T y) {
  x = (x + y) % mod;
}
template <class T>
void Sub(T &x, T y) {
  x = (x - y + mod) % mod;
}
template <class T>
void Mn(T &x, T y) {
  x = min(x, y);
}
template <class T>
void Mx(T &x, T y) {
  x = max(x, y);
}
long long qpow(long long x, long long y = mod - 2) {
  long long res = 1;
  while (y) {
    if (y & 1) Mul(res, x);
    Mul(x, x), y >>= 1;
  }
  return res;
}
void Div(long long &x, long long y) { Mul(x, qpow(y)); }
int n, m, k, T;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x[3], y[3];
  cin >> T;
  while (T--) {
    for (int i = 1; i <= 2; i++) cin >> x[i] >> y[i];
    if (x[1] == x[2]) {
      cout << abs(y[2] - y[1]) << '\n';
      continue;
    }
    if (y[1] == y[2]) {
      cout << abs(x[2] - x[1]) << '\n';
      continue;
    }
    cout << abs(x[2] - x[1]) + (y[2] - y[1]) + 2 << '\b';
  }
}
