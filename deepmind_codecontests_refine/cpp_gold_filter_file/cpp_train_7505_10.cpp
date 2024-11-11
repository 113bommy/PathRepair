#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
int n, q, ptr, H[N], St[N], Fi[N], node[N], lz[4 * N], par[LOG][N];
pair<int, int> seg[4 * N];
vector<int> adj[N];
set<pair<int, int> > st;
int k_th(int v, int del) {
  for (int T = LOG - 1; ~T; T--) {
    if (del >> T & 1) v = par[T][v];
  }
  return v;
}
void dfs(int v, int P) {
  H[v] = H[P] + 1;
  par[0][v] = P;
  for (int T = 1; T < LOG; T++) par[T][v] = par[T - 1][par[T - 1][v]];
  St[v] = ++ptr;
  node[ptr] = v;
  for (auto u : adj[v]) {
    if (u == P) continue;
    dfs(u, v);
  }
  Fi[v] = ptr;
}
void B(int v, int tl, int tr) {
  if (tl == tr) {
    seg[v] = make_pair(0, 1);
    return;
  }
  int mid = (tl + tr) >> 1;
  B(v << 1, tl, mid);
  B(v << 1 | 1, mid + 1, tr);
  if (seg[v << 1].first == seg[v << 1 | 1].first)
    seg[v] = make_pair(seg[v << 1].first,
                       seg[v << 1].second + seg[v << 1 | 1].second);
  else
    seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}
void second(int v, int tl, int tr) {
  if (tl == tr) return;
  seg[v << 1].first += lz[v];
  seg[v << 1 | 1].first += lz[v];
  lz[v << 1] += lz[v];
  lz[v << 1 | 1] += lz[v];
  lz[v] = 0;
}
void U(int v, int tl, int tr, int l, int r, int x) {
  second(v, tl, tr);
  if (l > tr || r < tl) return;
  if (l <= tl && tr <= r) {
    lz[v] += x;
    seg[v].first += x;
    second(v, tl, tr);
    return;
  }
  int mid = (tl + tr) >> 1;
  U(v << 1, tl, mid, l, r, x), U(v << 1 | 1, mid + 1, tr, l, r, x);
  if (seg[v << 1].first == seg[v << 1 | 1].first)
    seg[v] = make_pair(seg[v << 1].first,
                       seg[v << 1].second + seg[v << 1 | 1].second);
  else
    seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  B(1, 1, n);
  while (q--) {
    int v, u;
    scanf("%d%d", &v, &u);
    if (H[v] > H[u] || (H[v] == H[u] && u > v)) swap(u, v);
    if (st.count(make_pair(v, u)) == 0) {
      st.insert(make_pair(v, u));
      if (St[v] <= St[u] && Fi[v] >= Fi[u]) {
        int del = H[u] - H[v], cu = k_th(u, del - 1);
        U(1, 1, n, St[cu], Fi[cu], +1);
        U(1, 1, n, St[u], Fi[u], -1);
      } else {
        U(1, 1, n, 1, n, +1);
        U(1, 1, n, St[v], Fi[v], -1);
        U(1, 1, n, St[u], Fi[u], -1);
      }
    } else {
      st.erase(st.find(make_pair(v, u)));
      if (St[v] <= St[u] && Fi[v] >= Fi[u]) {
        int del = H[u] - H[v], cu = k_th(u, del - 1);
        U(1, 1, n, St[cu], Fi[cu], -1);
        U(1, 1, n, St[u], Fi[u], +1);
      } else {
        U(1, 1, n, 1, n, -1);
        U(1, 1, n, St[v], Fi[v], +1);
        U(1, 1, n, St[u], Fi[u], +1);
      }
    }
    second(1, 1, n);
    if (seg[1].first == 0) {
      printf("%d\n", seg[1].second);
    } else {
      printf("0\n");
    }
  }
  return 0;
}
