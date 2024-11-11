#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int MAXN = 600005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long f[205][205], s[205], C[205][205], n, d, mods;
long long upd(long long x, long long y) {
  return x + y >= mods ? x + y - mods : x + y;
}
void Init() {
  for (int i = 0; i <= n; i++) C[i][0] = C[i][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++) C[i][j] = upd(C[i - 1][j], C[i - 1][j - 1]);
}
int main() {
  n = read(), d = read(), mods = read();
  Init();
  f[1][0] = s[1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= d; j++) {
      for (int k = 1; k <= i - j; k++)
        f[i][j] = upd(f[i][j],
                      f[i - k][j - 1] * s[k] % mods * C[i - 2][k - 1] % mods);
      if (j != d) s[i] = upd(s[i], f[i][j]);
    }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= d; j++)
      for (int k = 0; k <= d; k++)
        if (k != 1) ans = upd(ans, f[i][j] * f[n - i + 1][k] % mods);
  printf("%lld\n", ans * n % mods * (n - 1) % mods * 2 % mods);
  return 0;
}
