#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x;
}
const int _ = 4e5 + 7;
namespace SAM {
int fa[_ << 1], len[_ << 1], ch[_ << 1][27];
int lst = 1, cnt = 1;
void ins(int c) {
  if (ch[lst][c] && len[lst] + 1 == len[ch[lst][c]]) {
    lst = ch[lst][c];
    return;
  }
  int p = lst, np = ++cnt;
  lst = np;
  len[np] = len[p] + 1;
  for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
  if (!p)
    fa[np] = 1;
  else {
    int q = ch[p][c];
    if (len[q] == len[p] + 1)
      fa[np] = q;
    else {
      int nq = ++cnt;
      if (p == lst) lst = nq;
      fa[nq] = fa[q];
      fa[np] = fa[q] = nq;
      len[nq] = len[p] + 1;
      memcpy(ch[nq], ch[q], sizeof(ch[q]));
      for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
    }
  }
}
}  // namespace SAM
using namespace SAM;
char str[_];
vector<int> pos[_];
int n, q;
int c[_];
int dfn[_], dfncnt, siz[_];
int anc[_][21];
void add(int x, int y) {
  assert(x != 0);
  for (; x <= dfncnt; x += (x & (-x))) c[x] += y;
}
int ask(int x) {
  int ans = 0;
  for (; x; x -= (x & (-x))) ans += c[x];
  return ans;
}
int query(int l, int r) { return ask(r) - ask(l - 1); }
int ans[_ << 2];
int Lst[_];
vector<pair<int, pair<int, int> > > G[_];
vector<int> E[_];
void dfs(int u) {
  dfn[u] = ++dfncnt;
  siz[u] = 1;
  anc[u][0] = fa[u];
  for (int i = 1; i <= 20; ++i) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto v : E[u]) {
    dfs(v);
    siz[u] += siz[v];
  }
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) {
    lst = 1;
    scanf("%s", str);
    int m = strlen(str);
    for (int k = 0; k < m; ++k) ins(str[k] - 'a'), pos[i].push_back(lst);
    Lst[i] = lst;
  }
  for (int i = 2; i <= cnt; ++i) E[fa[i]].push_back(i);
  for (int i = 1; i <= q; ++i) {
    int l = read(), r = read(), k = read();
    G[l - 1].push_back(make_pair(i, make_pair(-1, k)));
    G[r].push_back(make_pair(i, make_pair(1, k)));
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    for (int p : pos[i]) {
      add(dfn[p], 1);
    }
    for (auto Now : G[i]) {
      pair<int, int> now = Now.second;
      int o = Now.first;
      int u = Lst[now.second], op = now.first;
      for (int k = 20; k >= 0; --k) {
        if (anc[u][k] && len[anc[u][k]] == len[u]) u = anc[u][k];
      }
      ans[o] += op * query(dfn[u], dfn[u] + siz[u] - 1);
    }
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
  return 0;
}
