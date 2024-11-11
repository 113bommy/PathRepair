#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int n, m, w;
int dp[maxn][maxn][3];
struct node {
  int w, b, p;
} a[maxn];
int Find(int x) { return a[x].p == x ? x : a[x].p = Find(a[x].p); }
bool cmp(node x, node y) { return x.p < y.p; }
void upd(int x, int z, int &y) {
  if (x == -1) return;
  y = max(y, x + z);
}
int main() {
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].w);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].b), a[i].p = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int xx = Find(x), yy = Find(y);
    if (xx != yy) a[xx].p = yy;
  }
  for (int i = 1; i <= n; i++) a[i].p = Find(i);
  sort(a + 1, a + n, cmp);
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int l = 0; l <= w; l++) {
    for (int i = 1, j = 1; i <= n; i = j) {
      int sumb = 0, sumw = 0;
      for (j = i; j <= n && a[j].p == a[i].p; j++)
        sumb += a[j].b, sumw += a[j].w;
      for (int k = i; k < j; k++) {
        if (k == i) {
          upd(max(dp[k - 1][l][1], max(dp[k - 1][l][2], dp[k - 1][l][0])), 0,
              dp[k][l][0]);
          int x = a[i].w;
          if (l >= x)
            upd(max(dp[k - 1][l - x][0],
                    max(dp[k - 1][l - x][1], dp[k - 1][l - x][2])),
                a[i].b, dp[k][l][1]);
        } else {
          upd(dp[k - 1][l][0], 0, dp[k][l][0]);
          upd(dp[k - 1][l][1], 0, dp[k][l][1]);
          int x = a[i].w;
          if (l >= x) upd(dp[k - 1][l - x][0], a[i].b, dp[k][l][1]);
        }
        if (k == j - 1) {
          if (l >= sumw) {
            if (k == i)
              upd(max(dp[k - 1][l - sumw][1],
                      max(dp[k - 1][l - sumw][2], dp[k - 1][l - sumw][0])),
                  sumb, dp[k][l][2]);
            else
              upd(dp[k - 1][l - sumw][0], sumb, dp[k][l][2]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int l = 0; l <= w; l++) {
    for (int j = 0; j < 3; j++) ans = max(ans, dp[n][l][j]);
  }
  printf("%d\n", max(0, ans));
  return 0;
}
