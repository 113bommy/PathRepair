#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, m, c[MAXN], Fa[MAXN];
vector<int> st[MAXN];
vector<pair<int, int> > op[MAXN];
long long sum, ans[MAXN];
struct Edge {
  int v, nxt;
} e[MAXN << 1];
int first[MAXN], eCnt;
inline void AddEdge(int u, int v) {
  e[++eCnt].v = v;
  e[eCnt].nxt = first[u];
  first[u] = eCnt;
}
struct LCT {
  int fa[MAXN], ch[MAXN][2], siz[MAXN], son[MAXN];
  int isw[MAXN], stk[MAXN], top;
  long long son2[MAXN], ans;
  inline long long Sqr(long long x) { return x * x; }
  void DFS(int u, int f) {
    fa[u] = Fa[u] = f;
    siz[u] = 1;
    son[u] = son2[u] = 0;
    for (int i = first[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (v == f) continue;
      DFS(v, u);
      siz[u] += siz[v];
      son[u] += siz[v];
      son2[u] += Sqr(siz[v]);
    }
  }
  inline bool nroot(int x) {
    return (ch[fa[x]][0] == x) || (ch[fa[x]][1] == x);
  }
  inline void pushup(int x) {
    siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1 + son[x];
  }
  inline void Rotate(int x, int t) {
    int y = fa[x], z = fa[y], c = ch[x][t ^ 1];
    if (nroot(y)) ch[z][ch[z][1] == y] = x;
    ch[x][t ^ 1] = y;
    ch[y][t] = c;
    fa[x] = z;
    fa[y] = x;
    fa[c] = y;
    pushup(y);
  }
  inline void Splay(int x) {
    for (int y = fa[x], z = fa[y]; nroot(x); y = fa[x], z = fa[y]) {
      int f1 = (ch[y][1] == x), f2 = (ch[z][1] == y);
      if (!nroot(y)) {
        Rotate(x, f1);
        break;
      } else if (f1 ^ f2) {
        Rotate(x, f1);
        Rotate(x, f2);
      } else {
        Rotate(y, f2);
        Rotate(x, f1);
      }
    }
    pushup(x);
  }
  inline void Access(int x) {
    int u = x;
    for (int i = 0; x; i = x, x = fa[x]) {
      Splay(x);
      if (ch[x][1]) {
        son[x] += siz[ch[x][1]];
        son2[x] += Sqr(siz[ch[x][1]]);
      }
      if (i) {
        son[x] -= siz[i];
        son2[x] -= Sqr(siz[i]);
      }
      ch[x][1] = i;
      pushup(x);
    }
    Splay(u);
  }
  inline long long Query(int x) {
    Access(x);
    while (ch[x][0]) x = ch[x][0];
    Access(x);
    return son2[x];
  }
  inline void Link(int x, int y) {
    ans -= Query(x) + Query(y);
    Access(x);
    Access(y);
    fa[x] = y;
    son[y] += siz[x];
    son2[y] += Sqr(siz[x]);
    pushup(y);
    ans += Query(x);
  }
  inline void Cut(int x) {
    ans -= Query(x);
    Access(x);
    int y = ch[x][0];
    ch[x][0] = fa[y] = 0;
    pushup(x);
    ans += Query(x) + Query(y);
  }
  inline void Flip(int x, int t) {
    if (t) stk[++top] = x;
    if (isw[x]) {
      Link(x, Fa[x]);
    } else {
      Cut(x);
    }
    isw[x] ^= 1;
  }
  inline void Cancel() {
    for (int i = top; i; --i) {
      if (isw[stk[i]]) {
        Flip(stk[i], 0);
      }
    }
    top = 0;
  }
} lct;
void init() {
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i) {
    read(c[i]);
    st[c[i]].push_back(i);
  }
  for (int i = 1, u, v; i < n; ++i) {
    read(u);
    read(v);
    AddEdge(u, v);
    AddEdge(v, u);
  }
  AddEdge(n + 1, 1);
  AddEdge(1, n + 1);
  for (int i = 1, u, x; i <= m; ++i) {
    read(u);
    read(x);
    if (c[u] == x) continue;
    op[c[u]].push_back(make_pair(u, i));
    c[u] = x;
    op[c[u]].push_back(make_pair(u, i));
  }
}
void solve() {
  lct.DFS(n + 1, 0);
  sum = lct.ans = 1LL * n * n;
  for (int x = 1; x <= n; ++x) {
    for (int i = 0; i < st[x].size(); ++i) {
      lct.Flip(st[x][i], 1);
    }
    ans[0] += sum - lct.ans;
    for (int i = 0; i < op[x].size(); ++i) {
      pair<int, int> p = op[x][i];
      ans[p.second] -= sum - lct.ans;
      lct.Flip(p.first, 1);
      ans[p.second] += sum - lct.ans;
    }
    lct.Cancel();
  }
  for (int i = 0; i <= m; ++i) {
    if (i) ans[i] += ans[i - 1];
    printf("%lld\n", ans[i]);
  }
}
int main() {
  init();
  solve();
  return 0;
}
