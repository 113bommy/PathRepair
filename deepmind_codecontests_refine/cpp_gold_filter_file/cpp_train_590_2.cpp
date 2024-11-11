#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-8;
const int maxn = 205;
int x[maxn], y[maxn];
struct Matrix {
  double a[maxn][maxn];
  void init() {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < maxn; ++i) {
      a[i][i] = 1;
    }
  }
} P[14];
Matrix mul(Matrix a, Matrix b) {
  Matrix ans;
  memset(ans.a, 0, sizeof(ans.a));
  for (int i = 0; i < maxn; ++i) {
    for (int k = 0; k < maxn; ++k) {
      if (a.a[i][k] != 0)
        for (int j = 0; j < maxn; ++j) {
          ans.a[i][j] += a.a[i][k] * b.a[k][j];
        }
    }
  }
  return ans;
}
vector<pair<double, int> > v;
double d[maxn], e[maxn];
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d %d", x + i, y + i);
  for (int i = 1; i <= n; ++i) {
    v.clear();
    for (int j = 1; j <= n; ++j) {
      if (j == i) continue;
      double theta = atan2(x[j] - x[i], y[j] - y[i]);
      while (theta < 0) theta += pi;
      while (theta >= pi) theta -= pi;
      v.push_back(pair<double, int>(theta, j));
    }
    sort(v.begin(), v.end());
    int line = 0;
    for (int j = 0, k; j < n - 1;) {
      for (k = j; k < n - 1 && fabs(v[k].first - v[j].first) < eps; ++k)
        ;
      j = k, line++;
    }
    for (int j = 0, k; j < n - 1;) {
      for (k = j; k < n - 1 && fabs(v[k].first - v[j].first) < eps; ++k)
        ;
      for (int p = j; p < k; ++p)
        P[0].a[v[p].second][i] += 1.0 / line / (k - j + 1);
      P[0].a[i][i] += 1.0 / line / (k - j + 1);
      j = k;
    }
  }
  for (int i = 1; i < 14; ++i) P[i] = mul(P[i - 1], P[i - 1]);
  scanf("%d", &q);
  while (q--) {
    int t, m;
    scanf("%d %d", &t, &m);
    m--;
    memset(d, 0, sizeof(d));
    d[t] = 1;
    for (int i = 0; i < 14; ++i) {
      if (m & (1 << i)) {
        memset(e, 0, sizeof(e));
        for (int j = 1; j <= n; ++j)
          for (int k = 1; k <= n; ++k) e[j] += P[i].a[k][j] * d[k];
        memcpy(d, e, sizeof(d));
      }
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
      v.clear();
      for (int j = 1; j <= n; ++j) {
        if (j == i) continue;
        double theta = atan2(x[j] - x[i], y[j] - y[i]);
        while (theta < 0) theta += pi;
        while (theta >= pi) theta -= pi;
        v.push_back(pair<double, int>(theta, j));
      }
      sort(v.begin(), v.end());
      for (int j = 0, k; j < n - 1;) {
        double tmp = 0;
        for (k = j; k < n - 1 && fabs(v[k].first - v[j].first) < eps; ++k)
          ;
        for (int p = j; p < k; ++p) tmp += d[v[p].second] / (k - j + 1);
        tmp += d[i] / (k - j + 1);
        ans = max(ans, tmp);
        j = k;
      }
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
