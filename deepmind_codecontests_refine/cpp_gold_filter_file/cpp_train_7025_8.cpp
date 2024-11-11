#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const int N = 1000100;
int ch[N][26], fa[N], sz[N], C[N], vis[N], head[N], c[N], n, m,
    tot = 1, len, sum, ID, cnt, ANS[N], tt;
int dfn[N], dft;
char ss[N], sk[N];
struct poi {
  int x, y, w, opt, id;
} q[N << 2];
bool cmp(poi x, poi y) {
  if (x.x != y.x) return x.x < y.x;
  if (x.y != y.y) return x.y < y.y;
  if (x.opt != y.opt) return x.opt < y.opt;
  return 0;
}
struct pr {
  int next, to;
} a[N];
void add(int u, int v) {
  a[++tt] = (pr){head[u], v};
  head[u] = tt;
}
void insert(int id) {
  int rt = 1;
  for (int i = 1; i <= len; i++) {
    int c = ss[i] - 'a';
    if (!ch[rt][c]) ch[rt][c] = ++tot;
    rt = ch[rt][c];
  }
  C[id] = rt;
}
void input(int i) {
  scanf("%s", ss + 1);
  len = strlen(ss + 1);
  insert(i);
  for (int j = 1; j <= len; j++) sk[++sum] = ss[j];
  sk[++sum] = '$';
}
void bfs() {
  queue<int> q;
  while (!q.empty()) q.pop();
  for (int i = 0; i <= 25; i++) ch[0][i] = 1;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = 0; i <= 25; i++) {
      if (ch[x][i])
        fa[ch[x][i]] = ch[fa[x]][i], q.push(ch[x][i]);
      else
        ch[x][i] = ch[fa[x]][i];
    }
  }
}
void dfs(int x) {
  dfn[x] = ++dft;
  sz[x] = 1;
  for (int i = head[x]; i; i = a[i].next) {
    int y = a[i].to;
    dfs(y);
    sz[x] += sz[y];
  }
}
void ise(int x, int y, int w, int opt, int id) {
  if (x < 1 || y < 1) return;
  q[++cnt] = (poi){x, y, w, opt, id};
}
void pre() {
  bfs();
  for (int i = 1; i <= tot; i++) add(fa[i], i);
  dfs(1);
  int rt = 1, ID = 1;
  for (int i = 1; i <= sum; i++) {
    if (sk[i] == '$') {
      ID++;
      rt = 1;
      continue;
    }
    int c = sk[i] - 'a';
    rt = ch[rt][c];
    ise(dfn[rt], ID, 1, 1, 0);
  }
}
void INS(int x, int y, int l, int r, int id) {
  int L, R;
  ise(x - 1, l - 1, 1, 2, id);
  ise(y, l - 1, -1, 2, id);
  ise(x - 1, r, -1, 2, id);
  ise(y, r, 1, 2, id);
}
void update(int x, int w) {
  while (x <= n) {
    c[x] += w;
    x += x & (-x);
  }
}
int query(int x) {
  int sum = 0;
  while (x) {
    sum += c[x];
    x -= x & (-x);
  }
  return sum;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) input(i);
  pre();
  for (int i = 1; i <= m; i++) {
    int l = read(), r = read(), k = read();
    int x = C[k], L = dfn[x], R = L + sz[x] - 1;
    INS(L, R, l, r, i);
  }
  sort(q + 1, q + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    int y = q[i].y, w = q[i].w, opt = q[i].opt, id = q[i].id;
    if (opt == 1)
      update(y, 1);
    else
      ANS[id] += w * query(y);
  }
  for (int i = 1; i <= m; i++) cout << ANS[i] << '\n';
}
