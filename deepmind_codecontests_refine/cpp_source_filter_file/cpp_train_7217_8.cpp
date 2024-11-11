#include <bits/stdc++.h>
using namespace std;
double a[18][18], dp[18][1 << 18], c[1 << 18];
int n, g[1 << 18][18 + 1];
void init() {
  for (int i = 0; i < (1 << n); i++) {
    g[i][0] = 0;
    for (int j = 0; j < n; j++) {
      dp[j][i] = -100;
      if ((1 << j) & i) g[i][++g[i][0]] = j;
    }
    if (g[i][0] >= 2) c[i] = 2 / g[i][0] / (g[i][0] - 1);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i == j)
        dp[i][1 << j] = 1;
      else
        dp[i][1 << j] = 0;
}
double cal(int u, int s) {
  double &now = dp[u][s];
  if (now >= 0) return now;
  now = 0;
  int x, y;
  for (int i = 1; i <= g[s][0]; i++) {
    for (int j = i + 1; j <= g[s][0]; j++) {
      x = g[s][i];
      y = g[s][j];
      if (y == u) swap(x, y);
      if (x != u)
        now +=
            (a[x][y] * cal(u, s ^ (1 << y)) + a[y][x] * cal(u, s ^ (1 << x))) *
            c[s];
      else
        now += (a[x][y] * cal(u, s ^ (1 << y))) * c[s];
    }
  }
  return now;
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> a[i][j];
    init();
    for (int i = 0; i < n; i++)
      printf("%.6f%c", cal(i, (1 << n) - 1), i < n - 1 ? ' ' : '\n');
  }
  return 0;
}
