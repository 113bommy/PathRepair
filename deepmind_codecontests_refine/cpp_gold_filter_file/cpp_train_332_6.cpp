#include <bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 111;
int n, a, b;
vector<int> v[nax];
int h[nax];
int skok[nax][18];
void dfs(int u, int p) {
  h[u] = h[p] + 1;
  skok[u][0] = p;
  for (int j = 1; j <= 17; ++j) skok[u][j] = skok[skok[u][j - 1]][j - 1];
  for (auto it : v[u])
    if (it != p) dfs(it, u);
}
int lca(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  for (int i = 17; 0 <= i; --i)
    if (h[x] - (1 << i) >= h[y]) x = skok[x][i];
  if (x == y) return x;
  for (int i = 17; 0 <= i; --i)
    if (skok[x][i] != skok[y][i]) {
      x = skok[x][i];
      y = skok[y][i];
    }
  return skok[x][0];
}
int dis(int a, int b) { return h[a] + h[b] - 2 * h[lca(a, b)]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, 0);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y, k;
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
    if (dis(a, b) <= k && dis(a, b) % 2 == k % 2) {
      printf("YES\n");
      continue;
    }
    int z = dis(a, x) + 1 + dis(y, b);
    if (z <= k && z % 2 == k % 2) {
      printf("YES\n");
      continue;
    }
    z = dis(a, y) + 1 + dis(x, b);
    if (z <= k && z % 2 == k % 2) {
      printf("YES\n");
      continue;
    }
    printf("NO\n");
  }
  return 0;
}
