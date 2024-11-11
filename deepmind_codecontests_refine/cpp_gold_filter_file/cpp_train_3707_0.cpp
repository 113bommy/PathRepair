#include <bits/stdc++.h>
using namespace std;
const int maxn = 35005;
struct Node {
  int l, r;
  int Max;
  int lazy;
} node[maxn << 2];
int dp[maxn];
int n, k;
int a[maxn];
int pre[maxn];
void build(int l, int r, int root) {
  node[root].l = l, node[root].r = r;
  node[root].lazy = 0;
  if (l == r) {
    node[root].Max = dp[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, root << 1);
  build(mid + 1, r, root << 1 | 1);
  node[root].Max = max(node[root << 1].Max, node[root << 1 | 1].Max);
}
void pushdown(int root) {
  node[root << 1 | 1].lazy += node[root].lazy;
  node[root << 1].lazy += node[root].lazy;
  node[root << 1].Max += node[root].lazy;
  node[root << 1 | 1].Max += node[root].lazy;
  node[root].lazy = false;
}
void update(int l, int r, int root) {
  if (node[root].l >= l && node[root].r <= r) {
    node[root].lazy += 1;
    node[root].Max += 1;
    return;
  }
  if (node[root].lazy) pushdown(root);
  int mid = (node[root].l + node[root].r) >> 1;
  if (l <= mid) update(l, r, root << 1);
  if (r > mid) update(l, r, root << 1 | 1);
  node[root].Max = max(node[root << 1].Max, node[root << 1 | 1].Max);
}
int query(int l, int r, int root) {
  if (node[root].l >= l && node[root].r <= r) return node[root].Max;
  if (node[root].lazy) pushdown(root);
  int temp1 = 0, temp2 = 0;
  int mid = (node[root].l + node[root].r) >> 1;
  if (l <= mid) temp1 = query(l, r, root << 1);
  if (r > mid) temp2 = query(l, r, root << 1 | 1);
  node[root].Max = max(node[root << 1].Max, node[root << 1 | 1].Max);
  if (temp1 > temp2) return temp1;
  return temp2;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= k; i++) {
    build(0, n, 1);
    for (int j = 0; j < maxn; j++) {
      pre[j] = 0;
    }
    for (int j = 1; j <= n; j++) {
      update(pre[a[j]], j - 1, 1);
      pre[a[j]] = j;
      dp[j] = query(0, j - 1, 1);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
