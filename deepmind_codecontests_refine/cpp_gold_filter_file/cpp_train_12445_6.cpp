#include <bits/stdc++.h>
using namespace std;
bool dp[501][501][501];
bool was[501][501][501];
int w[502];
bool foo(int a, int b, int n) {
  if (was[a][b][n]) return dp[a][b][n];
  was[a][b][n] = 1;
  if (a == 0 && b == 0) return dp[a][b][n] = true;
  if (n == 0) return false;
  if (w[n] <= a && foo(a - w[n], b, n - 1)) return dp[a][b][n] = true;
  if (w[n] <= b && foo(a, b - w[n], n - 1)) return dp[a][b][n] = true;
  return dp[a][b][n] = foo(a, b, n - 1);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", w + i);
  vector<int> ans;
  for (int x = 0; x <= k; x++)
    if (foo(x, k - x, n)) ans.push_back(x);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
