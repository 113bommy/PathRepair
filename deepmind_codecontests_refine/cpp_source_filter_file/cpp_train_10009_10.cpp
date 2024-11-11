#include <bits/stdc++.h>
const double EPS = 1e-9;
using namespace std;
const int N = 1000 + 100;
int n, m, row[N], col[N];
int tp[N], pos[N][N][2];
int mp[N][N], ans[N][N];
void init() {
  for (int i = 1; i <= n; i++) {
    int tot = m;
    for (int j = 1; j <= m; j++) tp[j] = mp[i][j];
    sort(tp + 1, tp + 1 + tot);
    tot = unique(tp + 1, tp + tot + 1) - tp - 1;
    row[i] = tot;
    for (int j = 1; j <= m; j++) {
      int x = lower_bound(tp + 1, tp + 1 + tot, mp[i][j]) - tp;
      pos[i][j][0] = x;
    }
  }
  for (int i = 1; i <= m; i++) {
    int tot = m;
    for (int j = 1; j <= n; j++) tp[j] = mp[j][i];
    sort(tp + 1, tp + 1 + tot);
    tot = unique(tp + 1, tp + tot + 1) - tp - 1;
    col[i] = tot;
    for (int j = 1; j <= n; j++) {
      int x = lower_bound(tp + 1, tp + 1 + tot, mp[j][i]) - tp;
      pos[j][i][1] = x;
    }
  }
}
void solve() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int m1 = row[i], m2 = col[j];
      int x1 = pos[i][j][0], x2 = pos[i][j][1];
      if (x1 < x2)
        m1 += x2 - x1;
      else if (x1 > x2)
        m2 += x1 - x2;
      ans[i][j] = max(m1, m2);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      printf("%d", ans[i][j]);
      if (j == m)
        printf("\n");
      else
        printf(" ");
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &mp[i][j]);
  init();
  solve();
  return 0;
}
