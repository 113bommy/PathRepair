#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = (1 << 20), Inf = 1e9;
int n, tot, sum, rt, head[N], state[M], a[N], size[N], maxp[N];
long long ans[N];
bool vis[N];
char ch;
struct edge {
  int next, to;
} e[N * 2];
void add(int from, int to) {
  e[++tot].to = to;
  e[tot].next = head[from];
  head[from] = tot;
}
void findrt(int x, int fa) {
  size[x] = 1;
  maxp[x] = 0;
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (!vis[v] && v != fa) {
      findrt(v, x);
      size[x] += size[v];
      maxp[x] = max(maxp[x], size[v]);
    }
  }
  maxp[x] = max(maxp[x], sum - size[x]);
  if (maxp[x] < maxp[rt]) rt = x;
}
void dfs1(int x, int fa, int S, int val) {
  state[S] += val;
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (!vis[v] && v != fa) dfs1(v, x, S ^ a[v], val);
  }
}
long long dfs2(int x, int fa, int S) {
  size[x] = 1;
  long long cnt = state[S];
  for (int i = 0; i < 20; i++) cnt += state[S ^ (1 << i)];
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (!vis[v] && v != fa) {
      cnt += dfs2(v, x, S ^ a[v]);
      size[x] += size[v];
    }
  }
  ans[x] += cnt;
  return cnt;
}
void calc(int x) {
  dfs1(x, 0, a[x], 1);
  int cnt = state[0] + 1;
  for (int i = 0; i < 20; i++) cnt += state[1 << i];
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (!vis[v]) {
      dfs1(v, x, a[v] ^ a[x], -1);
      cnt += dfs2(v, x, a[v]);
      dfs1(v, x, a[v] ^ a[x], 1);
    }
  }
  dfs1(x, 0, a[x], -1);
  ans[x] += cnt / 2;
}
void solve(int x) {
  calc(x);
  vis[x] = 1;
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (!vis[v]) {
      sum = size[v];
      rt = 0;
      maxp[0] = Inf;
      findrt(v, x);
      solve(rt);
    }
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  for (int i = 1; i <= n; i++) {
    while (ch = getchar())
      if (ch >= 'a' && ch <= 'z') break;
    a[i] = (1 << ch - 'a');
  }
  rt = 0;
  maxp[0] = Inf;
  sum = n;
  findrt(1, 0);
  solve(rt);
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  return 0;
}
