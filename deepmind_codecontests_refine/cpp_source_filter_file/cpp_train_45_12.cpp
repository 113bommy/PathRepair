#include <bits/stdc++.h>
using namespace std;
class sparse_table {
 private:
  int ancestor[100010][20 + 10];
  int N;

 public:
  void init(int n, int *par) {
    int i, j;
    N = n;
    memset(ancestor, -1, sizeof(int) * 100010 * 20);
    for (i = 0; i < N; ++i) ancestor[i][0] = par[i];
    for (j = 1; (1 << j) < N; ++j) {
      for (i = 0; i < N; ++i) {
        if (ancestor[i][j - 1] < 0) continue;
        ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
      }
    }
  }
  int query(int u, int v, int *lev) {
    int i;
    if (lev[u] < lev[v]) swap(u, v);
    for (i = 20 - 1; i >= 0; --i) {
      if (lev[u] - (1 << i) < lev[v]) continue;
      u = ancestor[u][i];
    }
    if (u == v) return u;
    for (i = 20 - 1; i >= 0; --i) {
      if (ancestor[u][i] == ancestor[v][i]) continue;
      u = ancestor[u][i];
      v = ancestor[v][i];
    }
    return ancestor[u][0];
  }
};
int ssize[100010];
int outsz[100010];
int rdist[100010];
int indist[100010];
int indist2[100010];
int outdist[100010];
int outdist2[100010];
int par[100010];
int lev[100010];
vector<pair<int, int> > adj[100010];
int N;
inline int mul(int a, int b) { return (1LL * a * b) % (int)((1e9) + 7); }
inline int add(int a, int b) {
  int c = (a + b);
  return c >= (int)((1e9) + 7) ? c - (int)((1e9) + 7) : c;
}
void dfs1(int v, int p, int dpar) {
  rdist[v] = p >= 0 ? add(rdist[p], dpar) : 0;
  par[v] = p;
  lev[v] = p >= 0 ? lev[p] + 1 : 0;
  int i, u, du;
  ssize[v] = 1;
  for (i = 0; i < adj[v].size(); ++i) {
    u = adj[v][i].first;
    if (u == p) continue;
    du = adj[v][i].second;
    dfs1(u, v, du);
    ssize[v] += ssize[u];
    indist[v] = add(indist[v], indist[u]);
    indist[v] = add(indist[v], mul(du, ssize[u]));
    indist2[v] = add(indist2[v], mul(mul(du, du), ssize[u]));
    indist2[v] = add(indist2[v], indist2[u]);
    indist2[v] = add(indist2[v], mul(2, mul(du, indist[u])));
  }
  outsz[v] = N - ssize[v];
}
inline int sub(int a, int b) {
  int c = a - b;
  if (c >= (int)((1e9) + 7)) c -= (int)((1e9) + 7);
  return c < 0 ? c + (int)((1e9) + 7) : c;
}
void dfs2(int v, int p, int dpar) {
  int i;
  if (p < 0) {
    for (i = 0; i < adj[v].size(); ++i)
      dfs2(adj[v][i].first, v, adj[v][i].second);
    return;
  }
  outdist[v] = add(add(outdist[p], indist[p]), mul(dpar, N));
  outdist[v] = sub(outdist[v], add(indist[v], mul(dpar, 2 * ssize[v])));
  int all, all2;
  all = add(outdist[p], indist[p]);
  all2 = add(outdist2[p], indist2[p]);
  outdist2[v] = add(all2, add(mul(dpar, mul(dpar, N)), mul(all, mul(dpar, 2))));
  outdist2[v] = sub(outdist2[v],
                    add(indist2[v], add(mul(dpar, mul(4, indist[v])),
                                        mul(dpar, mul(dpar, 4 * ssize[v])))));
  for (i = 0; i < adj[v].size(); ++i) {
    if (adj[v][i].first == p) continue;
    dfs2(adj[v][i].first, v, adj[v][i].second);
  }
}
sparse_table T;
int get_sum(int u, int v) {
  int all2;
  int q1, q2;
  all2 = add(outdist2[u], indist2[u]);
  int l = T.query(u, v, lev);
  int duv;
  duv = sub(add(rdist[u], rdist[v]), mul(2, rdist[l]));
  if (l == v) {
    q2 = add(outdist2[v],
             add(mul(duv, mul(duv, outsz[v])), mul(mul(2, duv), outdist[v])));
    q1 = sub(all2, q2);
  } else {
    q1 = add(indist2[v],
             add(mul(duv, mul(duv, ssize[v])), mul(mul(2, duv), indist[v])));
    q2 = sub(all2, q1);
  }
  return sub(q1, q2);
}
int main() {
  int i, u, v, q;
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (i = 0; i < N - 1; ++i) {
    cin >> v >> u >> q;
    --u, --v;
    adj[u].push_back(make_pair(v, q));
    adj[v].push_back(make_pair(u, q));
  }
  dfs1(0, -1, 0);
  dfs2(0, -1, 0);
  T.init(N, par);
  cin >> q;
  while (q--) {
    cin >> u >> v;
    --u, --v;
    cout << get_sum(u, v) << '\n';
  }
  return 0;
}
