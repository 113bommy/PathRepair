#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5, maxa = 101;
int a[maxn];
double p[maxn][maxa];
int n;
int cura[maxn];
double ans;
void countC(double *ans, int x, int y) {
  double res = 1;
  ans[0] = res;
  for (int i = 0; i < y; i++) {
    res *= (x - i), res /= (i + 1);
    ans[i + 1] = res;
  }
}
double tmp[3][6];
void solve() {
  int u, v, k;
  scanf("%d%d%d", &u, &v, &k);
  --u, --v;
  assert(cura[u] >= k);
  ans -= p[u][0];
  for (int i = 0; i <= a[u] && i <= cura[u]; i++) {
    double curp = p[u][i];
    p[u][i] = 0;
    countC(tmp[0], i, k);
    countC(tmp[1], cura[u] - i, k);
    countC(tmp[2], cura[u], k);
    for (int j = 0; j <= k && j <= i; j++)
      p[u][i - j] += curp * tmp[0][j] * tmp[1][k - j] / tmp[2][k];
  }
  ans += p[u][0];
  cura[u] -= k;
  cura[v] += k;
}
int main() {
  while (scanf("%d", &n) >= 1) {
    ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      for (int j = 0; j < a[i]; j++) p[i][j] = 0;
      p[i][a[i]] = 1;
      ans += p[i][0];
      cura[i] = a[i];
    }
    int q;
    scanf("%d", &q);
    for (int iter = 0; iter < q; iter++) {
      solve();
      printf("%.18lf\n", ans);
    }
    break;
  }
  return 0;
}
