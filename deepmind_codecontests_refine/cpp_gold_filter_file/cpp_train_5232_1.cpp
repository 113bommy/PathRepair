#include <bits/stdc++.h>
using namespace std;
int dp[3001];
int n;
struct node {
  int pos, val;
  bool operator<(const node& a) const { return val < a.val; }
} nodes[3001];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &nodes[i].val);
      nodes[i].pos = i;
      dp[i] = 1;
    }
    sort(nodes, nodes + n);
    for (int i = 1; i < n; i++) {
      if (nodes[i - 1].pos < nodes[i].pos) dp[i] = dp[i - 1] + 1;
      ans = max(ans, dp[i]);
    }
    if (n == 1)
      printf("0\n");
    else
      printf("%d\n", n - ans);
  }
  return 0;
}
