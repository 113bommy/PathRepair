#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct node {
  int v, next;
} p[200005];
int head[200005], n, k;
long long dp[200005][10], size[200005], ans;
void dfs(int x, int fa, int depth) {
  size[x] = dp[x][depth % k] = 1;
  for (int i = head[x]; ~i; i = p[i].next) {
    if (p[i].v == fa) continue;
    dfs(p[i].v, x, depth + 1);
    for (int a = 0; a < k; a++) {
      for (int b = 0; b < k; b++) {
        int dis = ((a + b) % k - (depth * 2) % k + k) % k;
        ans += ((k - dis) % k) * dp[x][a] * dp[p[i].v][b];
      }
    }
    for (int a = 0; a < k; a++) {
      dp[x][a] += dp[p[i].v][a];
    }
    ans += size[p[i].v] * (n - size[p[i].v]);
    size[x] += size[p[i].v];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  memset(head, -1, sizeof(head));
  int len = 0;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    p[len].v = v;
    p[len].next = head[u];
    head[u] = len++;
    p[len].v = u;
    p[len].next = head[v];
    head[v] = len++;
  }
  dfs(1, 0, 0);
  printf("%d\n", ans / k);
}
