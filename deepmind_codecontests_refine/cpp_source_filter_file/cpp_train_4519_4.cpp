#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
long long mat[2048][2048], deg[2048], sum[2048];
double calc(long long n, long long k, long long d, long long s) {
  double ret = (double)s * (double)k / (double)d;
  int i;
  for (i = 0; i < n - d; ++i) {
    ret *= (double)(n - k - i) / (double)(n - i);
  }
  return ret;
}
long long solve(int n, int k) {
  int i, j;
  double ret = 0;
  memset(deg, 0, sizeof(deg));
  memset(sum, 0, sizeof(sum));
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (i != j && ~mat[i][j]) {
        ++deg[i];
        sum[j] += mat[i][j];
      }
    }
  }
  for (i = 0; i < n; ++i) {
    ret += calc(n, k, deg[i], sum[i]);
  }
  return (long long)(ret + 0.5 + eps);
}
int main() {
  int n, k, i, j, a;
  while (~scanf("%d %d", &n, &k)) {
    memset(mat, -1, sizeof(mat));
    for (i = 0; i < n; ++i) {
      for (j = i + 1; j < n; ++j) {
        scanf("%d", &a);
        if (~a) mat[i][j] = mat[j][i] = a;
      }
    }
    cout << solve(n, k) << endl;
  }
  return 0;
}
