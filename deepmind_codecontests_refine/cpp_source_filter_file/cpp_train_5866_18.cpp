#include <bits/stdc++.h>
using namespace std;
double p[3333][333];
double e[333], tmp[3333];
double f[333][3333];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int first;
      scanf("%d", &first);
      p[i][j] = first / 1000.;
    }
  for (int i = 0; i < m; ++i) {
    double pro = 1.;
    for (int j = 0; j < n; ++j) {
      f[i][j + 1] = pro * p[j][i];
      e[i] += pro * p[j][i];
      pro *= (1. - p[j][i]);
    }
  }
  double ans = 0;
  for (int act = 0; act < n; ++act) {
    int pos = max_element(e, e + m) - e;
    ans += e[pos];
    for (int i = 0; i < n; ++i) tmp[i] = f[pos][i];
    double pro = 0.;
    e[pos] = 0;
    for (int i = 0; i < n; ++i) {
      pro += tmp[i];
      f[pos][i + 1] = pro * p[i][pos];
      e[pos] += pro * p[i][pos];
      pro *= (1. - tmp[i]);
    }
  }
  printf("%0.15lf\n", ans);
}
