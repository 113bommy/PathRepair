#include <bits/stdc++.h>
inline long long rd() {
  long long _x = 0;
  int _ch = getchar(), _f = 1;
  for (; !isdigit(_ch) && (_ch != '-') && (_ch != EOF); _ch = getchar())
    ;
  if (_ch == '-') {
    _f = 0;
    _ch = getchar();
  }
  for (; isdigit(_ch); _ch = getchar()) _x = _x * 10 + _ch - '0';
  return _f ? _x : -_x;
}
void write(long long _x) {
  if (_x >= 10)
    write(_x / 10), putchar(_x % 10 + '0');
  else
    putchar(_x + '0');
}
inline void wrt(long long _x, char _p) {
  if (_x < 0) putchar('-'), _x = -_x;
  write(_x);
  if (_p) putchar(_p);
}
int solve(int a, int n, int p) {
  int t = 1ll * a * n / p;
  if (!t) return std::max(a, p - a * n);
  return solve(a - p % a, t - (1ll * a * n % p < (p / a - 1) * a), a);
}
int main() {
  int T = rd();
  while (T--) {
    int a = rd(), n = rd(), p = rd(), h = rd();
    if (1ll * (a % p) * n < p) {
      if (a % p <= h)
        printf("YES\n");
      else
        printf("NO\n");
      continue;
    }
    if (h >= solve(a % p, n, p))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
