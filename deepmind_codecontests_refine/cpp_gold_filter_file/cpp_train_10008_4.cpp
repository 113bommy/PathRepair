#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
const long long MOD = (long long)998244353ll;
const long long MAXN = (long long)2e5 + 10;
const long long INF = (long long)2242545357980376863;
const long double EPS = (long double)1e-8;
struct edge {
  long long u;
  long long v;
  long long w;
};
long long anssss = 0, lm = 1;
long long par[MAXN], ind[MAXN], an[MAXN], mark[MAXN], dep[MAXN];
edge E[MAXN];
vector<long long> G[MAXN], V;
long long get_par(long long node) {
  if (par[node] == node) return node;
  return par[node] = get_par(par[node]);
}
void merge(long long u, long long v) {
  u = get_par(u);
  v = get_par(v);
  if (u == v) return;
  par[u] = v;
}
bool CMP(long long i, long long j) { return E[i].w < E[j].w; }
long long DFS(long long node, long long edg, long long d) {
  long long res, adj, ans = d;
  mark[node] = lm;
  dep[node] = d;
  for (auto in : G[node]) {
    if (in == edg) continue;
    adj = (E[in].u == node ? E[in].v : E[in].u);
    if (mark[adj] == lm) {
      anssss++;
      an[in] = 1;
      ans = min(ans, dep[adj]);
    }
    if (mark[adj] < lm) {
      res = DFS(adj, in, d + 1);
    }
  }
  mark[node] = lm + 1;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(an, -1, sizeof an);
  for (int i = 0; i < MAXN; i++) par[i] = i;
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> E[i].u >> E[i].v >> E[i].w;
    ind[i] = i;
  }
  sort(ind, ind + m, CMP);
  E[m].w = INF;
  long long i, j;
  edge e;
  long long k = 0;
  while (k < m) {
    j = k;
    while ((E[ind[k]].w == E[ind[j]].w) and (j < m)) j++;
    for (int i = k; i < j; i++) {
      e = E[ind[i]];
      if (get_par(e.u) == get_par(e.v)) {
        an[ind[i]] = 0;
        continue;
      }
      e.u = par[e.u];
      e.v = par[e.v];
      E[ind[i]] = e;
      G[par[e.u]].push_back(ind[i]);
      G[par[e.v]].push_back(ind[i]);
      V.push_back(par[e.u]);
      V.push_back(par[e.v]);
    }
    for (auto node : V) {
      if (mark[node] < lm) {
        DFS(node, -1, 0);
      }
    }
    for (int i = k; i < j; i++) {
      e = E[ind[i]];
      G[par[e.u]].clear();
      G[par[e.v]].clear();
      merge(e.u, e.v);
    }
    V.clear();
    lm += 4;
    k = j;
  }
  cout << anssss;
  return 0;
}
