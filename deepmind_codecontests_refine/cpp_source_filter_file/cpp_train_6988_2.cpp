#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, mnrow[N][N], mnlast[N][N], a[N][10010], mem[1 << N][N], start, ans;
int dp(int msk, int last) {
  if (__builtin_popcount(msk) == n) return mnlast[last][start];
  int &ret = mem[msk][last];
  if (ret != -1) return ret;
  for (int i = 0; i < n; i++)
    if (!((1 << i) & msk))
      ret = max(ret, min(mnrow[last][i], dp(msk | (1 << i), i)));
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int mn = 1e9 + 1;
      for (int k = 0; k < m; k++) mn = min(mn, abs(a[i][k] - a[j][k]));
      mnrow[i][j] = mn;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int mn = 1e9 + 1;
      for (int k = 0; k < m - 1; k++) mn = min(mn, abs(a[i][k] - a[j][k + 1]));
      mnlast[i][j] = mn;
    }
  if (n == 1) {
    int mn = 1e9 + 10;
    for (int i = 1; i < m; i++) mn = min(mn, a[0][i] - a[0][i - 1]);
    printf("%d", mn);
    return 0;
  }
  for (; start < n; start++) {
    memset(mem, -1, sizeof mem);
    ans = max(ans, dp(1 << start, start));
  }
  printf("%d", ans);
}
