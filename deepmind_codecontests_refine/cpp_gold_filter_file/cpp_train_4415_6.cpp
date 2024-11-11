#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
int mod = (int)1e9 + 7;
const int logN = 18;
const int inf = 1e9;
const int N = 1e6 + 5;
int qa[N], vvv[N], hh[N], start[N], low[N], T, dp[N], h[N], SP[N], n, m, x, y,
    z, root[N], k, in[N], val[N];
vector<int> bef[N], can[N], go[N];
int dfs(int node) {
  if (dp[node] != -1) return dp[node];
  start[node] = low[node] = ++T;
  dp[node] = 0;
  qa[node] = 2;
  int ttt = 0, asd = 0, sq = 0;
  for (__typeof(can[node].begin()) it = can[node].begin();
       it != can[node].end(); it++) {
    int flag = 0;
    long long tt = vvv[*it];
    ttt = 0;
    for (__typeof(go[*it].begin()) it2 = go[*it].begin(); it2 != go[*it].end();
         it2++) {
      if (!h[*it2]) {
      } else
        flag = 1;
    }
    if (flag) continue;
    for (__typeof(go[*it].begin()) it2 = go[*it].begin(); it2 != go[*it].end();
         it2++) {
      if (qa[*it2] == 2) {
        ttt = 1;
        continue;
      } else {
        tt += dfs(*it2);
        if (dfs(*it2) == inf) {
          ttt = 1;
        }
      }
    }
    if (ttt == 1) {
      sq = 1;
      tt = inf;
    } else {
      asd = 1;
      dp[node] = max(dp[node], (int)min(314000000LL, tt));
    }
  }
  if (sq) dp[node] = inf;
  qa[node] = 1;
  return dp[node];
}
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &k);
    root[i] = x;
    can[x].push_back(i);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &x);
      if (x == -1) {
        val[i]++;
        ++vvv[i];
      } else {
        go[i].push_back(x);
        in[i]++;
        bef[x].push_back(i);
      }
    }
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  for (int i = 1; i <= m; i++) {
    if (in[i] == 0) {
      pq.push(make_pair(val[i], root[i]));
    }
  }
  for (int i = 1; i <= n; i++) SP[i] = inf;
  while (pq.size()) {
    int node = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    if (hh[node]) continue;
    hh[node] = 1;
    SP[node] = cost;
    for (__typeof(bef[node].begin()) it = bef[node].begin();
         it != bef[node].end(); it++) {
      val[*it] += cost;
      val[*it] = min(val[*it], 314000000);
      if (!--in[*it] && SP[root[*it]] > val[*it]) {
        pq.push(make_pair(SP[root[*it]] = val[*it], root[*it]));
      }
    }
  }
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++)
    if (SP[i] == inf) h[i] = 1;
  for (int i = 1; i <= n; i++)
    if (!h[i] && !qa[i]) dfs(i);
  for (int i = 1; i <= n; i++) {
    if (SP[i] == inf) {
      printf("-1 -1\n");
      continue;
    }
    if (dp[i] == inf) dp[i] = -2;
    printf("%d %d\n", SP[i], dp[i]);
  }
}
