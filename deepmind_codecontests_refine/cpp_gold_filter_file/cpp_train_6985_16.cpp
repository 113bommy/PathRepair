#include <bits/stdc++.h>
using namespace std;
long long c[500005];
map<long long, vector<int>> mp;
long long bit[500005];
map<long long, vector<int>> way[500005];
long long vs[500005];
int cur;
long long val;
int node_cnt;
void dfs(int v) {
  if (vs[v] == cur) return;
  vs[v] = cur;
  node_cnt++;
  for (int u : way[v][val]) {
    dfs(u);
  }
  return;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    long long val = (c[u] ^ c[v]);
    mp[val].push_back(u);
    mp[val].push_back(v);
    way[u][val].push_back(v);
    way[v][val].push_back(u);
  }
  bit[0] = 1;
  for (int i = 1; i <= max(n, k); i++) bit[i] = (bit[i - 1] << 1) % 1000000007;
  long long res = (bit[n] * (bit[k] - mp.size())) % 1000000007;
  for (auto it : mp) {
    val = it.first;
    vector<int> vt = it.second;
    cur++;
    node_cnt = 0;
    int comp = 0;
    for (int v : vt) {
      if (vs[v] == cur) continue;
      comp++;
      dfs(v);
    }
    res += bit[comp + (n - node_cnt)];
    res %= 1000000007;
  }
  printf("%lld", res);
  return 0;
}
