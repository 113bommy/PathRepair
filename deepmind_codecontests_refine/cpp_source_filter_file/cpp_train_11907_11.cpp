#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int n, m;
int a[maxn];
double p[maxn][maxn];
double tmp1[maxn], tmp2[maxn];
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[j] > a[i]) p[i][j] = 1;
    }
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; i++) tmp1[i] = (p[i][x] + p[i][y]) / 2.0;
    for (int i = 1; i <= n; i++) tmp2[i] = (p[y][i] + p[x][i]) / 2.0;
    for (int i = 1; i <= n; i++) p[i][x] = p[i][y] = tmp1[i];
    for (int i = 1; i <= n; i++) p[x][i] = p[y][i] = tmp2[i];
    p[x][y] = p[y][x] = 0.5;
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += p[i][j];
    }
  }
  printf("%0.6lf\n", ans);
  return 0;
}
