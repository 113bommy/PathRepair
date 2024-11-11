#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 1e6 + 5;
int bas = N * 2, son = N * 2, h[N], s, t, n, m, x, y, in[N], dp[N];
vector<int> v[N];
pair<int, int> dq[N * 6];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    v[y].push_back(x);
    in[x]++;
  }
  scanf("%d %d", &s, &t);
  for (int i = 1; i <= n; i++) dp[i] = inf;
  dq[++son] = make_pair(0, t);
  bas = son;
  while (bas <= son) {
    int node = dq[bas].second;
    int cost = dq[bas++].first;
    if (h[node]) continue;
    h[node] = 1;
    dp[node] = cost;
    for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
         it++) {
      if (dp[node] + 1 < dp[*it]) {
        dp[*it] = dp[node] + 1;
        dq[son++] = make_pair(dp[*it], *it);
      }
      if (!--in[*it]) {
        if (dp[*it] > dp[node]) {
          dp[*it] = dp[node];
          dq[--bas] = make_pair(dp[node], *it);
        }
      }
    }
  }
  if (dp[s] < inf)
    cout << dp[s] << '\n';
  else
    cout << -1 << '\n';
  return 0;
}
