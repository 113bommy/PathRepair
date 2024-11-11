#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200 * 1000 + 5, LOG = 20;
int n, p[MAX_N], h[MAX_N], jay[MAX_N];
pair<int, int> dp[LOG + 2][2 * MAX_N];
vector<int> adj[MAX_N], seq;
struct node {
  bool ok;
  int st, en;
  node() { st = -1; }
} seg[4 * MAX_N], base;
void read_tree() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 1; i < n; i++) {
    int pr;
    cin >> pr;
    pr--;
    adj[pr].push_back(i);
  }
}
void dfs(int v, int cur_h = 0) {
  h[v] = cur_h;
  jay[v] = seq.size();
  seq.push_back(v);
  for (int u : adj[v]) {
    dfs(u, cur_h + 1);
    seq.push_back(v);
  }
}
int lca(int u, int v) {
  u = jay[u], v = jay[v];
  if (u > v) swap(u, v);
  int x = 31 - __builtin_clz(v - u + 1);
  return min(dp[x][u], dp[x][v - (1 << x) + 1]).second;
}
int dis(int u, int v) {
  int l = lca(u, v);
  return h[u] + h[v] - 2 * h[l];
}
node merge(node a, node b) {
  if (!~a.st) return b;
  if (!~b.st) return a;
  node res;
  res.ok = a.ok & b.ok;
  res.st = 0;
  if (!res.ok) return res;
  int v[] = {a.st, a.en, b.st, b.en};
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++) {
      res.ok = true;
      for (int k = 0; k < 4; k++)
        if (dis(v[i], v[k]) + dis(v[j], v[k]) != dis(v[i], v[j]))
          res.ok = false;
      if (res.ok && v[i] != v[j]) {
        res.st = v[i], res.en = v[j];
        return res;
      }
    }
  return res;
}
void modify(int k, int x, int id = 1, int l = 0, int r = n) {
  if (l == r - 1) {
    seg[id].ok = true;
    seg[id].st = seg[id].en = x;
    return;
  }
  int mid = (l + r) / 2;
  if (k < mid)
    modify(k, x, id * 2, l, mid);
  else
    modify(k, x, id * 2 + 1, mid, r);
  seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id = 1, int l = 0, int r = n) {
  if (l == r - 1) {
    node tmp = merge(base, seg[id]);
    if (tmp.ok) {
      base = tmp;
      return 1;
    }
    return 0;
  }
  int mid = (l + r) / 2;
  node tmp = merge(base, seg[id * 2]);
  if (tmp.ok) {
    base = tmp;
    return mid - l + get(id * 2 + 1, mid, r);
  }
  return get(id * 2, l, mid);
}
void prep() {
  dfs(0);
  for (int i = 0; i < (int)seq.size(); i++) {
    int v = seq[i];
    dp[0][i] = {h[v], v};
  }
  for (int i = 1; i < LOG; i++)
    for (int v = 0; v < (int)seq.size(); v++) {
      if (v + (1 << i - 1) < (int)seq.size())
        dp[i][v] = min(dp[i - 1][v], dp[i - 1][v + (1 << i - 1)]);
      else
        dp[i][v] = dp[i - 1][v];
    }
  for (int i = 0; i < n; i++) modify(p[i], i);
}
void read_queries() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      modify(p[x], y);
      modify(p[y], x);
      swap(p[x], p[y]);
    } else {
      base.st = -1;
      cout << get() << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  read_tree();
  prep();
  read_queries();
}
