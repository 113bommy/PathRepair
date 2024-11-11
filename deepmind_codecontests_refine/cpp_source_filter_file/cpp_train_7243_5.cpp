#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long mod = 1000000007;
const int maxn = 3e5 + 100;
int head[maxn];
struct edge {
  int to, next, w;
} e[maxn * 2];
int tol = 0;
void add(int u, int v, int w) {
  e[++tol].to = v, e[tol].w = w, e[tol].next = head[u], head[u] = tol;
}
int ans[maxn];
int sz[maxn * 2], deep[maxn], c[maxn][27];
int cnt;
int n;
int merge(int a, int b) {
  if (!a || !b) return a | b;
  int rt = ++cnt;
  sz[rt] = 1;
  for (int i = 0; i < 26; i++) {
    c[rt][i] = merge(c[a][i], c[b][i]);
    sz[rt] += sz[c[rt][i]];
  }
  return rt;
}
void dfs(int u, int f) {
  sz[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == f) continue;
    deep[v] = deep[u] + 1;
    c[u][e[i].w] = v;
    dfs(v, u);
    sz[u] += sz[v];
  }
  ans[deep[u]] += sz[u];
  cnt = n;
  int p = 0;
  for (int i = 0; i < 26; i++) p = merge(p, c[u][i]);
  ans[deep[u]] -= sz[p];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    char s[10];
    scanf("%d%d%s", &u, &v, s);
    add(u, v, s[0] - 'a');
    add(v, u, s[0] - 'a');
  }
  dfs(1, 0);
  int p = 0;
  for (int i = 1; i < n; i++)
    if (ans[i] > ans[p]) p = i;
  printf("%d\n%d\n", n - ans[p], p + 1);
  return 0;
}
