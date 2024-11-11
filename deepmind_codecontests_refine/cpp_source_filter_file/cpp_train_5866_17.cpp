#include <bits/stdc++.h>
using namespace std;
int n, m;
double p[305][3005], f[305][3005], e[305], tmp[3005], sum[305];
void calc(int r) {
  tmp[0] = 0;
  for (int i = 1; i <= n; i++)
    tmp[i] = p[r][i] * f[r][i] + (1 - p[r][i]) * tmp[i - 1];
  for (int i = 0; i <= n; i++) f[r][i] = tmp[i];
  sum[r] += f[r][n];
}
int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return x;
}
int main() {
  int x;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &x), p[j][i] = x / 1000.0;
  for (int i = 1; i <= m; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= n; j++) f[i][j] = f[i][j - 1] * (1 - p[i][j]);
    sum[i] = f[i][n];
  }
  int cnt = n;
  double ans = 0;
  while (cnt--) {
    int id = 0;
    sum[0] = 1;
    for (int i = 1; i <= m; i++)
      if (sum[i] < sum[id]) id = i;
    ans += 1 - sum[id];
    calc(id);
  }
  printf("%.9lf", ans);
  return 0;
}
