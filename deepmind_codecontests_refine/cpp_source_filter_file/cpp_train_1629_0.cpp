#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
inline int gi() {
  register int x = 0;
  register char c = getchar();
  bool f = 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') c = getchar(), f = 1;
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
struct node {
  int to, next;
} g[N << 1];
int last[N], gl;
inline void add(int x, int y) {
  g[++gl] = (node){y, last[x]};
  last[x] = gl;
  return;
}
int sum, f[N], siz[N], rt;
bool vis[N];
void getroot(int u, int fa) {
  siz[u] = 1;
  f[u] = 0;
  for (int i = last[u]; i; i = g[i].next) {
    int v = g[i].to;
    if (v == fa || vis[v]) continue;
    getroot(v, u);
    f[u] = max(f[u], siz[v]);
    siz[u] += siz[v];
  }
  f[u] = max(f[u], sum - siz[u]);
  if (f[rt] > f[u]) rt = u;
  return;
}
char a[N];
int s[N], t[1050000];
void dfs(int x, int fa, int p, int S) {
  t[S ^= (1 << s[x])] += p;
  for (int i = last[x]; i; i = g[i].next) {
    int v = g[i].to;
    if (v == fa || vis[v]) continue;
    dfs(v, x, p, S);
  }
}
long long ans[N];
long long calc(int x, int fa, int S) {
  S ^= (1 << s[x]);
  long long cnt = 0;
  for (int i = 0; i < 20; i++) cnt += t[S ^ (1 << i)];
  for (int i = last[x]; i; i = g[i].next) {
    int v = g[i].to;
    if (v == fa || vis[v]) continue;
    cnt += calc(v, x, S);
  }
  ans[x] += cnt;
  return cnt;
}
void solve(int x) {
  vis[x] = 1;
  dfs(x, 0, 1, 0);
  long long cnt = t[0];
  for (int i = 0; i < 20; i++) cnt += t[1 << i];
  for (int i = last[x]; i; i = g[i].next) {
    int v = g[i].to;
    if (vis[v]) continue;
    dfs(v, x, -1, 1 << s[x]);
    cnt += calc(v, x, 0);
    dfs(v, x, 1, 1 << s[x]);
  }
  dfs(x, 0, -1, 0);
  ans[x] += cnt / 2;
  for (int i = last[x]; i; i = g[i].next) {
    int v = g[i].to;
    if (vis[v]) continue;
    sum = siz[v];
    rt = 0;
    getroot(v, 0);
    solve(rt);
  }
  return;
}
int main() {
  int n = gi();
  for (int i = 1; i < n; i++) {
    int u = gi(), v = gi();
    add(u, v);
    add(v, u);
  }
  scanf("%s", a);
  for (int i = 0; i < n; i++) s[i + 1] = a[i] - 'a';
  f[0] = sum = n;
  rt = 0;
  getroot(1, 0);
  solve(rt);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i] + 1);
  return 0;
}
