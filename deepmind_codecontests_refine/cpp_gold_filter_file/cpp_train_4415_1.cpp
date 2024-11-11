#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e18, Big = 314000000;
;
vector<int> rule[maxn], rev[maxn];
int who[maxn], del[maxn], ones[maxn];
vector<int> v[maxn];
long long dp1[maxn], dp2[maxn], cost[maxn];
bool bad[maxn], badr[maxn];
int mark[maxn];
void dfs(int u) {
  mark[u] = 1;
  for (int r : v[u]) {
    if (badr[r]) continue;
    long long num = ones[r];
    for (int y : rule[r]) {
      if (mark[y] == 1) {
        bad[u] = 1;
      }
      if (mark[y] == 0) {
        dfs(y);
      }
      bad[u] |= bad[y];
      num += dp2[y];
      num = min(num, Big);
    }
    dp2[u] = max(dp2[u], num);
  }
  mark[u] = 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    int u;
    cin >> u;
    --u;
    v[u].push_back(i);
    who[i] = u;
    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;
      if (x == -1)
        cost[i]++, ones[i]++;
      else
        --x, rule[i].push_back(x), rev[x].push_back(i);
    }
  }
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      pq;
  for (int i = 0; i < n; i++) {
    dp1[i] = inf;
    for (int j : v[i])
      if (rule[j].empty()) dp1[i] = min(dp1[i], cost[j]);
    if (dp1[i] != inf) pq.push({dp1[i], i});
  }
  while (int((pq).size())) {
    int u = pq.top().second;
    pq.pop();
    if (mark[u]) continue;
    mark[u] = 1;
    for (int y : rev[u]) {
      cost[y] += dp1[u];
      cost[y] = min(cost[y], Big);
      if (++del[y] == int((rule[y]).size())) {
        if (dp1[who[y]] > cost[y])
          dp1[who[y]] = cost[y], pq.push({cost[y], who[y]});
      }
    }
  }
  memset(mark, 0, sizeof mark);
  for (int i = 0; i < n; i++) {
    if (dp1[i] == inf) {
      mark[i] = 2;
      for (int u : rev[i]) badr[u] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (mark[i] == 0) dfs(i);
  }
  for (int i = 0; i < n; i++) {
    if (dp1[i] == inf)
      cout << -1 << " " << -1 << "\n";
    else if (bad[i])
      cout << dp1[i] << " " << -2 << "\n";
    else
      cout << dp1[i] << " " << dp2[i] << "\n";
  }
  return 0;
}
