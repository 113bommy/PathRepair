#include <bits/stdc++.h>
using namespace std;
int N, A, B, Q;
vector<int> G[100000];
int V[100000];
bool f[100000];
int dp[100000][2];
int dep[100000];
int par[17][100000];
void sol(int v, int p) {
  dp[v][f[v]] = 0;
  int fs = 0;
  for (int(i) = 0; (i) < (G[v].size()); (i)++)
    if (G[v][i] != p) {
      sol(G[v][i], v);
      fs += min(dp[G[v][i]][0], dp[G[v][i]][1]);
      int t0 = dp[v][0], t1 = dp[v][1];
      dp[v][0] = min((1 << 28), t0 + dp[G[v][i]][0]);
      dp[v][1] = min((1 << 28), min(t0 + dp[G[v][i]][1], t1 + dp[G[v][i]][0]));
    }
  if (!f[v]) dp[v][0] = min(dp[v][0], fs + 1);
}
int dfs_t;
int in[100000], out[100000];
void dfs(int v, int p, int d) {
  in[v] = dfs_t++;
  for (int(i) = 0; (i) < (G[v].size()); (i)++)
    if (G[v][i] != p) dfs(G[v][i], v, d + 1);
  dep[v] = d;
  par[0][v] = p;
  out[v] = dfs_t - 1;
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int(c) = 0; (c) < (17); (c)++)
    if ((dep[a] - dep[b]) >> c & 1) a = par[c][a];
  if (a == b) return a;
  for (int c = 16; c >= 0; c--)
    if (par[c][a] != par[c][b]) a = par[c][a], b = par[c][b];
  return par[0][a];
}
vector<pair<int, int> > G2[1000];
struct BIT {
  vector<pair<int, int> > zan;
  int bit[114514];
  void ad(int x, int a) {
    x++;
    while (x < 114514) bit[x] += a, x += x & -x;
  }
  void init() {
    for (int(i) = 0; (i) < (zan.size()); (i)++)
      ad(zan[i].first, -zan[i].second);
    zan.clear();
  }
  void add(int x, int a) {
    zan.push_back(make_pair(x, a));
    ad(x, a);
  }
  int sum(int x) {
    int r = 0;
    x++;
    while (x > 0) r += bit[x], x -= x & -x;
    return r;
  }
} bit;
void sol2(int v, int p) {
  int fs = 0;
  dp[v][f[v]] = 0;
  for (int(i) = 0; (i) < (G2[v].size()); (i)++)
    if (G2[v][i].first != p) {
      int u = G2[v][i].first;
      int c = G2[v][i].second;
      sol2(u, v);
      fs += min(dp[u][0], dp[u][1]);
      int t0 = dp[v][0], t1 = dp[v][1];
      dp[v][0] = min((1 << 28), t0 + dp[u][0]);
      if (c > 1) dp[v][0] = min(dp[v][0], t0 + dp[u][1] + 1);
      dp[v][1] = min((1 << 28), min(t0 + dp[u][1], t1 + dp[u][0]));
      if (c > 1) dp[v][1] = min(dp[v][1], t1 + dp[u][1] + 1);
    }
  if (!f[v]) dp[v][0] = min(dp[v][0], fs + 1);
}
int main() {
  scanf("%d", &N);
  for (int(i) = 0; (i) < (N - 1); (i)++)
    scanf("%d%d", &A, &B), A--, B--, G[A].push_back(B), G[B].push_back(A);
  scanf("%d", &Q);
  memset((par), (-1), sizeof(par));
  dfs(0, -1, 0);
  for (int(c) = 0; (c) < (16); (c)++)
    for (int(v) = 0; (v) < (N); (v)++)
      if (par[c][v] != -1) par[c + 1][v] = par[c][par[c][v]];
  while (Q--) {
    scanf("%d", &A);
    for (int(i) = 0; (i) < (A); (i)++) scanf("%d", &V[i]), V[i]--;
    if (A <= 200) {
      vector<int> vlis;
      for (int(i) = 0; (i) < (A); (i)++)
        for (int(j) = 0; (j) < (i); (j)++) vlis.push_back(lca(V[i], V[j]));
      for (int(i) = 0; (i) < (A); (i)++) vlis.push_back(V[i]);
      vlis.push_back(0);
      sort((vlis).begin(), (vlis).end());
      (vlis).erase(unique((vlis).begin(), (vlis).end()), (vlis).end());
      bit.init();
      for (int(i) = 0; (i) < (A); (i)++)
        V[i] =
            lower_bound((vlis).begin(), (vlis).end(), (V[i])) - (vlis).begin();
      int n = vlis.size();
      vector<pair<int, int> > st;
      for (int(i) = 0; (i) < (n); (i)++)
        st.push_back(make_pair(dep[vlis[i]], i));
      for (int(i) = 0; (i) < (n); (i)++) G2[i].clear();
      sort((st).begin(), (st).end());
      for (int(_) = (1); (_) < (n); (_)++) {
        int i = st[_].second;
        int pp = bit.sum(in[vlis[i]]);
        bit.add(in[vlis[i]], i - pp);
        bit.add(out[vlis[i]] + 1, pp - i);
        G2[pp].push_back(make_pair(i, dep[vlis[i]] - dep[vlis[pp]]));
      }
      for (int(i) = 0; (i) < (n); (i)++)
        f[i] = false, dp[i][0] = dp[i][1] = (1 << 28);
      for (int(i) = 0; (i) < (A); (i)++) f[V[i]] = true;
      sol2(0, -1);
      int res = min(dp[0][0], dp[0][1]);
      if (res == (1 << 28))
        puts("-1");
      else
        printf("%d\n", res);
    } else {
      for (int(i) = 0; (i) < (N); (i)++)
        f[i] = false, dp[i][0] = dp[i][1] = (1 << 28);
      for (int(i) = 0; (i) < (A); (i)++) f[V[i]] = true;
      sol(0, -1);
      int res = min(dp[0][0], dp[0][1]);
      if (res == (1 << 28))
        puts("-1");
      else
        printf("%d\n", res);
    }
  }
}
