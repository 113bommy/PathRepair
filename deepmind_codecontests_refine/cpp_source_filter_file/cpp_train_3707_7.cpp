#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
long long pw(long long b, long long p) {
  if (!p) return 1;
  long long sq = pw(b, p / 2) % 1000000007;
  sq = (sq * sq) % 1000000007;
  if (p % 2) sq = (sq * b) % 1000000007;
  return sq;
}
const int N = 35005, LG = 18;
long long dp[N][55];
int n, k;
int a[N];
int nxt[N], t[N];
int segTree[N * 4];
int lazy[N * 4];
void apply(int root) {
  if (!lazy[root]) return;
  lazy[(root << 1)] += lazy[root];
  lazy[((root << 1) | 1)] += lazy[root];
  segTree[(root << 1)] += lazy[root];
  segTree[((root << 1) | 1)] += lazy[root];
  lazy[root] = 0;
}
void update(int l, int r, int val, int st = 0, int end = n + 1, int root = 1) {
  if (r <= st || l >= end) return;
  if (st >= l && end <= r) {
    segTree[root] += val;
    lazy[root] += val;
    return;
  }
  apply(root);
  update(l, r, val, st, ((end + st) >> 1), (root << 1));
  update(l, r, val, ((end + st) >> 1) + 1, end, ((root << 1) | 1));
  segTree[root] = max(segTree[(root << 1)], segTree[((root << 1) | 1)]);
}
int query(int l, int r, int st = 0, int end = n + 1, int root = 1) {
  if (r <= st || l >= end) return -1e8;
  if (st >= l && end <= r) {
    return segTree[root];
  }
  apply(root);
  return max(query(l, r, st, ((end + st) >> 1), (root << 1)),
             query(l, r, ((end + st) >> 1) + 1, end, ((root << 1) | 1)));
}
void init() {
  memset(segTree, 0, sizeof segTree);
  memset(lazy, 0, sizeof lazy);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) t[i] = n;
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = t[a[i]];
    t[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    dp[i][k] = -1e8;
  }
  for (int i = 0; i < k; i++) {
    dp[n][i] = -1e8;
  }
  dp[n][k] = 0;
  for (int K = k - 1; K >= 0; K--) {
    init();
    for (int idx = 0; idx <= n; idx++) {
      update(idx, idx + 1, dp[idx][K + 1]);
    }
    for (int idx = n - 1; idx >= 0; idx--) {
      update(idx + 1, nxt[idx] + 1, 1);
      dp[idx][K] = query(idx + 1, n + 1);
    }
  }
  cout << dp[0][0];
  return 0;
}
