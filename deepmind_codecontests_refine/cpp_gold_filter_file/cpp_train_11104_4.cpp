#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 100007, __ = _ << 1, lglg = 18;
const char *YES = "Yes", *NO = "No";
int to[__], ne[__], he[_] = {0}, ecnt = 1;
inline void adde(int a, int b) {
  to[++ecnt] = b, ne[ecnt] = he[a], he[a] = ecnt;
}
inline void addde(int a, int b) { adde(a, b), adde(b, a); }
int hav[__] = {0};
int bfa[_];
int findbfa(int x) { return bfa[x] == x ? x : bfa[x] = findbfa(bfa[x]); }
void linka(int a, int b) { bfa[findbfa(a)] = findbfa(b); }
int dep[_] = {0};
vector<int> e[_];
int ps[_], lps;
void make(int bas) {
  int got = 0;
  for (int i = 1; !got && i <= lps; i++) {
    int x = to[ps[i]];
    for (auto b : e[x])
      if (x != bas && !((dep[x] ^ dep[b]) & 1)) {
        got = 1;
        break;
      }
    if (got) break;
    x = to[ps[i] ^ 1];
    for (auto b : e[x])
      if (x != bas && !((dep[x] ^ dep[b]) & 1)) {
        got = 1;
        break;
      }
  }
  if (!got) return;
  for (int i = 1; i <= lps; i++) hav[ps[i]] = hav[ps[i] ^ 1] = 1;
}
int dfn[_] = {0}, low[_] = {0}, dcnt = 0, stk[_] = {0}, top = 0;
void dfs(int x, int ff) {
  dfn[x] = low[x] = ++dcnt, dep[x] = dep[ff] + 1;
  for (int i = he[x]; i; i = ne[i]) {
    int b = to[i];
    if (b == ff) continue;
    if (!dfn[b]) {
      stk[++top] = i, dfs(b, x);
      low[x] = min(low[x], low[b]);
      if (low[b] >= dfn[x]) {
        lps = 0;
        do {
          ps[++lps] = stk[top--];
        } while (stk[top + 1] != i);
        make(x);
      }
    } else {
      low[x] = min(low[x], dfn[b]);
      if (dfn[b] < dfn[x]) e[x].emplace_back(b);
    }
  }
}
int ed[_] = {0}, fa[_] = {0}, pfa[_][lglg + 1] = {0}, sval[_] = {0};
void dfs2(int x, int ff) {
  ed[x] = 1, fa[x] = ff;
  for (int i = he[x]; i; i = ne[i]) {
    int b = to[i];
    if (b == ff || ed[b]) continue;
    sval[b] = sval[x] + hav[i], dfs2(b, x);
  }
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int i = lglg; i >= 0; i--)
    if (dep[pfa[a][i]] >= dep[b]) a = pfa[a][i];
  if (a == b) return a;
  for (int i = lglg; i >= 0; i--)
    if (pfa[a][i] != pfa[b][i]) a = pfa[a][i], b = pfa[b][i];
  if (a != b) a = fa[a], b = fa[b];
  return a;
}
int n, m;
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty();
  for (int i = 1; i <= n; i++) bfa[i] = i;
  for (int i = 1, a, b; i <= m; i++)
    a = ty(), b = ty(), addde(a, b), linka(a, b);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i, 0);
  for (int i = 1; i <= n; i++)
    if (!ed[i]) dfs2(i, 0);
  for (int i = 1; i <= n; i++) pfa[i][0] = fa[i];
  for (int i = 1; i <= lglg; i++)
    for (int j = 1; j <= n; j++) pfa[j][i] = pfa[pfa[j][i - 1]][i - 1];
  for (int qq = 1, qn = ty(); qq <= qn; qq++) {
    int a = ty(), b = ty();
    if (findbfa(a) != findbfa(b))
      cout << NO << lf;
    else if (((dep[a] ^ dep[b]) & 1))
      cout << YES << lf;
    else
      cout << ((sval[a] + sval[b] - 2 * sval[lca(a, b)] > 0) ? YES : NO) << lf;
  }
  return 0;
}
