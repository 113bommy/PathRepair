#include <bits/stdc++.h>
using namespace std;
double p[1005][1005], s[1005][1005];
int n, m;
int main() {
  scanf("%d", &n);
  for (int i = (1), iend = (n); i <= iend; i++) {
    int x;
    scanf("%d", &x);
    p[x][i] = 1.0;
  }
  for (int i = (1), iend = (m); i <= iend; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int j = (1), jend = (n); j <= jend; j++) {
      double mid = (p[j][x] + p[j][y]) / 2.0;
      p[j][x] = p[j][y] = mid;
    }
  }
  for (int i = (1), iend = (n); i <= iend; i++)
    for (int j = (1), jend = (n); j <= jend; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + p[i][j];
  double ans = n * (n - 1) / 2.0;
  for (int i = (1), iend = (n); i <= iend; i++)
    for (int j = (1), jend = (n); j <= jend; j++)
      ans -= p[i][j] * (s[i - 1][j - 1] + s[i - 1][j]) / 2.0;
  printf("%.9lf", ans);
  return 0;
}
