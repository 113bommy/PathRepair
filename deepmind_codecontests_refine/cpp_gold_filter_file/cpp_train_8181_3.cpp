#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 + 10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int realcmp(double a, double b) {
  return (a > b + eps) ? 1 : ((a + eps < b) ? -1 : 0);
}
int a[Maxn];
int f[Maxn][Maxn];
int pre[Maxn][Maxn];
pair<int, int> pp[Maxn][Maxn];
int main() {
  int n;
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    printf("%d\n%d\n", a[1], 1);
    return 0;
  }
  if (n == 2) {
    printf("%d\n%d %d\n", max(a[1], a[2]), 1, 2);
    return 0;
  }
  memset(pre, -1, sizeof(pre));
  memset(f, 0x7f, sizeof(f));
  f[1][1] = max(a[2], a[3]);
  pp[1][1] = pair<int, int>(2, 3);
  f[1][2] = max(a[1], a[3]);
  pp[1][2] = pair<int, int>(1, 3);
  f[1][3] = max(a[2], a[1]);
  pp[1][3] = pair<int, int>(1, 2);
  for (int i = 3; i <= n; i += 2) {
    if (i + 2 <= n) {
      for (int j = 1; j <= n; j++)
        if (f[(i + 1) / 2 - 1][j] != INF) {
          if (f[(i + 1) / 2][j] >
              f[(i + 1) / 2 - 1][j] + max(a[i + 1], a[i + 2])) {
            pre[(i + 1) / 2][j] = j;
            pp[(i + 1) / 2][j] = pair<int, int>(i + 1, i + 2);
            f[(i + 1) / 2][j] = f[(i + 1) / 2 - 1][j] + max(a[i + 1], a[i + 2]);
          }
          if (f[(i + 1) / 2][i + 1] >
              f[(i + 1) / 2 - 1][j] + max(a[j], a[i + 2])) {
            pre[(i + 1) / 2][i + 1] = j;
            pp[(i + 1) / 2][i + 1] = pair<int, int>(j, i + 2);
            f[(i + 1) / 2][i + 1] = f[(i + 1) / 2 - 1][j] + max(a[j], a[i + 2]);
          }
          if (f[(i + 1) / 2][i + 2] >
              f[(i + 1) / 2 - 1][j] + max(a[i + 1], a[j])) {
            pre[(i + 1) / 2][i + 2] = j;
            pp[(i + 1) / 2][i + 2] = pair<int, int>(j, i + 1);
            f[(i + 1) / 2][i + 2] = f[(i + 1) / 2 - 1][j] + max(a[i + 1], a[j]);
          }
        }
    } else if (i == n) {
      for (int j = 1; j <= n; j++)
        if (f[(i + 1) / 2 - 1][j] != INF)
          if (f[(i + 1) / 2][0] > f[(i + 1) / 2 - 1][j] + a[j]) {
            pre[(i + 1) / 2][0] = j;
            pp[(i + 1) / 2][0] = pair<int, int>(j, -1);
            f[(i + 1) / 2][0] = f[(i + 1) / 2 - 1][j] + a[j];
          }
    } else if (i + 1 == n) {
      for (int j = 1; j <= n; j++)
        if (f[(i + 1) / 2 - 1][j] != INF)
          if (f[(i + 1) / 2][0] > f[(i + 1) / 2 - 1][j] + max(a[j], a[i + 1])) {
            pre[(i + 1) / 2][0] = j;
            pp[(i + 1) / 2][0] = pair<int, int>(j, i + 1);
            f[(i + 1) / 2][0] = f[(i + 1) / 2 - 1][j] + max(a[j], a[i + 1]);
          }
    }
  }
  vector<pair<int, int> > ans;
  if (n & 1) {
    printf("%d\n", f[(n + 1) / 2][0]);
    int x = (n + 1) / 2, y = 0;
    while (pre[x][y] != -1) {
      ans.push_back(pp[x][y]);
      y = pre[x][y];
      x--;
    }
    ans.push_back(pp[x][y]);
    for (int i = ((int)(ans).size()) - 1; i >= 1; i--)
      printf("%d %d\n", ans[i].first, ans[i].second);
    printf("%d\n", ans[0].first);
  } else {
    printf("%d\n", f[(n + 1) / 2][0]);
    int x = (n + 1) / 2, y = 0;
    while (pre[x][y] != -1) {
      ans.push_back(pp[x][y]);
      y = pre[x][y];
      x--;
    }
    ans.push_back(pp[x][y]);
    for (int i = ((int)(ans).size()) - 1; i >= 0; i--)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
