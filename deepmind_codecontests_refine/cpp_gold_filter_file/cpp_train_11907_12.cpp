#include <bits/stdc++.h>
using namespace std;
double prob[1010][1010];
int p[1010];
int a[1010], b[1010];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", p + i), --p[i];
  for (int i = 0; i < m; ++i) scanf("%d%d", a + i, b + i), --a[i], --b[i];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) prob[i][j] = 1;
  }
  for (int k = m - 1; ~k; --k) {
    int u = a[k], v = b[k];
    for (int i = 0; i < n; ++i) {
      if (i != u && i != v) {
        prob[i][v] = prob[i][u] = (prob[i][u] + prob[i][v]) * 0.5;
        prob[v][i] = 1 - prob[i][v];
        prob[u][i] = 1 - prob[i][u];
      }
    }
    prob[u][v] = prob[v][u] = (prob[u][v] + prob[v][u]) * 0.5;
  }
  double res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (p[i] > p[j]) res += prob[i][j];
    }
  }
  printf("%.7lf\n", res);
}
