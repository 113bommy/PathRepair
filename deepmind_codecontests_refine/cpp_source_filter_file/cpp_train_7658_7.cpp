#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15;
int x[N], y[N], w[N], s[N], par[N], cadd[N];
long long sum[N], nsum[N];
bool vis[N];
vector<int> adj[N];
void dfs(int cur, int parent, int pid) {
  int u, id, i, v;
  for (i = 0; i < adj[cur].size(); ++i) {
    id = adj[cur][i];
    u = x[id] ^ y[id] ^ cur;
    if (u != parent) {
      dfs(u, cur, id);
      sum[cur] += sum[u] + w[id];
    }
  }
  if (pid == 0) {
    return;
  }
  if (sum[cur] > s[pid]) {
    printf("-1\n");
    exit(0);
  }
  long long maxi = min((long long)s[pid] - sum[cur], (long long)w[pid] - 1);
  s[pid] -= maxi, w[pid] -= maxi;
  cadd[pid] += maxi;
}
void dfs2(int cur, int parent, int pid, long long rem) {
  int u, id, i, v;
  long long crem = rem, add, nrem;
  for (i = 0; i < adj[cur].size(); ++i) {
    id = adj[cur][i];
    u = x[id] ^ y[id] ^ cur;
    if (u != parent) {
      if (pid == 0) crem = 1e9;
      add = min((long long)cadd[id], crem);
      s[id] += add, w[id] += add;
      crem -= add;
      nrem = min(crem, (long long)s[id] - sum[u]);
      dfs2(u, cur, id, nrem);
      nsum[cur] += nsum[u] + w[id];
      crem -= nsum[u] - sum[u];
    }
  }
}
int main() {
  int n, i, u, v;
  cin >> n;
  for (i = 1; i < n; ++i)
    scanf("%d%d%d%d", &x[i], &y[i], &w[i], &s[i]), adj[x[i]].push_back(i),
        adj[y[i]].push_back(i);
  dfs(1, 0, 0);
  dfs2(1, 0, 0, 0);
  cout << n << endl;
  for (i = 1; i < n; ++i) printf("%d %d %d %d\n", x[i], y[i], w[i], s[i]);
}
