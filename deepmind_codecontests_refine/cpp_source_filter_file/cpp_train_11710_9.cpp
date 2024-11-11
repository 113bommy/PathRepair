#include <bits/stdc++.h>
using namespace std;
int dp[200050 * 2], tree[200050 * 2];
int C[200050];
pair<int, int> A[200050];
int query(int v) {
  int ans = 0;
  while (v) {
    ans = max(ans, tree[v]);
    v -= v & -v;
  }
  return ans;
}
void update(int v, int first, int m) {
  while (v <= m) {
    tree[v] = max(tree[v], first);
    v += v & -v;
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &A[i].first, &A[i].second);
      C[i] = A[i].first + A[i].second;
    }
    sort(A, A + n);
    memset(dp, 0, sizeof dp);
    memset(tree, 0, sizeof tree);
    sort(C, C + n);
    int m = unique(C, C + n) - C;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int pos1 = upper_bound(C, C + m, A[i].first - A[i].second) - C;
      int pos2 = lower_bound(C, C + m, A[i].first + A[i].second) - C + 1;
      dp[pos2] = max(dp[pos2], 1);
      if (pos1) dp[pos2] = max(dp[pos2], query(pos1)) + 1;
      update(pos2, dp[pos2], m);
      ans = max(ans, dp[pos2]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
