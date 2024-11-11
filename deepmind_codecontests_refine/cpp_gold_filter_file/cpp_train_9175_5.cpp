#include <bits/stdc++.h>
using namespace std;
const int N = 505;
double a[N][N], p[N], ans[N];
int n, m, S, T, x, y;
vector<int> v[N];
inline int id(int x, int y) { return (x - 1) * n + y; }
void gauss() {
  for (int i = 1; i <= n * n; i++) {
    int k = i;
    for (int j = i; j <= n * n; j++)
      if (fabs(a[j][i]) > fabs(a[k][i])) k = j;
    swap(a[i], a[k]);
    for (int j = i + 1; j <= n * n; j++) {
      double temp = a[j][i] / a[i][i];
      for (int k = i; k <= n * n + 1; k++) a[j][k] -= temp * a[i][k];
    }
  }
  for (int i = n * n; i; i--) {
    for (int j = n * n; j > i; j--) a[i][n * n + 1] += a[i][j] * ans[j];
    ans[i] = -a[i][n * n + 1] / a[i][i];
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &S, &T);
  while (m--) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int u = id(i, j);
      a[u][u] = 1;
      if (i ^ j) a[u][u] -= p[i] * p[j];
      for (int k : v[i])
        if (k != j) a[u][id(k, j)] -= p[j] * (1 - p[k]) / v[k].size();
      for (int k : v[j])
        if (k != i) a[u][id(i, k)] -= p[i] * (1 - p[k]) / v[k].size();
      for (int k : v[i])
        for (int l : v[j])
          if (k != l)
            a[u][id(k, l)] -=
                (1 - p[l]) * (1 - p[k]) / v[l].size() / v[k].size();
    }
  a[id(S, T)][n * n + 1] = -1;
  gauss();
  for (int i = 1; i <= n; i++) printf("%.10lf\n", ans[id(i, i)]);
}
