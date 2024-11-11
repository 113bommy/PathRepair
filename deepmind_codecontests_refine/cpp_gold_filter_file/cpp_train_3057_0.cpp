#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  int f = 0, c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == 45, c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (f) x = -x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
namespace run {
const int maxn = 1e6 + 10;
char s[maxn], str[maxn];
struct Edge {
  int nxt, to;
} edge[maxn << 1];
int begn[maxn << 1], e;
int siz[maxn << 1];
int ans, n, m, l, p, q, tim;
namespace Sam {
int nxt[maxn << 1][26], len[maxn << 1], link[maxn << 1], vis[maxn << 1];
int tot = 1, last = 1;
inline void extend(int c) {
  int pos = last, now = ++tot;
  len[now] = len[pos] + 1;
  siz[now] = 1;
  while (~pos && nxt[pos][c] == 0) nxt[pos][c] = now, pos = link[pos];
  if (pos == -1)
    link[now] = 0;
  else {
    int d = nxt[pos][c];
    if (len[d] == len[pos] + 1)
      link[now] = d;
    else {
      int v = ++tot;
      for (register int i = 0; i < 26; ++i) nxt[v][i] = nxt[d][i];
      len[v] = len[pos] + 1;
      link[v] = link[d], link[d] = v, link[now] = v;
      while (~pos && nxt[pos][c] == d) nxt[pos][c] = v, pos = link[pos];
    }
  }
  last = now;
  return;
}
inline void init(int c) {
  while (p && !nxt[p][c]) l = len[p = link[p]];
  if (nxt[p][c]) ++l, p = nxt[p][c];
  return;
}
inline void calc() {
  if (l == m && vis[p] < tim) ans += siz[p], vis[p] = tim;
  return;
}
inline void del() {
  if (l > m && --l == len[link[p]]) p = link[p];
  return;
}
}  // namespace Sam
inline void add(int x, int y) {
  edge[++e] = (Edge){begn[x], y};
  begn[x] = e;
  return;
}
inline void dfs(int x) {
  for (register int i = begn[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    dfs(y);
    siz[x] += siz[y];
  }
  return;
}
inline int main() {
  scanf("%s", str);
  read(q);
  n = strlen(str);
  Sam ::link[0] = -1;
  for (register int i = 0; i < n; ++i) Sam ::extend(str[i] - 'a');
  for (register int i = 1; i <= Sam ::tot; ++i) add(Sam ::link[i], i);
  dfs(0);
  for (tim = 1; tim <= q; ++tim) {
    scanf("%s", s);
    m = strlen(s);
    ans = p = l = 0;
    for (register int i = 0; i < m; ++i) Sam ::init(s[i] - 'a');
    Sam ::calc();
    for (register int i = 0; i < m - 1; ++i) {
      Sam ::init(s[i] - 'a');
      Sam ::del();
      Sam ::calc();
    }
    printf("%d\n", ans);
  }
  return 0;
}
}  // namespace run
int main() { return run ::main(); }
