#include <bits/stdc++.h>
using namespace std;
int dp[20][100003];
vector<int> ind[100003];
int depth[100003];
vector<int> g[100003];
int n, m, q;
struct node {
  int sum;
  node* left;
  node* right;
  node(int s = 0, node* l = NULL, node* r = NULL) {
    sum = s;
    left = l;
    right = r;
  }
  node* insert(int l, int r, int val);
};
node* dummy;
node* root[100003];
node* node::insert(int l, int r, int val) {
  if (l == r) return new node(sum + 1, dummy, dummy);
  int mid = (l + r) / 2;
  if (val <= mid) return new node(sum + 1, left->insert(l, mid, val), right);
  return new node(sum + 1, left, right->insert(mid + 1, r, val));
}
void dfs(int u, int par) {
  dp[0][u] = par;
  depth[u] = depth[par] + 1;
  root[u] = root[par];
  for (int x : ind[u]) root[u] = root[u]->insert(1, m, x);
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
int LCA(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int diff = depth[u] - depth[v];
  for (int i = 19; i >= 0; i--)
    if ((diff >> i) & 1 && dp[i][u] != -1) u = dp[i][u];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (dp[i][u] != dp[i][v] && dp[i][u] != -1) {
      u = dp[i][u];
      v = dp[i][v];
    }
  }
  return dp[0][u];
}
void print(int l, int r, node* a, node* b, node* c, node* d) {
  int cnt = a->sum + b->sum - c->sum - d->sum;
  if (!cnt) return;
  if (l == r) {
    cout << l << " ";
    return;
  }
  int mid = (l + r) / 2;
  print(l, mid, a->left, b->left, c->left, d->left);
  print(mid + 1, r, a->right, b->right, c->right, d->right);
}
void solve(int u, int v, int k) {
  node* a = root[u];
  node* b = root[v];
  node* c = root[LCA(u, v)];
  node* d = root[dp[0][LCA(u, v)]];
  k = min(k, a->sum + b->sum - c->sum - d->sum);
  int l = 1;
  int r = m;
  cout << k << " ";
  while (l < r) {
    int cnt = a->left->sum + b->left->sum - c->left->sum - d->left->sum;
    int mid = (l + r) >> 1;
    if (cnt >= k) {
      r = mid;
      a = a->left;
      b = b->left;
      c = c->left;
      d = d->left;
    } else {
      print(l, mid, a->left, b->left, c->left, d->left);
      l = mid + 1;
      a = a->right;
      b = b->right;
      c = c->right;
      d = d->right;
      k -= cnt;
    }
  }
  if (k) {
    print(l, l, a, b, c, d);
  }
  printf("\n");
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int u;
    cin >> u;
    ind[u].push_back(i);
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 1; j <= n; j++) dp[i][j] = -1;
  }
  dummy = new node();
  dummy->left = dummy;
  dummy->right = dummy;
  root[0] = dummy;
  depth[0] = 0;
  dfs(1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++)
      if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][dp[i - 1][j]];
  }
  while (q--) {
    int u, v, a;
    cin >> u >> v >> a;
    solve(u, v, a);
  }
  return 0;
}
