#include <bits/stdc++.h>
using namespace std;
template <typename T>
string NumberToString(T Number) {
  std::ostringstream second;
  second << Number;
  return second.str();
}
long long qpow(long long p, long long q) {
  long long f = 1;
  while (q) {
    if (q & 1) f = f * p % 1000000007LL;
    p = p * p % 1000000007LL;
    q >>= 1;
  }
  return f;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const long long mod7 = 998244353LL;
inline long long add(long long _x, long long _y, long long _mod = mod7) {
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline long long sub(long long _x, long long _y, long long _mod = mod7) {
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline long long mul(long long _x, long long _y, long long _mod = mod7) {
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
int const N = 553;
long long t[N][N], cum[N][N];
int main() {
  for (auto ik = 0; ik < (501); ++ik) cum[0][ik] = 1LL;
  for (int in = 1; in <= 500; ++in) {
    for (int ik = 1; ik <= in; ++ik) {
      for (int before = 0; (in - ik - before) >= 0; ++before) {
        t[in][ik] =
            add(t[in][ik],
                mul(cum[before][min(before, ik - 1)],
                    cum[(in - ik - before)][min((in - ik - before), ik)]));
      }
      cum[in][ik] = add(cum[in][ik - 1], t[in][ik]);
    }
  }
  int n, k;
  cin >> n >> k;
  long long sol = 0LL;
  for (int a = 1; a < min(k, n + 1); ++a) {
    if (k % a == 0)
      sol = add(sol, mul(t[n][a], cum[n][min(n, (k - 1) / a)]));
    else
      sol = add(sol, mul(t[n][a], cum[n][min(n, k / a)]));
  }
  cout << mul(sol, 2LL);
  return 0;
}
