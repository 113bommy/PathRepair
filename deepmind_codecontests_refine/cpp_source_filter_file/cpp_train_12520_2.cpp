#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long MOD = 1000000007;
vector<long long> G[N], edge, p;
long long n, m, child[N], ans = 0;
void dfs(int now, int pre) {
  child[now] = 1;
  for (int next : G[now]) {
    if (next == pre) continue;
    dfs(next, now);
    child[now] += child[next];
  }
  if (now != 1) edge.push_back(child[now] * (n - child[now]));
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    p.clear();
    edge.clear();
    for (int i = 0; i <= n; ++i) G[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int tmp;
      cin >> tmp;
      p.push_back(tmp);
    }
    for (int i = m; i < n - 1; ++i) p.push_back(1);
    sort(p.begin(), p.end());
    while (p.size() > n - 1) {
      long long a = p.back();
      p.pop_back();
      long long b = p.back();
      p.pop_back();
      p.push_back((a * b) % MOD);
    }
    dfs(1, -1);
    sort(edge.begin(), edge.end());
    reverse(edge.begin(), edge.end());
    int cnt = n - 1;
    for (int i = 0; i < edge.size(); ++i) {
      long long E = edge[i];
      ans = (ans + E * p[cnt--]) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
