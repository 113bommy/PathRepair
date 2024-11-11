#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m;
int c[MAXN + 1];
int f[MAXN + 1];
int g[2][MAXN + 1];
int ans;
int main(int argc, char const *argv[]) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    c[l]++, c[r + 1]--;
  }
  for (int i = 1; i <= m; i++) c[i] += c[i - 1];
  memset(f, 0x7f, sizeof(f));
  for (int i = 1; i <= m; i++) {
    int pos = upper_bound(f, f + m, c[i]) - f;
    f[pos] = c[i];
    g[0][i] = pos + 1;
  }
  for (int i = 1; i <= m / 2; i++) swap(c[i], c[m - i + 1]);
  memset(f, 0x7f, sizeof(f));
  for (int i = 1; i <= m; i++) {
    int pos = upper_bound(f, f + m, c[i]) - f;
    f[pos] = c[i];
    g[1][i] = pos + 1;
  }
  for (int i = 1; i <= m; i++) ans = max(ans, g[0][i] + g[1][m - i + 1] - 1);
  printf("%d\n", ans);
  return 0;
}
