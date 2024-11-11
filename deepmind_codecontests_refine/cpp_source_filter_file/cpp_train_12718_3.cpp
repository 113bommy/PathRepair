#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 1e6 + 10;
struct tree {
  int v, next;
} e[2 * MAX];
long long head[MAX], size[MAX];
long long f[MAX], d[MAX];
int tot;
void add(int u, int v) {
  e[++tot].v = v;
  e[tot].next = head[u];
  head[u] = tot;
}
void dfs(int now, int fa) {
  size[now] = 1;
  for (int i = head[now]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, now);
    size[now] += size[v];
    d[now] += d[v];
  }
  d[now] += size[now];
}
void dp(int now, int fa) {
  f[now] = f[fa] - 2 * size[now] + n;
  for (int i = head[now]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa) continue;
    dp(v, now);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  long long ans = 0;
  f[1] = d[1];
  for (int i = head[1]; i; i = e[i].next) {
    int v = e[i].v;
    dp(v, 1);
  }
  int flag = 1;
  for (int i = 2; i <= n; i++)
    if (ans < f[i]) {
      flag = i;
      ans = f[i];
    }
  printf("%d\n", ans);
  return 0;
}
