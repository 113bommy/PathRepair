#include <bits/stdc++.h>
long long dp[50 + 1], ff[50];
void init() {
  int n, j, b;
  long long x;
  double x_;
  x = 1;
  for (b = 0; b < 50; b++) {
    ff[b] = x;
    x_ = (double)x * (b + 1);
    x = x_ > ((long long)2e18) ? ((long long)2e18) : x * (b + 1);
  }
  dp[0] = dp[1] = 1;
  for (n = 2; n <= 50; n++) {
    long long y = dp[n - 1];
    for (j = 1; j < n; j++) {
      b = j + 1;
      x_ = (double)ff[b - 2] * dp[n - b];
      x = x_ > ((long long)2e18) ? ((long long)2e18) : ff[b - 2] * dp[n - b];
      if ((y += x) > ((long long)2e18)) {
        y = ((long long)2e18);
        break;
      }
    }
    dp[n] = y;
  }
}
int aa[50];
char used[50], visited[50];
long long count_(int n, int l, int r) {
  int i, k;
  double x_;
  memset(visited + l, 0, (r - l) * sizeof *visited);
  for (i = l; i < r; i++) {
    int j;
    if (visited[i]) continue;
    for (j = i; j < r; j = aa[j]) {
      if (visited[j]) {
        if (j == i) return 0;
        break;
      }
      visited[j] = 1;
    }
    if (j > aa[l]) return 0;
  }
  k = aa[l];
  x_ = (double)ff[k - r] * dp[n - k - 1];
  return x_ > ((long long)2e18) ? ((long long)2e18) : ff[k - r] * dp[n - k - 1];
}
long long count(int n, int p) {
  int i;
  for (i = 0; i < p; i++) {
    if (aa[i] >= p) return count_(n, i, p);
    i = aa[i];
  }
  return dp[n - p];
}
void solve(int n, long long k) {
  int i, j;
  memset(aa, 0, n * sizeof *aa);
  memset(used, 0, n * sizeof *used);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (!used[j]) {
        long long cnt;
        used[j] = 1;
        aa[i] = j;
        cnt = count(n, i + 1);
        if (cnt >= k) break;
        k -= cnt;
        used[j] = 0;
      }
}
int main() {
  int t;
  init();
  scanf("%d", &t);
  while (t--) {
    int n, i;
    long long k;
    scanf("%d%lld", &n, &k);
    if (dp[n] < k)
      printf("-1\n");
    else {
      solve(n, k);
      for (i = 0; i < n; i++) printf("%d ", aa[i] + 1);
      printf("\n");
    }
  }
  return 0;
}
