#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, dfn, rt, tot, p[N], dp[N], ll[N], rr[N], len[N], lk[N], T[N << 2],
    fa[20][N], ch[N][26];
vector<int> g[N];
char s[N];
int extend(int p, int c) {
  int np = ++tot;
  len[np] = len[p] + 1;
  while (p && !ch[p][c]) ch[p][c] = np, p = lk[p];
  if (!p)
    lk[np] = rt;
  else {
    int q = ch[p][c];
    if (len[q] == len[p] + 1)
      lk[np] = q;
    else {
      int nq = ++tot;
      len[nq] = len[p] + 1;
      lk[nq] = lk[q];
      lk[q] = lk[np] = nq;
      memcpy(ch[nq], ch[q], sizeof(ch[nq]));
      while (p && ch[p][c] == q) ch[p][c] = nq, p = lk[p];
    }
  }
  return np;
}
void dfs(int x) {
  ll[x] = ++dfn;
  fa[0][x] = lk[x];
  for (int i = 1; i < 20; i++) fa[i][x] = fa[i - 1][fa[i - 1][x]];
  for (int i = 0; i < g[x].size(); i++) dfs(g[x][i]);
  rr[x] = dfn;
}
int gt(int x, int l) {
  x = p[x];
  for (int i = 19; i >= 0; i--)
    if (len[fa[i][x]] >= l) x = fa[i][x];
  return x;
}
void upd(int x, int l, int r, int p, int v) {
  T[x] = max(T[x], v);
  if (l == r) return;
  int mid = l + r >> 1;
  if (p <= mid)
    upd(x << 1, l, mid, p, v);
  else
    upd(x << 1 | 1, mid + 1, r, p, v);
}
int qry(int x, int l, int r, int tl, int tr) {
  if (tl <= l && r <= tr) return T[x];
  int mid = l + r >> 1;
  if (tr <= mid) return qry(x << 1, l, mid, tl, tr);
  if (tl > mid) return qry(x << 1 | 1, mid + 1, r, tl, tr);
  return max(qry(x << 1, l, mid, tl, tr), qry(x << 1 | 1, mid + 1, r, tl, tr));
}
bool ok(int x) {
  if (dp[x] == 1) return 1;
  int p = gt(x, dp[x] - 1), q = gt(x - 1, dp[x] - 1);
  return qry(1, 1, tot, ll[p], rr[p]) >= dp[x] - 1 ||
         qry(1, 1, tot, ll[q], rr[q]) >= dp[x] - 1;
}
int main() {
  scanf("%d%s", &n, s + 1);
  reverse(s + 1, s + n + 1);
  rt = tot = 1;
  p[0] = rt;
  for (int i = 1; i <= n; i++) p[i] = extend(p[i - 1], s[i] - 'a');
  for (int i = 2; i <= tot; i++) g[lk[i]].push_back(i);
  dfs(rt);
  int ans = 0;
  for (int i = 1, j = 0; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    while (!ok(i)) {
      dp[i]--;
      j++;
      upd(1, 1, tot, ll[gt(j, dp[j])], dp[j]);
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
