#include <bits/stdc++.h>
using namespace std;
const int N = 22, D = 26, oo = 1000000000;
int i, j, k, n, m;
int a[N][N], cost[N][D], ma[N][D], mi[N], state[N][D], f[N][1 << 20];
char s[N][N];
int min(const int &x, const int &y) {
  if (x < y) return x;
  return y;
}
int max(const int &x, const int &y) {
  if (x < y) return y;
  return x;
}
void Up(int &x, const int &y) {
  if (y < x) x = y;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(f, 60, sizeof f);
  memset(mi, 60, sizeof mi);
  for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      mi[i] = min(mi[i], a[i][j]);
      cost[j][s[i][j] - 'a'] += a[i][j],
          ma[j][s[i][j] - 'a'] = max(ma[j][s[i][j] - 'a'], a[i][j]);
      state[j][s[i][j] - 'a'] |= 1 << i - 1;
    }
  f[0][0] = 0;
  for (i = 0; i < n; i++)
    for (j = (1 << i) - 1; j < (1 << n); j += 1 << i)
      if (f[i][j] < oo) {
        if (j & 1 << i) Up(f[i + 1][j], f[i][j]);
        Up(f[i + 1][j | 1 << i], f[i][j] + mi[i + 1]);
        for (k = 1; k <= m; k++)
          Up(f[i + 1][j | state[k][s[i + 1][k] - 'a']],
             f[i][j] + cost[k][s[i + 1][k] - 'a'] - ma[k][s[i + 1][k] - 'a']);
      }
  printf("%d\n", f[n][(1 << n) - 1]);
}
