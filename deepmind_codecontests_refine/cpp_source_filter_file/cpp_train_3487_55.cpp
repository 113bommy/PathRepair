#include <bits/stdc++.h>
using namespace std;
int N, a[2][22][22];
const int inf = 1e9;
int res;
int x[22], y[22], z[22], bef[22], d[22];
int g[22][22];
bool visited[22];
void dfs(int str, int p1, int p2) {
  if (str > N) {
    res = max(res, y[0]);
    return;
  }
  int tx[22], ty[22], tz[22];
  for (int k = 0; k < 2; k++) {
    if (p1 + k > N / 2 || p2 + (k ^ 1) > N / 2) continue;
    for (int i = 0; i <= N; i++) tx[i] = x[i], ty[i] = y[i], tz[i] = z[i];
    for (int i = 0; i <= N; i++) visited[i] = 0, d[i] = inf;
    for (int i = 1; i <= N; i++) g[str][i] = -a[k][i][str];
    z[0] = str;
    int r = 0;
    while (z[r] != -1) {
      visited[r] = 1;
      int z1 = z[r], nxtr;
      int slack = inf;
      for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
          int t = g[z1][i] - x[z1] - y[i];
          if (t < d[i]) {
            d[i] = t;
            bef[i] = r;
          }
          if (d[i] < slack) {
            slack = d[i];
            nxtr = i;
          }
        }
      }
      for (int i = 0; i <= N; i++) {
        if (visited[i]) {
          x[z[i]] += slack;
          y[i] -= slack;
        } else
          d[i] -= slack;
      }
      r = nxtr;
    }
    while (r) {
      x[r] = z[bef[r]];
      r = bef[r];
    }
    dfs(str + 1, p1 + k, p2 + (k ^ 1));
    for (int i = 0; i <= N; i++) x[i] = tx[i], y[i] = ty[i], z[i] = tz[i];
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= N; j++)
      for (int k = 1; k <= N; k++) scanf("%d", &a[i][j][k]);
  }
  memset(z, -1, sizeof(z));
  dfs(1, 0, 0);
  printf("%d\n", res);
}
