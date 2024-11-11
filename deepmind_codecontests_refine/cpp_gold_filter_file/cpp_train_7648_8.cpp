#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN], p[MAXN];
double d[MAXN];
double mean[MAXN];
int main() {
  int n, T;
  double c;
  while (scanf("%d %d %lf", &n, &T, &c) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", &p[i]);
    d[0] = 0.;
    for (int i = 0; i < n; ++i) d[i + 1] = d[i] + a[i];
    mean[0] = 0.;
    for (int i = 0; i < n; ++i) mean[i + 1] = (mean[i] + a[i]) / c;
    for (int i = 0; i < m; ++i) {
      double real = (d[p[i]] - d[p[i] - T]) / T, approx = mean[p[i]] / T;
      printf("%.6lf %.6lf %.6lf\n", real, approx, fabs(real - approx) / real);
    }
  }
}
