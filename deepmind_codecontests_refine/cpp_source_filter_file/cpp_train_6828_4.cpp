#include <bits/stdc++.h>
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f;
const int mod = 20000311;
const int maxn = 1e5 + 5;
const int N = 1005;
using namespace std;
int a[maxn] = {0};
int dp[maxn][305] = {0};
int n;
int dfs(int p, int k) {
  if (p > n) return 0;
  if (dp[p][k] != -1) return dp[p][k];
  int num = p + a[p] + k;
  return dp[p][k] = dfs(num, k) + 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int j = 1; j <= 300; j++) {
    for (int i = n; i >= 1; i--) {
      int num = i + a[j] + j;
      if (num > n)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[num][j] + 1;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, k;
    scanf("%d %d", &p, &k);
    if (k >= 300) {
      int res = 0;
      while (p <= n) {
        p = a[p] + k + p;
        res++;
      }
      cout << res << "\n";
    } else
      cout << dp[p][k] << "\n";
  }
  return 0;
}
