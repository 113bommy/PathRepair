#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-12;
const long double PI = 3.1415926535897932384626433832795028841;
const long long MD = 925262732;
const long long T = 634521;
const int N = 200100;
const int M = 201;
int n, m, p[N * 4], b[N], q, tin[N], tout[N], timer = 0;
long long a[N];
bool mark[N];
vector<int> g[N], pp;
bitset<1000> t[N * 4], bb, ww;
void dfs(int v) {
  tin[v] = ++timer;
  b[timer] = a[v] % m;
  for (int i = 0; i < int(int((g[v]).size())); i++)
    if (!tin[g[v][i]]) dfs(g[v][i]);
  tout[v] = timer;
}
void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v][b[tl]] = 1;
  else {
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] | t[v * 2 + 1];
  }
}
void push(int v, int tl, int tr) {
  if (tl != tr) {
    p[v * 2] += p[v];
    p[v * 2] %= m;
    p[v * 2 + 1] += p[v];
    p[v * 2 + 1] %= m;
  }
  p[v] %= m;
  t[v] = (t[v] << p[v]) | (t[v] >> (m - p[v]));
  p[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (l > r) return;
  if (tl == l && tr == r) {
    p[v] += val;
    p[v] %= m;
    push(v, tl, tr);
  } else {
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[v * 2] | t[v * 2 + 1];
  }
}
void get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (l > r) return;
  if (tl == l && tr == r)
    ww = ww | t[v];
  else {
    int tm = (tl + tr) / 2;
    get(v * 2, tl, tm, l, min(r, tm));
    get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 2; i <= m; i++)
    if (!mark[i]) {
      pp.push_back(i);
      int j = i * i;
      while (j <= m) {
        mark[j] = 1;
        j += i;
      }
    }
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < int(n - 1); i++) {
    int first, second;
    cin >> first >> second;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  dfs(1);
  build(1, 1, n);
  cin >> q;
  for (int u = 0; u < int(q); u++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, first;
      cin >> v >> first;
      update(1, 1, n, tin[v], tout[v], first);
    } else {
      int v;
      cin >> v;
      int ans = 0;
      ww = 0;
      get(1, 1, n, tin[v], tout[v]);
      for (int i = 0; i < int(int((pp).size())); i++)
        if (ww[pp[i]]) ans++;
      cout << ans << endl;
    }
  }
  return 0;
}
