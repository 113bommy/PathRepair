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
const int mods = 1e9 + 7;
const int MAXN = 1100005;
const int P = 1e7 + 19;
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
int S[MAXN], f[MAXN], cnt[MAXN];
signed main() {
  int n = read(), m = read(), d = read(), M = (1 << m) - 1;
  for (int i = 1; i <= m; i++) {
    int t = read();
    for (int j = 1, x; j <= t; j++) x = read() - 1, S[x] |= 1 << (i - 1);
  }
  for (int i = 0; i < d; i++)
    for (int j = 0; j < m; j++)
      if ((S[i] >> j) & 1) cnt[j]++;
  for (int i = 0; i <= n - d; i++) {
    int s = 0;
    for (int j = 0; j < m; j++)
      if (cnt[j]) s |= 1 << j;
    f[M ^ s] = 1;
    for (int j = 0; j < m; j++) {
      if ((S[i + d] >> j) & 1) cnt[j]++;
      if ((S[i] >> j) & 1) cnt[j]--;
    }
  }
  for (int i = M; i >= 0; i--)
    for (int j = 0; j < m; j++) f[i] |= f[i | (1 << j)];
  int ans = m;
  for (int i = 0; i <= M; i++)
    if (!f[i]) upmin(ans, __builtin_popcount(i));
  printf("%d\n", ans);
  return 0;
}
