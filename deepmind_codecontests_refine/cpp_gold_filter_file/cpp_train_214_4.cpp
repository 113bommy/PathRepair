#include <bits/stdc++.h>
using namespace std;
const long long N = 222222;
long long r[N], c[N];
vector<long long> graph[N << 1];
bool vis[N << 1];
long long n, m, q;
void dfs(long long u) {
  vis[u] = true;
  for (auto v : graph[u]) {
    if (vis[v]) continue;
    dfs(v);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> q;
  for (long long i = (1); i <= (q); i++) {
    cin >> r[i] >> c[i];
    long long u = r[i], v = c[i] + n;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  long long ans = 0;
  for (long long i = (1); i <= (n + m); i++) {
    if (vis[i]) continue;
    dfs(i);
    ans++;
  }
  ans--;
  cout << ans << endl;
  return 0;
}
