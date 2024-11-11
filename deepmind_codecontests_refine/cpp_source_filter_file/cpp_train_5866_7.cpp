#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n, m;
double p[N][N];
double f[N][N], tmp[N];
double g[N], ans;
int cnt[N];
void update(int x) {
  cnt[x]++;
  if (cnt[x] >= n) {
    g[x] = 0;
    return;
  }
  for (int i = 1; i <= n; i++) tmp[i] = f[x][i];
  f[x][0] = 0.0;
  for (int i = 1; i <= n; i++)
    f[x][i] = f[x][i - 1] * (1.0 - p[i][x]) + tmp[i - 1] * p[i][x];
  g[x] -= f[x][n];
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%lf", &p[i][j]), p[i][j] /= 1000.0;
  for (int i = 1; i <= m; i++) {
    f[i][0] = 1.0;
    for (int j = 1; j <= n; j++) f[i][j] = f[i][j - 1] * (1.0 - p[j][i]);
    g[i] = 1.0 - f[i][n];
  }
  for (int i = 1; i <= n; i++) {
    int maxpos = -1;
    double maxval = 0;
    for (int j = 1; j <= m; j++)
      if (g[j] > maxval) maxpos = j, maxval = g[j];
    ans += g[maxpos];
    update(maxpos);
  }
  printf("%.12lf\n", ans);
  return 0;
}
