#include <bits/stdc++.h>
using namespace std;
inline int read(int x = 0, int f = 1, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 1e6 + 5;
int n, m;
int head[N], ver[N], nxt[N], tot;
int fa[N], dep[N], d[N], son[N], siz[N], del[N];
int op[N];
inline void add(int x, int y) {
  ver[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
}
void dfs(int x) {
  siz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    dfs(y);
    siz[x] += siz[y];
  }
}
int main() {
  n = read();
  for (int i = 2; i <= n; ++i)
    add(fa[i] = read() + 1, i), dep[i] = dep[fa[i]] + 1;
  for (int i = n; i >= 1; --i)
    if (d[i] + 1 > d[fa[i]]) d[fa[i]] = d[i] + 1, son[fa[i]] = i;
  dfs(1);
  for (int x = 1; x <= n; ++x)
    while (siz[x] > siz[son[x]] + 1) {
      for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa[y] != x || y == son[x]) continue;
        op[++m] = son[x];
        siz[y] += siz[son[x]];
        son[y] = son[x];
        fa[son[x]] = y;
        d[y] = d[son[x]] + 1;
        add(y, son[x]);
        d[x] = d[y] + 1;
        son[x] = y;
      }
    }
  for (int i = 1; i <= n; ++i) son[fa[i]] = i;
  printf("0 ");
  int x = 1;
  while (son[x]) printf("%d ", son[x] - 1), x = son[x];
  puts("");
  printf("%d\n", m);
  for (int i = m; i >= 1; --i) printf("%d ", op[i] - 1);
  puts("");
  return 0;
}
