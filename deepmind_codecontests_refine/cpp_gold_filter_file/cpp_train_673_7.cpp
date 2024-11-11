#include <bits/stdc++.h>
using namespace std;
int N, K, a, b, x, depth[100100], p[100100][20], topar[100100], last,
    call[100100];
long long ar[2200200];
int U[100100], D[100100], usum[100100], dsum[100100];
vector<pair<int, int>> adj[100005];
bool seen[100005];
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int k = 20; k--;)
    if (depth[u] - (1 << k) >= depth[v]) u = p[u][k];
  if (u == v) return u;
  for (int k = 20; k--;)
    if (p[u][k] != p[v][k]) {
      u = p[u][k];
      v = p[v][k];
    }
  return p[u][0];
}
void dfs(int i) {
  seen[i] = 1;
  for (auto k : adj[i]) {
    if (!seen[k.first]) {
      p[k.first][0] = i;
      depth[k.first] = depth[i] + 1;
      topar[k.first] = k.second;
      dfs(k.first);
    }
  }
}
void rec(int i) {
  usum[i] = U[i];
  dsum[i] = D[i];
  for (auto k : adj[i])
    if (k.first != p[i][0]) {
      rec(k.first);
      usum[i] += usum[k.first];
      dsum[i] += dsum[k.first];
    }
  if (topar[i] == -1) return;
  if (topar[i] == 0) {
    call[i] = usum[i];
  } else {
    call[i] = dsum[i];
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= (N - 1); i++) {
    scanf("%d %d %d", &a, &b, &x);
    if (x) {
      adj[a].push_back({b, 0});
      adj[b].push_back({a, 1});
    } else {
      adj[a].push_back({b, -1});
      adj[b].push_back({a, -1});
    }
  }
  topar[1] = -1;
  dfs(1);
  for (int i = 1; i <= (19); i++)
    for (int j = 1; j <= (N); j++) p[j][i] = p[p[j][i - 1]][i - 1];
  last = 1;
  scanf("%d", &K);
  for (int i = 1; i <= (K); i++) {
    scanf("%d", &x);
    int L = lca(last, x);
    U[last]++;
    U[L]--;
    D[x]++;
    D[L]--;
    last = x;
  }
  rec(1);
  ar[0] = 1;
  for (int i = 1; i <= (2100100); i++) {
    ar[i] = (ar[i - 1] * 2) % 1000000007;
  }
  long long ans = 0;
  for (int i = 1; i <= (N); i++) {
    ans += ar[call[i]] - 1;
    ans %= 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
