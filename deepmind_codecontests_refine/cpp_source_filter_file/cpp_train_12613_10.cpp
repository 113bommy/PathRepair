#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
struct Node {
  int fa, ch[2], siz, sizi;
  long long siz2i;
  long long siz2() { return (long long)siz * siz; }
} t[N];
bool nroot(int x);
void rotate(int x);
void Splay(int x);
void access(int x);
int findroot(int x);
void link(int x);
void cut(int x);
void pushup(int x);
void add(int u, int v);
void dfs(int u);
int head[N], nxt[N << 1], to[N << 1], cnt;
int n, m, c[N], f[N];
long long ans, delta[N];
bool bw[N];
vector<int> mod[N][2];
int main() {
  int i, j, u, v;
  long long last;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%d", c + i);
    mod[c[i]][0].push_back(i);
    mod[c[i]][1].push_back(0);
  }
  for (i = 1; i <= n + 1; ++i) t[i].siz = 1;
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    mod[c[u]][0].push_back(u);
    mod[c[u]][1].push_back(i);
    c[u] = v;
    mod[v][0].push_back(u);
    mod[v][1].push_back(i);
  }
  f[1] = n + 1;
  dfs(1);
  for (i = 1; i <= n; ++i) link(i);
  for (i = 1; i <= n; ++i) {
    if (!mod[i][0].size()) {
      delta[0] += (long long)n * n;
      continue;
    }
    if (mod[i][1][0]) {
      delta[0] += (long long)n * n;
      last = (long long)n * n;
    } else
      last = 0;
    for (j = 0; j < mod[i][0].size(); ++j) {
      u = mod[i][0][j];
      if (bw[u] ^= 1)
        cut(u);
      else
        link(u);
      if (j == mod[i][0].size() - 1 || mod[i][1][j + 1] != mod[i][1][j]) {
        delta[mod[i][1][j]] += ans - last;
        last = ans;
      }
    }
    for (j = mod[i][0].size() - 1; ~j; --j) {
      u = mod[i][0][j];
      if (bw[u] ^= 1)
        cut(u);
      else
        link(u);
    }
  }
  ans = (long long)n * n * n;
  for (i = 0; i <= m; ++i) {
    ans -= delta[i];
    printf("%I64d ", ans);
  }
  return 0;
}
bool nroot(int x) { return x == t[t[x].fa].ch[0] || x == t[t[x].fa].ch[1]; }
void rotate(int x) {
  int y = t[x].fa;
  int z = t[y].fa;
  int k = x == t[y].ch[1];
  if (nroot(y)) t[z].ch[y == t[z].ch[1]] = x;
  t[x].fa = z;
  t[y].ch[k] = t[x].ch[k ^ 1];
  t[t[x].ch[k ^ 1]].fa = y;
  t[x].ch[k ^ 1] = y;
  t[y].fa = x;
  pushup(y);
  pushup(x);
}
void Splay(int x) {
  while (nroot(x)) {
    int y = t[x].fa;
    int z = t[y].fa;
    if (nroot(y)) (x == t[y].ch[1]) ^ (y == t[z].ch[1]) ? rotate(x) : rotate(y);
    rotate(x);
  }
}
void access(int x) {
  for (int y = 0; x; x = t[y = x].fa) {
    Splay(x);
    t[x].sizi += t[t[x].ch[1]].siz;
    t[x].sizi -= t[y].siz;
    t[x].siz2i += t[t[x].ch[1]].siz2();
    t[x].siz2i -= t[y].siz2();
    t[x].ch[1] = y;
    pushup(x);
  }
}
int findroot(int x) {
  access(x);
  Splay(x);
  while (t[x].ch[0]) x = t[x].ch[0];
  Splay(x);
  return x;
}
void link(int x) {
  int y = f[x];
  Splay(x);
  ans -= t[x].siz2i + t[t[x].ch[1]].siz2();
  int z = findroot(y);
  ans -= t[t[z].ch[1]].siz2();
  t[x].fa = y;
  Splay(y);
  t[y].sizi += t[x].siz;
  t[y].siz2i += t[x].siz2();
  pushup(y);
  access(x);
  Splay(z);
  ans += t[t[z].ch[1]].siz2();
}
void cut(int x) {
  int y = f[x];
  Splay(x);
  ans += t[x].siz2i;
  int z = findroot(y);
  access(x);
  Splay(z);
  ans -= t[t[z].ch[1]].siz2();
  Splay(x);
  t[x].ch[0] = t[t[x].ch[0]].fa = 0;
  pushup(x);
  Splay(z);
  ans += t[t[z].ch[1]].siz2();
}
void pushup(int x) {
  t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + t[x].sizi + 1;
}
void add(int u, int v) {
  nxt[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
void dfs(int u) {
  int i, v;
  for (i = head[u]; i; i = nxt[i]) {
    v = to[i];
    if (v != f[u]) {
      f[v] = u;
      dfs(v);
    }
  }
}
