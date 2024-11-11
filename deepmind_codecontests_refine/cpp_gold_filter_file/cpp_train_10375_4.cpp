#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char ch = getchar();
  bool f = false;
  while (!isdigit(ch)) {
    if (ch == '-') {
      f = true;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
  return;
}
const int N = 1e5 + 5;
int n, ans;
int head[N], nex[N << 1], to[N << 1], idx;
int root, dep[N], len[N], son[N];
int edge[N], cnt;
void add(int u, int v) {
  nex[++idx] = head[u];
  to[idx] = v;
  head[u] = idx;
  return;
}
void dfs1(int x, int fa) {
  dep[x] = dep[fa] + 1;
  if (dep[x] > dep[root]) root = x;
  for (int i = head[x]; i; i = nex[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs1(y, x);
  }
  return;
}
void dfs2(int x, int fa) {
  for (int i = head[x]; i; i = nex[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs2(y, x);
    if (len[y] > len[son[x]]) son[x] = y;
  }
  len[x] = len[son[x]] + 1;
  for (int i = head[x]; i; i = nex[i]) {
    int y = to[i];
    if (y == fa || y == son[x]) continue;
    edge[++cnt] = len[y];
  }
  return;
}
int main() {
  read(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    read(u), read(v);
    add(u, v);
    add(v, u);
  }
  dfs1(1, 0);
  dfs2(root, 0);
  sort(edge + 1, edge + cnt + 1);
  write(1), putchar(' ');
  ans = len[root];
  for (int i = cnt; i >= 1; i--) {
    write(ans), putchar(' ');
    ans += edge[i];
  }
  for (int i = 1; i <= n - cnt - 1; i++) write(ans), putchar(' ');
  return 0;
}
