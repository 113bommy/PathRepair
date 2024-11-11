#include <bits/stdc++.h>
using namespace std;
int n, m, tot, dep, cnt, fail[1000005], ed[1000005], dfn[1000005], low[1000005],
    ch[1000005][26];
int head[1000005], vis[1000005], tr[1000005];
char s[1000005];
struct Edge {
  int v, nx;
} e[2000005];
inline int read() {
  int ret = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -ff;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = (ret << 3) + (ret << 1) + (ch ^ 48);
    ch = getchar();
  }
  return ret * ff;
}
inline void add(int x, int y) {
  e[++tot].v = y;
  e[tot].nx = head[x];
  head[x] = tot;
}
inline void insert(char *s, int idd) {
  int len = strlen(s), now = 0;
  for (int i = 0; i < len; i++) {
    int to = s[i] - 'a';
    if (!ch[now][to]) ch[now][to] = ++cnt;
    now = ch[now][to];
  }
  ed[idd] = cnt;
}
inline void build() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (ch[x][i])
        fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
      else
        ch[x][i] = ch[fail[x]][i];
    }
  }
}
void dfs(int now) {
  dfn[now] = ++dep;
  for (int i = head[now]; i; i = e[i].nx) dfs(e[i].v);
  low[now] = dep;
}
inline void modify(int x, int v) {
  while (x <= dep) {
    tr[x] += v;
    x += (x) & (-x);
  }
}
inline int query(int x) {
  int res = 0;
  while (x) {
    res += tr[x];
    x -= (x) & (-x);
  }
  return res;
}
signed main() {
  m = read(), n = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    insert(s, i);
  }
  build();
  for (int i = 1; i <= cnt; i++) add(fail[i], i);
  dfs(0);
  for (int i = 1; i <= n; i++) {
    modify(dfn[ed[i]], 1);
    modify(low[ed[i]] + 1, -1);
    vis[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    int len = strlen(s);
    if (s[0] == '+') {
      int id = 0;
      for (int i = 1; i < len; i++) id = id * 10 + s[i] - '0';
      if (vis[id]) continue;
      modify(dfn[ed[id]], 1);
      modify(low[ed[id]] + 1, -1);
      vis[id] = 1;
    } else if (s[0] == '-') {
      int id = 0;
      for (int i = 1; i < len; i++) id = id * 10 + s[i] - '0';
      if (!vis[id]) continue;
      modify(dfn[ed[id]], -1);
      modify(low[ed[id]] + 1, 1);
      vis[id] = 0;
    } else {
      int now = 0, ans = 0;
      for (int i = 1; i < len; i++) {
        int to = s[i] - 'a';
        now = ch[now][to];
        ans += query(dfn[now]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
