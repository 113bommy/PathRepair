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
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long mods = 998244353;
const long long MAXN = 100005;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
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
char st[MAXN];
long long f[MAXN][11];
signed main() {
  scanf("%s", st + 1);
  long long n = strlen(st + 1), ans = 0;
  for (long long i = n; i >= 1; i--) {
    for (long long j = 0; j < 11; j++) {
      f[i][j] = 1;
      if (i < n && j > st[i + 1] - '0')
        f[i][j] += f[i + 1][(j * (j - 1) / 2 + (st[i + 1] - '0') + 10) % 11];
    }
    if (st[i] != '0') ans += f[i][st[i] - '0'];
  }
  printf("%d\n", ans);
  return 0;
}
