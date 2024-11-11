#include <bits/stdc++.h>
using namespace std;
int read() {
  int cnt = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch))
    cnt = (cnt << 3) + (cnt << 1) + (ch - '0'), ch = getchar();
  return cnt * f;
}
const int inf = 0x3fffffff;
const int maxn = 2e5 + 50;
vector<int> q[maxn];
vector<int> graph[maxn];
int cnt, dep[maxn], in[maxn], out[maxn];
int n, m, root, rt[maxn], nume, mx;
int lasta;
int a[maxn];
struct node {
  int ls, rs, val;
} tree[maxn * 30];
void build(int& x, int l, int r) {
  x = ++cnt;
  tree[x].val = inf;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(tree[x].ls, l, mid);
  build(tree[x].rs, mid + 1, r);
}
void insert(int& x, int last, int l, int r, int pos, int val) {
  x = ++cnt;
  tree[x] = tree[last];
  tree[x].val = min(tree[x].val, val);
  if (l == r) return;
  int mid = (l + r) / 2;
  if (pos <= mid)
    insert(tree[x].ls, tree[last].ls, l, mid, pos, val);
  else
    insert(tree[x].rs, tree[last].rs, mid + 1, r, pos, val);
}
int query(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tree[x].val;
  int mid = (l + r) / 2;
  int ans = inf;
  if (L <= mid) ans = min(ans, query(tree[x].ls, l, mid, L, R));
  if (R > mid) ans = min(ans, query(tree[x].rs, mid + 1, r, L, R));
  return ans;
}
void dfs(int u, int fa) {
  in[u] = ++nume;
  q[dep[u]].push_back(u);
  mx = max(mx, dep[u]);
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
  out[u] = nume;
}
int main() {
  n = read();
  root = read();
  build(rt[0], 1, n);
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) {
    int u, v;
    u = read(), v = read();
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dep[root] = 1;
  dfs(root, 0);
  for (int i = 1; i <= mx; i++) {
    rt[i] = rt[i - 1];
    for (int j = 0; j < q[i].size(); j++) {
      insert(rt[i], rt[i], 1, n, in[q[i][j]], a[q[i][j]]);
    }
  }
  m = read();
  while (m--) {
    int u = (read() + lasta) % n + 1;
    int k = (read() + lasta) % n;
    lasta = query(rt[min(mx, dep[u] + k)], 1, n, in[u], out[u]);
    cout << lasta << endl;
  }
  return 0;
}
