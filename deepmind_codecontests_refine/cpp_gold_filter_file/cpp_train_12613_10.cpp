#include <bits/stdc++.h>
using namespace std;
int getnum() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 400010;
int n, m;
int cnt;
int C[N];
int F[N];
int head[N];
struct edge {
  int v, nxt;
} vec[N << 1];
vector<pair<int, int> > V[N];
int col[N];
long long Ans[N];
long long Num;
struct LCT {
  int ch[N][2];
  int par[N];
  long long sz[N];
  long long vsz[N];
  long long ssz[N];
  int isroot(int x) { return ch[par[x]][0] != x && ch[par[x]][1] != x; }
  int chk(int x) { return ch[par[x]][1] == x; }
  long long Val(int x) { return sz[x] * sz[x]; }
  void pushup(int x) { sz[x] = sz[(ch[x][0])] + sz[(ch[x][1])] + vsz[x] + 1; }
  void rotate(int x) {
    int y = par[x], z = par[y], k = chk(x), w = ch[x][k ^ 1];
    if (!isroot(y)) ch[z][chk(y)] = x;
    par[x] = z;
    ch[y][k] = w;
    par[w] = y;
    ch[x][k ^ 1] = y;
    par[y] = x;
    pushup(y);
    pushup(x);
  }
  void splay(int x) {
    while (!isroot(x)) {
      int y = par[x];
      if (!isroot(y)) {
        if (chk(x) != chk(y))
          rotate(x);
        else
          rotate(y);
      }
      rotate(x);
    }
    pushup(x);
  }
  void access(int x) {
    int t = 0;
    while (x) {
      splay(x);
      vsz[x] += sz[(ch[x][1])] - sz[t];
      ssz[x] += Val((ch[x][1])) - Val(t);
      ch[x][1] = t;
      pushup(x);
      t = x;
      x = par[x];
    }
  }
  int getroot(int x) {
    access(x);
    splay(x);
    while ((ch[x][0])) x = (ch[x][0]);
    splay(x);
    return x;
  }
  void link(int x, int y) {
    splay(x);
    Num -= ssz[x] + Val((ch[x][1]));
    int z = getroot(y);
    access(x);
    splay(z);
    Num -= Val(ch[z][1]);
    par[x] = y;
    splay(y);
    vsz[y] += sz[x];
    ssz[y] += Val(x);
    pushup(y);
    access(x);
    splay(z);
    Num += Val(ch[z][1]);
  }
  void cut(int x, int y) {
    access(x);
    Num += ssz[x];
    int z = getroot(y);
    access(x);
    splay(z);
    Num -= Val(ch[z][1]);
    splay(x);
    ch[x][0] = par[ch[x][0]] = 0;
    pushup(x);
    splay(z);
    Num += Val(ch[z][1]);
  }
} lct;
void addedge(int u, int v) {
  vec[++cnt] = (edge){v, head[u]};
  head[u] = cnt;
}
void dfs(int u, int fa) {
  F[u] = fa;
  for (int i = head[u]; i; i = vec[i].nxt) {
    int v = vec[i].v;
    if (v == fa) continue;
    dfs(v, u);
  }
}
void get_work() {
  n = getnum();
  m = getnum();
  for (int i = 1; i <= n; ++i) C[i] = getnum();
  for (int i = 1; i <= n - 1; ++i) {
    int u = getnum(), v = getnum();
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; ++i) V[C[i]].push_back(make_pair(0, i));
  for (int i = 1; i <= m; ++i) {
    int u = getnum(), v = getnum();
    V[C[u]].push_back(make_pair(i, u));
    C[u] = v;
    V[C[u]].push_back(make_pair(i, u));
  }
  dfs(1, n + 1);
  for (int i = 1; i <= n + 1; ++i) lct.pushup(i);
  for (int i = 1; i <= n; ++i) lct.link(i, F[i]);
  for (int i = 1; i <= n; ++i) {
    long long lst = 0;
    for (int j = 0, limit = V[i].size(); j < limit; ++j) {
      int u = V[i][j].second, t = V[i][j].first;
      col[u] ? lct.link(u, F[u]) : lct.cut(u, F[u]);
      col[u] ^= 1;
      Ans[t] += (long long)n * n - Num - lst;
      lst = (long long)n * n - Num;
    }
    for (int j = 0, limit = V[i].size(); j < limit; ++j) {
      int u = V[i][j].second;
      if (col[u]) lct.link(u, F[u]), col[u] ^= 1;
    }
  }
  for (int i = 1; i <= m; ++i) Ans[i] += Ans[i - 1];
  for (int i = 0; i <= m; ++i) cout << Ans[i] << '\n';
}
signed main() {
  get_work();
  return 0;
}
