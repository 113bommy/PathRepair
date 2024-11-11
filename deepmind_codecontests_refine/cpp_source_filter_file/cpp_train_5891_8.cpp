#include <bits/stdc++.h>
using namespace std;
long long x[41234], y[1234];
long long dist[1234][1234];
long long a[4123][1234];
long long b[1234][1234];
long long c[1234][1234];
double ddd[1234][1234];
int n;
inline int mx(int i, int j) { return max(j - i, n - j + i); }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      dist[i][j] =
          ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  double ans = 2e18;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      a[i][j] = y[j] - y[i], b[i][j] = x[i] - x[j];
      c[i][j] = -a[i][j] * x[i] - b[i][j] * y[i];
      ddd[i][j] = sqrt(double(a[i][j] * a[i][j] + b[i][j] * b[i][j]));
    }
  }
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (mx(i, j) > 10 && mx(i, k) > 10 && mx(j, k) > 10) continue;
        int ii, jj, kk;
        long long m1 = dist[i][j];
        long long m2 = dist[i][k];
        long long m3 = dist[j][k];
        if (m1 > m2)
          ii = k, jj = i, kk = j;
        else if (m2 > m3)
          ii = j, jj = i, kk = k;
        else
          ii = i, jj = j, kk = k;
        double d = abs(a[jj][kk] * x[ii] + b[jj][kk] * y[ii] + c[jj][kk]) /
                   ddd[jj][kk];
        ans = min(ans, d);
      }
    }
  }
  printf("%.10f", ans / 2);
  return 0;
}
