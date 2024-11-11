#include <bits/stdc++.h>
inline int read() {
  int x = 0, op = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * op;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 2e5 + 10;
int n, cnt;
int head[N], sum[N], diff[N];
int pre[N], path[N], a[N];
struct edge {
  int to, nxt, val;
} e[N];
void add(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void dfs(int u, int id, long long dis) {
  pre[id] = dis;
  path[id] = u;
  int l = 1, r = id;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[u] >= dis - pre[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }
  diff[path[r]]--;
  diff[path[id - 1]]++;
  for (int i = head[u]; ~i; i = e[i].nxt) dfs(e[i].to, id + 1, dis + e[i].val);
}
void dfs_ans(int u) {
  sum[u] = diff[u];
  for (int i = head[u]; ~i; i = e[i].nxt) {
    int v = e[i].to;
    dfs_ans(v);
    sum[u] += sum[v];
  }
}
int main() {
  memset(head, -1, sizeof head);
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 2, fa, w; i <= n; ++i) {
    fa = read(), w = read();
    add(fa, i, w);
  }
  dfs(1, 1, 0);
  dfs_ans(1);
  for (int i = 1; i <= n; ++i) write(sum[i]), putchar(' ');
  return 0;
}
