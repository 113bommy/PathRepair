#include <bits/stdc++.h>
using namespace std;
const int maxN = 200005;
const int inf = 214748364;
int n, m, g[21][1 << 20], f[maxN], v[maxN], s[maxN];
int cost(int a, int b) {
  for (int i = m; i >= 0; --i) {
    if ((a & ((1 << i) - 1)) == (b >> (m - i))) return m - i;
  }
}
void init() {
  char c[25];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", c + 1);
    m = strlen(c + 1);
    for (int j = 1; j <= m; ++j) v[i] = (v[i] << 1) + c[j] - 48;
  }
  s[1] = m;
  for (int i = 2; i <= n; ++i) s[i] = s[i - 1] + cost(v[i - 1], v[i]);
}
void work() {
  int ans = inf;
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= (1 << m) - 1; ++j) g[i][j] = inf;
  g[0][0] = 0;
  f[1] = m;
  for (int i = 2; i <= n; ++i) {
    f[i] = inf;
    for (int j = 0; j <= m; ++j) {
      int tmp = s[i - 1] + g[j][v[i] >> (m - j)] + m - j;
      f[i] = ((f[i]) < (tmp) ? (f[i]) : (tmp));
    }
    for (int j = 0; j <= m; ++j)
      g[j][v[i - 1] & ((1 << j) - 1)] =
          ((g[j][v[i - 1] & ((1 << j) - 1)]) < (f[i] - s[i])
               ? (g[j][v[i - 1] & ((1 << j) - 1)])
               : (f[i] - s[i]));
  }
  for (int i = 1; i <= n; ++i)
    ans = ((ans) < (f[i] + s[n] - s[i]) ? (ans) : (f[i] + s[n] - s[i]));
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
