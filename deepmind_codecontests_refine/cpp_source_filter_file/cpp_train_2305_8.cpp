#include <bits/stdc++.h>
using namespace std;
const int N = 300005, mod = 998244353;
int p[N], noww[2 * N], goal[2 * N], siz[N];
int anc[N], dep[N], imp[N], top[N], col[N], dp[N][2];
int n, k, cnt, t1, t2;
vector<int> ve[N];
void Link(int f, int t) {
  noww[++cnt] = p[f];
  goal[cnt] = t, p[f] = cnt;
  noww[++cnt] = p[t];
  goal[cnt] = f, p[t] = cnt;
}
void Add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void Mul(int &x, int y) { x = 1ll * x * y % mod; }
void DFS(int nde, int fth, int dth) {
  int tmp = 0;
  siz[nde] = 1, anc[nde] = fth, dep[nde] = dth;
  for (int i = p[nde]; i; i = noww[i])
    if (goal[i] != fth) {
      DFS(goal[i], nde, dth + 1);
      siz[nde] += siz[goal[i]];
      if (siz[goal[i]] > tmp) tmp = siz[goal[i]], imp[nde] = goal[i];
    }
}
void Decompose(int nde, int tpp) {
  top[nde] = tpp;
  if (imp[nde]) {
    Decompose(imp[nde], tpp);
    for (int i = p[nde]; i; i = noww[i])
      if (goal[i] != anc[nde] && goal[i] != imp[nde])
        Decompose(goal[i], goal[i]);
  }
}
int LCA(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = anc[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
void Climb(int nde, int lca, int cor) {
  while (nde != lca) {
    nde = anc[nde];
    if (col[nde]) {
      if (col[nde] == cor)
        return;
      else
        printf("0"), exit(0);
    }
    col[nde] = cor;
  }
}
void Getans(int nde, int fth) {
  vector<int> v1, v2;
  dp[nde][(bool)col[nde]] = 1;
  for (int i = p[nde]; i; i = noww[i])
    if (goal[i] != fth) {
      int g = goal[i];
      Getans(g, nde);
      int s = (dp[g][0] + dp[g][1]) % mod;
      v1.push_back(s), v2.push_back(s);
      col[nde] ? Mul(dp[nde][1], s) : Mul(dp[nde][0], s);
    }
  if (!col[nde] && v1.size()) {
    int sz = v1.size(), pt = 0;
    for (int i = 1; i < sz; i++) Mul(v1[i], v1[i - 1]);
    for (int i = sz - 2; i >= 0; i--) Mul(v2[i], v2[i + 1]);
    for (int i = p[nde]; i; i = noww[i])
      if (goal[i] != fth) {
        int pre = pt ? v1[pt - 1] : 1, suf = (pt == sz - 1) ? 1 : v2[pt + 1];
        int tmp = dp[goal[i]][1];
        Mul(tmp, pre), Mul(tmp, suf), Add(dp[nde][1], tmp);
      }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &col[i]);
    if (col[i]) ve[col[i]].push_back(i);
  }
  for (int i = 1; i < n; i++) scanf("%d%d", &t1, &t2), Link(t1, t2);
  DFS(1, 0, 1), Decompose(1, 1);
  for (int i = 1; i <= k; i++) {
    vector<int> v = ve[i];
    int lca = *v.begin();
    if (v.size() > 1) {
      vector<int>::iterator it = ++v.begin();
      while (it != v.end()) lca = LCA(lca, *it++);
    }
    vector<int>::iterator it = v.begin();
    while (it != v.end()) Climb(*it++, lca, i);
  }
  Getans(1, 0);
  printf("%d", dp[1][1]);
  return 0;
}
