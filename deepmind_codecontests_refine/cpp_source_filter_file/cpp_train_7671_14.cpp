#include <bits/stdc++.h>
using namespace std;
const int N = 60;
const double inf = 1e14;
double dp[N][N];
int n;
struct nd {
  int v, w;
  double c;
} a[N];
bool cmp(nd x, nd y) { return x.v > y.v; }
bool cmp2(nd x, nd y) { return x.c < y.c; }
bool check(double mid) {
  int i, j, k, p;
  double sum;
  for (i = 1; i <= n; i++) a[i].c = (double)a[i].v - (double)a[i].w * mid;
  int top = 0;
  dp[0][0] = 0;
  for (i = 1; i <= n; i++) dp[0][i] = inf;
  for (i = 1; i <= n; i = j + 1) {
    j = i;
    while ((j < n) && (a[j + 1].v == a[i].v)) j++;
    sort(a + i, a + j + 1, cmp2);
    top++;
    for (k = 0; k <= n; k++) dp[top][k] = inf;
    for (k = 0; k < i; k++) {
      sum = 0;
      for (p = i; p <= j; p++) {
        if (k >= j - p + 1)
          dp[top][k + 2 * p - i - j - 1] =
              min(dp[top][k + 2 * p - i - j - 1], dp[top - 1][k] + sum);
        sum += a[p].c;
      }
      dp[top][k + j - i + 1] =
          min(dp[top][k + j - i + 1], dp[top - 1][k] + sum);
    }
  }
  for (i = 0; i <= n; i++)
    if (dp[top][i] <= 0) return 1;
  return 0;
}
int main() {
  int i, j, k;
  double l, r, mid;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i].v);
  for (i = 1; i <= n; i++) scanf("%d", &a[i].w);
  sort(a + 1, a + n + 1, cmp);
  l = 0;
  r = 100000000.0;
  while (r - l > 1e-6) {
    mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  long long ans = (long long)((l + r) * 500 + 0.5);
  printf("%I64d\n", ans);
  return 0;
}
