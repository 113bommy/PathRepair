#include <bits/stdc++.h>
using namespace std;
const int N = 2E5 + 5;
const int M = 60;
struct map {
  long double x, y;
} a[N];
int n, m, b[N], r, h, l[N], x;
long long f[N];
long double g[N], t[N], dp[M][N];
void add(int i) {
  for (; r >= 2 && (a[l[r]].y - a[i].y) * (a[l[r]].x - a[l[r - 1]].x) >=
                       (a[l[r]].x - a[i].x) * (a[l[r]].y - a[l[r - 1]].y);
       r--)
    ;
  l[++r] = i;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    f[i] = f[i - 1] + x;
    dp[1][i] = g[i] = g[i - 1] + (long double)f[i] / x;
    t[i] = t[i - 1] + (long double)1.0 / x;
  }
  for (int i = 1; i < m; i++) {
    h = 1;
    r = 0;
    for (int j = i; j < n; j++) {
      a[j].x = f[j];
      a[j].y = t[j] * f[j] - g[j] + dp[i][j];
      add(j);
      for (; h < r && t[j + 1] * (a[l[h + 1]].x - a[l[h]].x) >=
                          a[l[h + 1]].y - a[l[h]].y;
           h++)
        ;
      x = l[h];
      dp[i + 1][j + 1] = g[j + 1] - g[x] - (t[j + 1] - t[x]) * f[x] + dp[i][x];
    }
  }
  printf("%.6f", dp[m][n]);
}
