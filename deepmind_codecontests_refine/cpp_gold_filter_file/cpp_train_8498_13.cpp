#include <bits/stdc++.h>
using namespace std;
template <class T>
bool cmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool cmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 1e4 + 10;
int n, l, r;
int a[N];
int b[N];
int p[N];
int dp[2][N];
int m;
int inside(int x) { return m - r <= x && x <= m - l; }
int main() {
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    m += a[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  sort(p, p + n, [](int i, int j) -> bool {
    return b[i] == b[j] ? a[i] > a[j] : b[i] < b[j];
  });
  memset(dp, -1, sizeof dp);
  dp[1][0] = 0;
  int sum = 0;
  for (int pi = 0; pi < n; pi++) {
    int i = p[pi];
    int *f = dp[pi & 1], *g = dp[1 - (pi & 1)];
    memset(dp[pi & 1], -1, sizeof dp[pi & 1]);
    for (int j = 0; j <= sum; j++) {
      if (g[j] == -1) {
        continue;
      }
      cmax(f[j + a[i]], g[j] + inside(j + a[i]) * b[i]);
      cmax(f[j], g[j]);
    }
    sum += a[i];
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    cmax(ans, dp[1 - (n & 1)][i]);
  }
  printf("%d\n", ans);
  return 0;
}
