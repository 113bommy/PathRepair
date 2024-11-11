#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 2147483647;
struct edge {
  int to, w;
};
struct temp {
  int w, num;
  friend bool operator<(const temp& a, const temp& b) {
    return (a.w - a.w / 2) * 1ll * a.num < (b.w - b.w / 2) * 1ll * b.num;
  }
} tt;
vector<edge> g[N];
int n, T;
long long s;
int sz[N], weight[N];
void dfs(int u, int fa) {
  if (u != 1 && g[u].size() == 1) {
    sz[u] = 1;
    return;
  }
  for (auto& x : g[u]) {
    int v = x.to, w = x.w;
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
    weight[v] = w;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n >> s;
    memset(sz, 0, sizeof sz);
    memset(weight, 0, sizeof weight);
    for (int i = 1; i <= n; i++) g[i].clear();
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    dfs(1, 0);
    priority_queue<temp> pq;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
      pq.push({weight[i], sz[i]});
      sum += weight[i] * sz[i];
    }
    int cnt = 0;
    while (sum > s) {
      tt = pq.top();
      pq.pop();
      sum -= (tt.w - tt.w / 2) * 1ll * tt.num;
      cnt++;
      pq.push({tt.w / 2, tt.num});
    }
    cout << cnt << endl;
  }
  return 0;
}
