#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, k, ara[N], to[N];
vector<int> g[N];
int tree[4 * N], lazy[4 * N];
void upd(int node, int val) {
  lazy[node] += val;
  tree[node] += val;
}
void push(int node) {
  if (lazy[node] != 0) {
    upd(2 * node, lazy[node]);
    upd(2 * node + 1, lazy[node]);
    lazy[node] = 0;
  }
}
void update(int node, int L, int R, int pos, int val) {
  if (pos < L or pos > R) return;
  if (L == R) {
    tree[node] = val;
    return;
  }
  push(node);
  int mid = (L + R) >> 1;
  update(2 * node, L, mid, pos, val);
  update(2 * node + 1, mid + 1, R, pos, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
void updateRange(int node, int L, int R, int l, int r, int val) {
  if (R < l or r < L) return;
  if (L >= l and R <= r) {
    upd(node, val);
    return;
  }
  int mid = (L + R) >> 1;
  push(node);
  updateRange(2 * node, L, mid, l, r, val);
  updateRange(2 * node + 1, mid + 1, R, l, r, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int query(int node, int L, int R, int l, int r) {
  if (R < l or r < L) return 0;
  if (L >= l and R <= r) {
    return tree[node];
  }
  push(node);
  int mid = (L + R) >> 1;
  int x = query(2 * node, L, mid, l, r);
  int y = query(2 * node + 1, mid + 1, R, l, r);
  return max(x, y);
}
int st[N], ed[N];
void dfs(int node, int pre) {
  static int timer = 0;
  st[node] = ++timer;
  for (int i : g[node]) {
    if (i == pre) continue;
    dfs(i, node);
  }
  ed[node] = timer;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> ara[i];
  ara[n + 1] = 1e9;
  stack<int> stk;
  stk.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() and ara[stk.top()] <= ara[i]) {
      stk.pop();
    }
    to[i] = stk.top();
    stk.push(i);
    g[to[i]].push_back(i);
  }
  dfs(n + 1, 0);
  for (int i = 1; i < k; i++) {
    updateRange(1, 1, n + 1, st[i], ed[i], 1);
  }
  for (int i = k; i <= n; i++) {
    updateRange(1, 1, n + 1, st[i], ed[i], 1);
    int ans = query(1, 1, n + 1, 1, n + 1);
    cout << ans << " ";
    update(1, 1, n + 1, st[i - k + 1], -1e9);
  }
}
