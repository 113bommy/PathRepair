#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e9;
int n, m, r;
long long p[30], v, ans, X, Y, Z;
int w[30], ww[30], q[100000], g[100000][30], u[30], P[100000];
bool cmp(int x, int y) { return q[x] < q[y]; }
int gen(int i, int x) {
  if (i == n) {
    for (int j = 0; j < n; j++) g[r][j] = u[j];
    P[r] = r;
    q[r++] = x;
    return 0;
  }
  for (int j = 0; j <= w[i]; j++) {
    u[i] = j;
    gen(i + 1, x);
    if (j < w[i] && x < maxn / p[i])
      x *= p[i];
    else
      break;
    if (x > v / x / x) break;
  }
  return 0;
}
int gen2(int i, int x, int y, long long z) {
  if (i == n) {
    if (x >= y) {
      z /= x;
      long long tmp = (long long)x * y + y * z + z * x;
      if (tmp < ans) {
        ans = tmp;
        X = x;
        Y = y;
        Z = z;
      }
    }
    return 0;
  }
  for (int j = 0; j <= ww[i]; j++) {
    gen2(i + 1, x, y, z);
    if (j < ww[i] && x <= maxn / p[i])
      x *= p[i];
    else
      break;
    if (x > z / x) break;
  }
  return 0;
}
int main() {
  int t, i, j, k, o;
  cin >> t;
  for (o = 1; o <= t; o++) {
    cin >> n;
    v = 1;
    for (i = 0; i < n; i++) {
      scanf("%lld%d", &p[i], &w[i]);
      for (j = 1; j <= w[i]; j++) v *= p[i];
    }
    ans = 4e18;
    r = 0;
    gen(0, 1);
    sort(P, P + r, cmp);
    for (j = r - 1; j >= 0; j--) {
      int i = P[j];
      double b = sqrt(v / q[i] + 0.0);
      if (2 * q[i] * b + b * b >= ans) continue;
      for (k = 0; k < n; k++) ww[k] = w[k] - g[i][k];
      gen2(0, 1, q[i], v / q[i]);
    }
    cout << ans * 2 << " " << X << " " << Y << " " << Z << endl;
  }
  return 0;
}
