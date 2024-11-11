#include <bits/stdc++.h>
using namespace std;
long long dp[55][20005];
long long sum[55][20005];
int n, m, k;
long long getsum(int i, int l, int r) {
  if (l > r) return 0;
  l = max(1, l);
  l = min(m, l);
  r = min(m, r);
  r = max(1, r);
  return sum[i][r] - sum[i][l - 1];
}
long long tree[55][4 * 20005];
void makeTree(int node, int left, int right, int x) {
  if (left == right) {
    tree[x][node] = dp[x][left];
    return;
  }
  int mid = (left + right) >> 1;
  int l = node << 1;
  int r = l | 1;
  makeTree(l, left, mid, x);
  makeTree(r, mid + 1, right, x);
  tree[x][node] = max(tree[x][l], tree[x][r]);
  return;
}
long long query(int node, int left, int right, int a, int b, int x) {
  if (left > b || right < a) return 0;
  if (left >= a && right <= b) return tree[x][node];
  int mid = (left + right) >> 1;
  int l = node << 1;
  int r = l | 1;
  return max(query(l, left, mid, a, b, x), query(r, mid + 1, right, a, b, x));
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%lld", &sum[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) sum[i][j] += sum[i][j - 1];
  }
  for (int i = 1; i <= m; i++) {
    dp[n][i] = getsum(n, i, i + k - 1);
  }
  for (int i = n - 1; i > 0; i--) {
    makeTree(1, 1, m, i + 1);
    for (int j = 1; j <= m; j++) {
      long long ss = getsum(i, j, j + k - 1) + getsum(i + 1, j, j + k - 1);
      dp[i][j] = query(1, 1, m, j + k, m, i + 1) + ss;
      dp[i][j] = max(dp[i][j], query(1, 1, m, 1, j - k, i + 1) + ss);
      for (int x = max(1, j - k + 1); x <= j; x++) {
        dp[i][j] =
            max(dp[i][j], dp[i + 1][x] + ss - getsum(i + 1, j, x + k - 1));
      }
      for (int x = j + 1; x <= min(m, j + k - 1); x++) {
        dp[i][j] =
            max(dp[i][j], dp[i + 1][x] + ss - getsum(i + 1, x, j + k - 1));
      }
    }
  }
  makeTree(1, 1, n, 1);
  printf("%lld\n", tree[1][1]);
  ;
  return 0;
}
