#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int res = 0, flag = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * flag;
}
int n, m, head[100001], to[800001], nxt[800001], tot = -1, d[100001], x, y, lst,
                                                 cnt, now;
bool vis[800001];
vector<int> p;
inline void add(int x, int y) {
  to[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
  ++d[y];
}
void dfs(int x) {
  for (int &i = head[x]; i; i = nxt[i]) {
    if (vis[i]) continue;
    int y = to[i];
    vis[i] = vis[i ^ 1] = 1;
    dfs(y);
    ++now;
    if (now & 1)
      printf("%d %d\n", x, y);
    else
      printf("%d %d\n", y, x);
  }
}
int main() {
  n = read();
  m = read();
  for (register int i = 1; i <= m; ++i) {
    x = read();
    y = read();
    add(x, y);
    add(y, x);
  }
  for (register int i = 1; i <= n; ++i)
    if (d[i] & 1) p.push_back(i);
  for (register int i = 0, up = p.size(); i < up; i += 2) {
    add(p[i], p[i + 1]);
    add(p[i + 1], p[i]);
    ++m;
  }
  if (m & 1) {
    ++m;
    add(1, 1);
    add(1, 1);
  }
  printf("%d\n", m);
  dfs(1);
  return 0;
}
