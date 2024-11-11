#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 1e6 + 1;
const long long int INF = MAX * MAX;
long long int N, M, K, cost[MAX], pre[MAX], suf[MAX], total;
vector<pair<long long int, long long int> > v[MAX], w[MAX];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> K;
  for (long long int i = 1; i <= M; ++i) {
    long long int d, f, t, c;
    cin >> d >> f >> t >> c;
    if (f == 0)
      w[d].push_back({t, c});
    else
      v[d].push_back({f, c});
  }
  total = N * INF;
  for (long long int i = 1; i <= N; ++i) cost[i] = INF;
  pre[0] = total;
  for (long long int i = 1; i < MAX; ++i) {
    for (auto it : v[i]) {
      if (cost[it.first] > it.second) {
        total = total - cost[it.first];
        cost[it.first] = it.second;
        total = total + cost[it.first];
      }
    }
    pre[i] = min(pre[i - 1], total);
  }
  total = N * INF;
  for (long long int i = 1; i <= N; ++i) cost[i] = INF;
  suf[MAX - 1] = total;
  for (long long int i = MAX - 2; i > 0; --i) {
    for (auto it : w[i]) {
      if (cost[it.first] > it.second) {
        total = total - cost[it.first];
        cost[it.first] = it.second;
        total = total + cost[it.first];
      }
    }
    suf[i] = min(suf[i + 1], total);
  }
  long long int ans = N * INF * 3;
  for (long long int i = 1; i < MAX; ++i) {
    if (i + K + 1 >= MAX) break;
    ans = min(ans, pre[i] + suf[i + K + 1]);
  }
  if (ans >= N * MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
