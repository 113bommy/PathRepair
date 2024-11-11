#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
const int MAXM = MAXN * 10;
struct edge {
  int u, v, c, t;
} e[MAXN];
vector<int> g[MAXM], pt[MAXN];
int n, m, num, bin[MAXN], tot;
int dfn[MAXM], low[MAXM], stk[MAXM], scc[MAXM], cnt, tmr, indx;
void tar(int u) {
  dfn[u] = low[u] = ++tmr;
  stk[++indx] = u;
  for (int v, i = (int)g[u].size() - 1; ~i; --i) {
    if (!dfn[v = g[u][i]])
      tar(v), low[u] = min(low[u], low[v]);
    else if (!scc[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    ++cnt;
    do scc[stk[indx]] = cnt;
    while (stk[indx--] != u);
  }
}
bool chk(int mid) {
  for (int i = 1; i <= m; ++i)
    if (e[i].t > mid) g[i].push_back(i + m);
  memset(dfn, 0, (num + 1) << 2);
  tmr = 0;
  memset(scc, 0, (num + 1) << 2);
  cnt = 0;
  for (int i = 1; i <= num; ++i)
    if (!dfn[i]) tar(i);
  bool re = 1;
  for (int i = 1; i <= m; ++i)
    if (scc[i] == scc[i + m]) {
      re = 0;
      break;
    }
  for (int i = 1; i <= m; ++i)
    if (e[i].t > mid) g[i].pop_back();
  return re;
}
inline bool cmp(int i, int j) { return e[i].c < e[j].c; }
inline void link(int u, int v, int flg) {
  if (flg) swap(u, v);
  g[u].push_back(v);
}
void work(const vector<int> &vec, int flg) {
  int S, T;
  for (int i = 0; i < vec.size(); ++i) {
    int x = vec[i], y = vec[i] + m, s = ++num, t = ++num;
    link(x, s, flg), link(t, y, flg);
    if (i) {
      link(x, T, flg), link(S, y, flg);
      link(S, s, flg), link(t, T, flg);
    }
    S = s, T = t;
  }
}
vector<int> S, ans;
int main() {
  scanf("%d%d", &n, &m);
  num = m << 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].c, &e[i].t);
    pt[e[i].u].push_back(i), pt[e[i].v].push_back(i);
    bin[++tot] = e[i].t;
  }
  for (int i = 1; i <= n; ++i) {
    sort(pt[i].begin(), pt[i].end(), cmp);
    work(pt[i], 0);
    for (int l = 0, r = 0; l < pt[i].size(); l = ++r) {
      S.push_back(pt[i][l]);
      for (; r + 1 < pt[i].size() && e[pt[i][r + 1]].c == e[pt[i][r]].c;)
        S.push_back(pt[i][++r]);
      work(S, 1);
      S.clear();
    }
  }
  sort(bin + 1, bin + tot + 1);
  tot = unique(bin + 1, bin + tot + 1) - bin - 1;
  if (!chk(tot)) return puts("No"), 0;
  int l = 1, r = tot, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (chk(bin[mid]))
      r = mid;
    else
      l = mid + 1;
  }
  chk(bin[l]);
  puts("Yes");
  for (int i = 1; i <= m; ++i)
    if (scc[i] < scc[i + m]) ans.push_back(i);
  printf("%d %d\n", bin[l], (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
}
