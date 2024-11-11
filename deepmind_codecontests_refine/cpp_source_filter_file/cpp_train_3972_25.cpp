#include <bits/stdc++.h>
using namespace std;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9 + 7;
const int maxn = (int)3e5;
const int LOGN = 20;
int par[2 + maxn << 1], szx[2 + maxn << 1], szy[2 + maxn << 1];
int find(int u) { return par[u] == u ? u : find(par[u]); }
long long ans;
struct upd {
  int u, v, sx, sy;
  upd(int _u, int _v, int _sx, int _sy) { u = _u, v = _v, sx = _sx, sy = _sy; }
};
stack<upd> stk;
void rollback() {
  upd cur = stk.top();
  stk.pop();
  ans -= 1ll * szx[cur.u] * szy[cur.u];
  szx[cur.u] = cur.sx;
  szy[cur.u] = cur.sy;
  par[cur.v] = cur.v;
  ans += 1ll * szx[cur.u] * szy[cur.u];
  ans += 1ll * szx[cur.v] * szy[cur.v];
}
void make_union(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  if (szx[u] + szy[u] < szx[v] + szy[v]) swap(u, v);
  ans -= 1ll * szx[v] * szy[v];
  ans -= 1ll * szx[u] * szy[u];
  stk.push(upd(u, v, szx[u], szy[u]));
  szx[u] += szx[v];
  szy[u] += szy[v];
  ans += 1ll * szx[u] * szy[u];
  par[v] = u;
}
int l, r, val;
vector<int> seg[2 + maxn << 3];
void insert(int node, int b, int e) {
  if (e < l || b > r) return;
  if (l <= b && e <= r) {
    seg[node].push_back(val);
    return;
  }
  int mid = (b + e) >> 1, lft = node * 2, rgt = lft + 1;
  insert(lft, b, mid);
  insert(rgt, mid + 1, e);
}
int res[2 + maxn];
pair<int, int> E[2 + maxn];
void dfs(int node, int b, int e) {
  int stk_sz = stk.size();
  for (int i : seg[node]) make_union(E[i].first, E[i].second);
  if (b == e) {
    res[b] = ans;
  }
  if (b != e) {
    int mid = (b + e) >> 1, lft = node << 1, rgt = lft | 1;
    dfs(lft, b, mid);
    dfs(rgt, mid + 1, e);
  }
  while (stk.size() > stk_sz) rollback();
}
map<pair<int, int>, int> m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x, y;
  cin >> n;
  for (int i = 1; i <= (n); i++) {
    cin >> E[i].first >> E[i].second;
    E[i].second += maxn;
    if (m.find(E[i]) == m.end()) {
      m[E[i]] = i;
    } else {
      l = m[E[i]];
      r = i - 1;
      val = l;
      insert(1, 1, n);
      m.erase(E[i]);
    }
  }
  for (int i = 1; i <= (maxn); i++) par[i] = i, szx[i] = 1;
  for (int i = (maxn + 1); i <= (maxn << 1); i++) par[i] = i, szy[i] = 1;
  for (auto e : m) {
    l = e.second;
    r = n;
    val = l;
    insert(1, 1, n);
  }
  dfs(1, 1, n);
  for (int i = 1; i <= (n); i++) cout << res[i] << " ";
  return 0;
}
