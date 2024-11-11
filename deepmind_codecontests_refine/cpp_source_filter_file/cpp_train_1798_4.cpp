#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long inf = 1e18;
long long p[MAXN];
long long score[MAXN];
long long dp[MAXN][3];
vector<long long> t;
bool cmp(pair<long long, long long>& A, pair<long long, long long>& B) {
  return (A.second - A.first) > (B.second - B.first);
}
long long calc(long long diff, long long sm, long long price) {
  diff = abs(diff);
  long long a = (diff + sm) / 2;
  long long b = sm - a;
  return max(a, b) * price;
}
void dfs(int u, vector<vector<int> >& graph, vector<int>& used) {
  used[u] = 1;
  vector<pair<long long, long long> > child;
  long long all = 0;
  for (int v : graph[u]) {
    if (used[v] != 1) {
      dfs(v, graph, used);
      child.push_back({dp[v][0], dp[v][1]});
      all += dp[v][0];
    }
  }
  sort(child.begin(), child.end(), cmp);
  long long k = child.size();
  long long sc = score[u] - k;
  dp[u][0] = calc(sc + 1, p[u], t[u]) + all;
  dp[u][1] = calc(sc - 1, p[u], t[u]) + all;
  dp[u][2] = calc(sc, p[u], t[u]) + all;
  for (int i = 0; i < k; i++) {
    all += child[i].second - child[i].first;
    sc += 2;
    dp[u][0] = min(dp[u][0], calc(sc + 1, p[u], t[u]) + all);
    dp[u][1] = min(dp[u][1], calc(sc - 1, p[u], t[u]) + all);
    dp[u][2] = min(dp[u][2], calc(sc, p[u], t[u]) + all);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  t.resize(n);
  vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    p[u]++;
    p[v]++;
    if (h[u] == h[v]) {
      graph[u].push_back(v);
      graph[v].push_back(u);
    } else {
      if (h[u] < h[v]) {
        score[u]++;
        score[v]--;
      } else {
        score[u]--;
        score[v]++;
      }
    }
  }
  vector<int> used(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (used[i] == 1) continue;
    dfs(i, graph, used);
    ans += dp[i][2];
  }
  cout << ans << endl;
}
