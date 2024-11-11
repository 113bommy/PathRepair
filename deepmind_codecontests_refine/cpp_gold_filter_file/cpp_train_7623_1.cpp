#include <bits/stdc++.h>
using namespace std;
vector<int> al[100005];
int deg[100005];
int dist[100005];
int n;
int fmax() {
  int ans = n - 1;
  for (int u = 1; u <= n; u++) {
    int cnt = 0;
    for (auto v : al[u]) {
      if (deg[v] == 1) cnt++;
    }
    ans -= max(0, cnt - 1);
  }
  return ans;
}
void dfs(int par, int u, int d) {
  dist[u] = d;
  for (auto v : al[u]) {
    if (v != par) dfs(u, v, d + 1);
  }
}
int fmin() {
  dfs(-1, 1, 0);
  int parity = -1;
  for (int u = 1; u <= n; u++) {
    if (deg[u] == 1) {
      if (parity == -1)
        parity = dist[u] % 2;
      else if (dist[u] % 2 != parity)
        return 3;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    al[a].push_back(b);
    al[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  printf("%d %d", fmin(), fmax());
}
