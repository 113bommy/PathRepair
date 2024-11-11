#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m, q, tin[N], tout[N], timer, a[N], p[N], used[N];
vector<int> g[N];
bitset<1001> pr, cur;
struct node {
  bitset<1001> b;
  int add;
  node() {
    add = 0;
    b.reset();
  }
} T[N * 4];
void dfs(int v = 1, int pr = 0) {
  tin[v] = ++timer;
  p[timer] = v;
  for (auto to : g[v])
    if (to != pr) dfs(to, v);
  tout[v] = timer;
}
void build(int v = 1, int tl = 1, int tr = timer) {
  if (tl == tr) {
    T[v].b[a[p[tl]]] = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  T[v].b = (T[v * 2].b | T[v * 2 + 1].b);
}
void push(int v, int tl, int tr) {
  if (tl > tr || T[v].add == 0) return;
  if (tl != tr) {
    T[v * 2].add += T[v].add;
    T[v * 2].add %= m;
    T[v * 2 + 1].add += T[v].add;
    T[v * 2 + 1].add %= m;
  }
  T[v].b = ((T[v].b << T[v].add) | (T[v].b >> (m - T[v].add)));
  T[v].add = 0;
}
void upd(int l, int r, int x, int v = 1, int tl = 1, int tr = timer) {
  push(v, tl, tr);
  if (tl > r || tr < l) return;
  if (l <= tl && tr <= r) {
    T[v].add += x;
    T[v].add %= m;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(l, r, x, v * 2, tl, tm);
  upd(l, r, x, v * 2 + 1, tm + 1, tr);
  T[v].b = (T[v * 2].b | T[v * 2 + 1].b);
}
void get(int l, int r, int v = 1, int tl = 1, int tr = timer) {
  push(v, tl, tr);
  if (tl > r || tr < l) return;
  if (l <= tl && tr <= r) {
    cur |= T[v].b;
    return;
  }
  int tm = (tl + tr) / 2;
  get(l, r, v * 2, tl, tm);
  get(l, r, v * 2 + 1, tm + 1, tr);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= m;
  }
  for (int i = 1, a, b; i < n; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs();
  build();
  for (int i = 2; i < m; i++) {
    if (!used[i]) {
      pr[i] = 1;
      for (int j = i; j < m; j += i) used[j] = 1;
    }
  }
  cin >> q;
  for (int i = 1, t, a, b; i <= q; i++) {
    cin >> t >> a;
    if (t == 1) {
      cin >> b;
      b %= m;
      upd(tin[a], tout[a], b);
    } else {
      cur.reset();
      get(tin[a], tout[a]);
      cur = (cur & pr);
      cout << cur.count() << endl;
    }
  }
  return 0;
}
