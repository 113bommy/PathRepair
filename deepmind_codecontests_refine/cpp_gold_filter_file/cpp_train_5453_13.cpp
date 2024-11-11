#include <bits/stdc++.h>
using namespace std;
int n, m, i, u, v, head[1000005], Next[2000005], adj[2000005], k, dep[1000005];
double ans;
void Push(int u, int v) {
  Next[++k] = head[u];
  head[u] = k;
  adj[k] = v;
}
void dfs(int i, int fa) {
  int j;
  ans += 1.0 / dep[i];
  for (j = head[i]; j != 0; j = Next[j])
    if (adj[j] != fa) {
      dep[adj[j]] = dep[i] + 1;
      dfs(adj[j], i);
    }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    Push(u, v);
    Push(v, u);
  }
  dep[1] = 1;
  dfs(1, 0);
  printf("%.12lf", ans);
}
