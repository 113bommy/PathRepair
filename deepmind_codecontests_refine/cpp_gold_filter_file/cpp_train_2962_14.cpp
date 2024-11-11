#include <bits/stdc++.h>
using namespace std;
int s[510][510];
int val[510];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  memset(s, 0, sizeof(s));
  int x, y, c;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &c);
    s[x][y] = c;
  }
  double ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == 0) continue;
      double ans1 = (val[i] + val[j]) * 1.0 / s[i][j];
      ans = ans < ans1 ? ans1 : ans;
    }
  printf("%.15lf\n", ans);
  return 0;
}
