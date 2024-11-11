#include <bits/stdc++.h>
const int N = 100010;
using namespace std;
double dp[N][110];
int n, a[N], sum[N];
double getC(int a, int b) {
  if (a < b) return 0;
  double ret = 1;
  for (int i = 0; i < b; i++) ret *= (a - i);
  for (int i = 0; i < b; i++) ret /= (i + 1);
  return ret;
}
void work(int u, int v, int k) {
  double t[110];
  for (int i = 0; i <= a[u]; i++) t[i] = 0;
  for (int i = 0; i <= a[u]; i++) {
    if (sum[u] < i) break;
    for (int j = 0; j <= min(k, i); j++) {
      double p = getC(i, j) * getC(sum[u] - i, k - j) / getC(sum[u], k);
      t[i - j] += dp[u][i] * p;
    }
  }
  for (int i = 0; i <= a[u]; i++) dp[u][i] = t[i];
  sum[u]--;
  sum[v]++;
}
int main() {
  double ret = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i), sum[i] = a[i], dp[i][a[i]] = 1.0;
  int q;
  for (int i = 1; i <= n; i++) ret += (a[i] == 0);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v, k;
    scanf("%d%d%d", &u, &v, &k);
    ret -= dp[u][0];
    work(u, v, k);
    ret += dp[u][0];
    printf("%.15f\n", ret);
  }
  return 0;
}
