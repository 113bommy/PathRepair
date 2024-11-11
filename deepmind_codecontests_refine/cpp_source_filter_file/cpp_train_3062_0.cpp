#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int f[MAXN], g[MAXN], o[MAXN];
int n, m;
vector<int> p[110000];
int q[110000];
int main() {
  scanf("%d%d", &n, &m);
  int res = 0;
  for (int i = (1); i <= (int)m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x <= n - 500)
      res += 3;
    else
      p[y].push_back(n - x + 1);
  }
  for (int i = (1); i <= (int)n; i++) sort(p[i].begin(), p[i].end());
  memset(o, 63, sizeof o);
  o[0] = 0;
  for (int i = (1); i <= (int)n; i++) {
    int up = min(n - i + 1, 500);
    int N = p[i].size();
    for (int j = (1); j <= (int)N; j++) q[j] = p[i][j - 1];
    int v = 0;
    f[0] = N * 3 + o[0];
    f[0] = min(f[0], N * 3 + o[1]);
    for (int j = (1); j <= (int)up; j++) {
      while (v < N && q[v + 1] <= j) v++;
      f[j] = g[j] + (j * (j + 1) / 2) + 2 + (N - v) * 3;
      f[j] = min(f[j], o[j + 1] + (N - v) * 3);
    }
    for (int j = (0); j <= (int)up; j++) o[j] = f[j], f[j] = o[504];
    g[0] = o[0];
    for (int j = (1); j <= (int)up; j++) g[j] = min(g[j - 1], o[j]);
  }
  printf("%d\n", g[1] + res);
  return 0;
}
