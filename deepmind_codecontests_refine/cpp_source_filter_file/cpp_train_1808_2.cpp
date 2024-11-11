#include <bits/stdc++.h>
using namespace std;
vector<int> st;
vector<vector<int> > g1, g2;
int p[100100];
int was[100100];
int c[100100];
int par[100100][20];
int dp[100100];
int tin[100100];
int tout[100100];
int timer;
void dfs1(int v, int par) {
  if (was[v] == 2) return;
  if (was[v] == 1) {
    c[v] = 1;
    for (int i = (int)st.size() - 1; i >= 0; --i) {
      p[st[i]] = v;
      if (st[i] == v) break;
    }
    return;
  }
  was[v] = 1;
  st.push_back(v);
  for (int i = (0); i < (g1[v].size()); ++i) {
    int to = g1[v][i];
    if (to != par) dfs1(to, v);
  }
  was[v] = 2;
  st.pop_back();
}
void dfs2(int v, int p) {
  tin[v] = timer++;
  par[v][0] = p;
  for (int i = (1); i < (20); ++i) par[v][i] = par[par[v][i - 1]][i - 1];
  dp[v] = dp[p] + c[v];
  for (int i = (0); i < (g2[v].size()); ++i)
    if ((g2[v][i] != p) && (g2[v][i] != v)) dfs2(g2[v][i], v);
  tout[v] = timer++;
}
inline bool ispar(int v1, int v2) {
  return ((tin[v1] <= tin[v2]) && (tout[v1] >= tout[v2]));
}
inline int lca(int v1, int v2) {
  if (ispar(v1, v2)) return v1;
  if (ispar(v2, v1)) return v2;
  int v = v2;
  for (int i = 19; i >= 0; --i)
    if (!(ispar(par[v][i], v1))) v = par[v][i];
  return par[v][0];
}
int step[100100];
int mod = 1000000007;
int main() {
  step[0] = 1;
  for (int i = (1); i < (100100); ++i) {
    step[i] = step[i - 1] + step[i - 1];
    if (step[i] >= mod) step[i] -= mod;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); ++i) p[i] = i;
  g1.resize(n);
  for (int i = (0); i < (m); ++i) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    g1[v1].push_back(v2);
    g1[v2].push_back(v1);
  }
  g2.resize(n);
  dfs1(0, -1);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (g1[i].size()); ++j) g2[p[i]].push_back(g1[i][j]);
  for (int i = (0); i < (n); ++i) {
    sort(g2[i].begin(), g2[i].end());
    g2[i].resize(unique(g2[i].begin(), g2[i].end()) - g2[i].begin());
  }
  timer = 0;
  dfs2(0, 0);
  int k;
  scanf("%d", &k);
  for (int i = (0); i < (k); ++i) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    int res = 0;
    if (p[v1] == p[v2])
      res = c[p[v1]];
    else {
      v1 = p[v1];
      v2 = p[v2];
      int v = lca(v1, v2);
      if (v == v1) {
        res = dp[v2];
        if (v1) res -= dp[par[v1][0]];
      } else if (v == v2) {
        res = dp[v1];
        if (v2) res -= dp[par[v2][0]];
      } else {
        res = dp[v1] + dp[v2];
        if (v) res -= dp[par[v][0]] - dp[par[v][0]];
        res -= dp[v];
      }
    }
    printf("%d\n", step[res]);
  }
  return 0;
}
