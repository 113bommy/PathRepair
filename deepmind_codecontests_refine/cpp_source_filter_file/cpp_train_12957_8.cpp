#include <bits/stdc++.h>
int V[2020], n, d, root;
long long int ans;
std::vector<int> G[2020];
int f(int v, int parent) {
  long long int sum = 1;
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i];
    if (u == parent || V[root] < V[u] || V[root] == V[u] && root < u) continue;
    if (V[v] - V[u] <= d) sum = sum * (f(u, v) + 1), sum %= 1000000007;
  }
  return sum;
}
int main() {
  scanf("%d%d", &d, &n);
  for (int i = 1; i <= n; i++) scanf("%d", V + i);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) root = i, ans += f(i, -1), ans %= 1000000007;
  printf("%lld", ans);
}
