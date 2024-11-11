#include <bits/stdc++.h>
using namespace std;
void Build(vector<int> &dp, int *tree, int node, int ts, int te) {
  if (ts == te) {
    if (ts != 0)
      tree[node] = dp[ts - 1];
    else
      tree[node] = 0;
    return;
  }
  int tm = (ts + te) >> 1;
  Build(dp, tree, 2 * node + 1, ts, tm);
  Build(dp, tree, 2 * node + 2, tm + 1, te);
  tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}
void Update(int *tree, int *lazy, int node, int ts, int te, int rs, int re) {
  if (lazy[node] != 0) {
    tree[node] += (lazy[node]);
    if (ts != te) {
      lazy[2 * node + 1] += lazy[node];
      lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
  }
  int tm = (ts + te) >> 1;
  if (ts > te || ts > re || te < rs) return;
  if (ts >= rs && te <= re) {
    tree[node]++;
    if (ts != te) {
      lazy[2 * node + 1]++;
      lazy[2 * node + 2]++;
    }
    return;
  }
  Update(tree, lazy, 2 * node + 1, ts, tm, rs, re);
  Update(tree, lazy, 2 * node + 2, tm + 1, te, rs, re);
  tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}
int RangeMax(int *tree, int *lazy, int node, int ts, int te, int rs, int re) {
  if (lazy[node]) {
    tree[node] += (lazy[node]);
    if (ts != te) {
      lazy[2 * node + 1] += lazy[node];
      lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
  }
  int tm = (ts + te) >> 1;
  if (ts > te || ts > re || te < rs) return 0;
  if (ts >= rs && te <= re) {
    return tree[node];
  }
  return max(RangeMax(tree, lazy, 2 * node + 1, ts, tm, rs, re),
             RangeMax(tree, lazy, 2 * node + 2, tm + 1, te, rs, re));
}
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  vector<int> dp(n, 0);
  int prev[n], last[n];
  memset(last, -1, sizeof(prev));
  for (int i = 0; i < n; ++i) {
    prev[i] = last[arr[i] - 1];
    last[arr[i] - 1] = i;
  }
  int tree[4 * n], lazy[4 * n];
  for (int i = 0; i < k; ++i) {
    memset(lazy, 0, sizeof(lazy));
    memset(tree, 0, sizeof(lazy));
    if (i != 0) Build(dp, tree, i - 1, 0, n - 1);
    for (int j = i; j < n; ++j) {
      Update(tree, lazy, 0, 0, n - 1, prev[j] + 1, j);
      dp[j] = RangeMax(tree, lazy, 0, 0, n - 1, 0, j);
    }
  }
  cout << dp[n - 1] << "\n";
}
