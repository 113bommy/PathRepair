#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
int tot, head[maxn];
struct E {
  int to, next, w;
} edge[maxn << 1];
void add(int u, int v, int w) {
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].next = head[u];
  head[u] = tot++;
}
int siz[maxn], n;
long long ans1, ans2;
void dfs(int x, int fa) {
  siz[x] = 1;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    int v = edge[i].to, w = edge[i].w;
    if (v == fa) continue;
    dfs(v, x);
    siz[x] += siz[v];
    if (siz[v] % 2 == 1) ans1 += w;
    ans2 += 1LL * w * min(n - siz[v], siz[v]);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    n *= 2;
    memset(head, -1, sizeof(head));
    tot = 0;
    memset(siz, 0, sizeof(siz));
    ans1 = ans2 = 0;
    for (int i = 1; i <= n - 1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
      add(v, u, w);
    }
    dfs(1, 0);
    printf("%lld %lld\n", ans1, ans2);
  }
}
