#include <bits/stdc++.h>
using namespace std;
int a[100500], b[100500];
double p[100500][105];
inline double C(const int &n, const int &m) {
  double res = 1.0;
  for (int i = 0; i < m; i++) res *= n - i;
  for (int i = 1; i <= m; i++) res /= i;
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    p[i][a[i]] = 1.0;
    ans += p[i][0];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x, --y;
    ans -= p[x][0];
    for (int j = 0; j <= a[x]; j++) {
      double cur = p[x][j];
      p[x][j] = 0.0;
      for (int k = 0; k <= j && k <= z; k++)
        p[x][j - k] += cur * C(j, k) * C(b[x] - j, z - k) / C(b[x], z);
    }
    ans += p[x][0];
    b[x] -= z;
    b[y] += z;
    printf("%.15lf\n", ans);
  }
  return 0;
}
