#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int N = 3e5 + 10;
int n, cnt, head[N], in[N], rt, ans;
struct node {
  int to, next;
} edge[N << 1];
inline void add(int u, int v) {
  edge[++cnt] = {v, head[u]};
  head[u] = cnt;
}
inline void dfs(int u, int fa, int dis) {
  if (dis > ans) ans = dis, rt = u;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u, dis + in[v]);
  }
}
int main() {
  int t = read();
  while (t--) {
    int u, v;
    n = read();
    for (int i = 1; i <= n; i++) head[i] = 0, in[i] = -1;
    cnt = 0;
    for (int i = 1; i < n; i++) {
      u = read(), v = read();
      in[u]++, in[v]++;
      add(u, v), add(v, u);
    }
    ans = -1;
    dfs(1, 0, in[1]);
    ans = -1;
    dfs(rt, 0, in[rt]);
    cout << ans + 2 << endl;
  }
}
