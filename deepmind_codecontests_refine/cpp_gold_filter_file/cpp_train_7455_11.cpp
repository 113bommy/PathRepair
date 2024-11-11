#include <bits/stdc++.h>
int n;
struct trr {
  long long value;
  long long lz;
};
trr seg[200200 * 4];
void prop(int idx, int l, int r) {
  if (seg[idx].lz) {
    if (l != r - 1) {
      seg[(idx << 1)].lz += seg[idx].lz;
      seg[((idx << 1) + 1)].lz += seg[idx].lz;
    };
    seg[idx].value += seg[idx].lz;
  };
  seg[idx].lz = 0;
};
long long qry(int idx, int l, int r, int x) {
  if (l >= r) return -1;
  prop(idx, l, r);
  if (l == r - 1) {
    return seg[idx].value;
  } else {
    int m = (l + r) >> 1;
    if (m > x) {
      return qry((idx << 1), l, m, x);
    } else {
      return qry(((idx << 1) + 1), m, r, x);
    };
  };
};
void update(int idx, int l, int r, int a, int b, long long x) {
  if (l >= r) return;
  if (l >= b || a >= r) return;
  if (a <= l && r <= b) {
    seg[idx].lz += x;
  } else {
    int m = (l + r) >> 1;
    update((idx << 1), l, m, a, b, x);
    update(((idx << 1) + 1), m, r, a, b, x);
  };
};
int bef[200200][20];
int in[200200];
int out[200200];
int inSub(int a, int b) {
  if (a == 0) return 1;
  if (b == 0) return 0;
  return in[b] >= in[a] && out[b] <= out[a];
};
int lca(int a, int b) {
  if (inSub(a, b)) return a;
  if (inSub(b, a)) return b;
  int akt = a;
  for (int i = 19; i >= 0; i--) {
    if (!inSub(bef[akt][i], b)) {
      akt = bef[akt][i];
    };
  };
  return bef[akt][0];
};
long long dp[200200][2];
std::vector<int> adj[200200];
std::vector<std::pair<std::pair<int, int>, long long> > edg[200200];
int cnt = 1;
void fdfs(int v, int p) {
  in[v] = cnt++;
  bef[v][0] = p;
  int pp = p;
  for (int i = 1; i < 19; i++) {
    bef[v][i] = bef[pp][i - 1];
    pp = bef[v][i];
  };
  for (auto j : adj[v]) {
    fdfs(j, v);
  };
  out[v] = cnt - 1;
};
int findS(int a, int v) {
  int l = 0;
  int r = adj[v].size();
  while (l < r) {
    int m = (l + r) >> 1;
    int akt = adj[v][m];
    if (inSub(akt, a)) {
      return akt;
    };
    if (in[a] < in[akt]) {
      r = m;
    } else {
      l = m + 1;
    };
  };
  return -1000;
};
void dpdfs(int v, int p) {
  for (auto j : adj[v]) {
    dpdfs(j, v);
  };
  for (auto j : adj[v]) {
    dp[v][0] += dp[j][1];
  };
  dp[v][1] = dp[v][0];
  long long tmp;
  long long va, vb;
  for (auto j : edg[v]) {
    if (j.first.first != v) {
      va = qry(1, 1, n + 1, in[j.first.first]);
      va -= dp[findS(j.first.first, v)][1];
      va += dp[j.first.first][0];
    } else {
      va = 0;
    };
    if (j.first.second != v) {
      vb = qry(1, 1, n + 1, in[j.first.second]);
      vb -= dp[findS(j.first.second, v)][1];
      vb += dp[j.first.second][0];
    } else {
      vb = 0;
    };
    tmp = va + vb + j.second + dp[v][0];
    dp[v][1] = std::max(dp[v][1], tmp);
  };
  for (auto j : adj[v]) {
    update(1, 1, n + 1, in[j], out[j] + 1, dp[v][0] - dp[j][1]);
  };
};
int main(void) {
  int m;
  scanf("%d %d", &n, &m);
  int tmp;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &tmp);
    adj[tmp].push_back(i);
  };
  fdfs(1, 0);
  int u, v, c;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d\n", &u, &v, &c);
    edg[lca(u, v)].push_back(
        std::pair<std::pair<int, int>, long long>({u, v}, c));
  };
  dpdfs(1, 0);
  printf("%lld\n", dp[1][1]);
  return 0;
};
