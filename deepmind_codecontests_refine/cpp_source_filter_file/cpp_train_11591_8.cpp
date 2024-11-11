#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4010;
int n, k;
pair<int, int> a[MAXN];
int f[MAXN][MAXN];
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
void init() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second);
}
void solve() {
  sort(a + 0, a + n);
  memset(f, 0x7f, sizeof(f));
  f[0][0] = 1;
  int i, j, ans = 0;
  a[n].first = a[n].second = 86400;
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= k; ++j)
      if (f[i][j] < 86400) {
        f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
        ans = max(ans, a[i].first - f[i][j]);
        f[i + 1][j] = min(f[i + 1][j], max(f[i][j], a[i].first) + a[i].second);
      }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
