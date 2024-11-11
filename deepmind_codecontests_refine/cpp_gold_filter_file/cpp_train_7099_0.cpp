#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int a[maxn];
int dp[maxn];
void dfs(int x, int y) {
  if (x == y) {
    dp[x]++;
    return;
  }
  dp[y]++;
  dfs(a[x], y);
  return;
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
      dfs(a[i], i);
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", dp[i]);
    }
    printf("\n");
  }
  return 0;
}
