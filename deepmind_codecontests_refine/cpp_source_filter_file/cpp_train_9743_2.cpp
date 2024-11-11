#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m, fa[MAXN];
bool vis[MAXN];
struct Edge {
  int u, v;
} e[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Union(int a, int b) {
  vis[a] = true;
  vis[b] = true;
  int u = find(a);
  int v = find(b);
  if (u != v) fa[u] = v;
}
bool ok() {
  int f = -1;
  for (int i = 1; i < n; i++) {
    if (vis[i]) {
      if (f == -1)
        f = find(i);
      else if (f != find(i))
        return false;
    }
  }
  return true;
}
int num[MAXN], sum;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i, vis[i] = false, num[i] = 0;
  sum = 0;
  for (int i = 0, u, v; i < m; i++) {
    scanf("%d%d", &u, &v);
    Union(u, v);
    e[i].u = u;
    e[i].v = v;
    if (u != v) {
      num[u]++;
      num[v]++;
    } else {
      sum++;
    }
  }
  if (ok()) {
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      if (e[i].u != e[i].v) {
        ans += num[e[i].u] - 1 + num[e[i].v] - 1 + sum;
      } else {
        ans += m - 1;
      }
    }
    printf("%lld\n", ans / 2);
  } else
    puts("0");
}
