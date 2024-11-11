#include <bits/stdc++.h>
using namespace std;
int n, m, cost[100005], ans = -1;
vector<pair<int, int> > G[100005];
map<int, int> T[100005];
map<int, int>::iterator it;
void dij() {
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      Q;
  int c = 0;
  if (T[1].begin() != T[1].end() && T[1].begin()->first == 0)
    c = T[1].begin()->second + 1;
  Q.push(make_pair(c, 1));
  cost[1] = c;
  while (!Q.empty()) {
    pair<int, int> cur, ch;
    cur = Q.top();
    Q.pop();
    if (cur.second == n) {
      if (ans == -1 || cur.first < ans) {
        ans = cur.first;
      }
      continue;
    }
    if (cost[cur.second] != -1 && cost[cur.second] != cur.first) continue;
    for (int i = 0; i < G[cur.second].size(); ++i) {
      ch = G[cur.second][i];
      int u = ch.first, c = ch.second + cur.first;
      it = T[u].lower_bound(c);
      if (it != T[u].end() && it->first == c)
        c = it->second + 1;
      else if (it != T[u].begin()) {
        it--;
        if (it->first <= c && it->second >= c) c = it->second + 1;
      }
      ch.second = u;
      ch.first = c;
      if (cost[u] == -1 || cost[u] > c) {
        cost[u] = c;
        Q.push(ch);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int t1, t2, t3;
    scanf("%d%d%d", &t1, &t2, &t3);
    G[t1].push_back(make_pair(t2, t3));
    G[t2].push_back(make_pair(t1, t3));
  }
  for (int i = 1; i < n; ++i) {
    int t;
    scanf("%d", &t);
    int prv = -5, st;
    while (t--) {
      int tt;
      scanf("%d", &tt);
      if (tt - 1 == prv)
        T[i][st] = tt;
      else {
        T[i][tt] = tt;
        st = tt;
      }
      prv = tt;
    }
  }
  memset(cost, -1, sizeof cost);
  dij();
  printf("%d\n", ans);
  return 0;
}
