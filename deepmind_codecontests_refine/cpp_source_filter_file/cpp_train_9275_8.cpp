#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000 + 9;
int a[maxN];
int dp[maxN];
int n;
int dfs(int x) {
  if (dp[x] != 0) return dp[x];
  for (int i = a[x]; i <= n; i += a[x]) {
    if (i == x) continue;
    if (a[i] > a[x] && dfs(i) == -1) return dp[x] = 1;
  }
  return dp[x] = -1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    dfs(i);
  }
  for (int i = 1; i <= n; i++)
    if (dp[i] > 0)
      printf("A");
    else
      printf("B");
  puts("");
  return 0;
}
