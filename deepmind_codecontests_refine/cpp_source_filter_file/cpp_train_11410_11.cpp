#include <bits/stdc++.h>
using namespace std;
const int MX = 202020;
const long long INF = 102938475610293847LL;
vector<int> el[MX];
int V;
int ip[MX];
int RT;
pair<long long, long long> dfs(int v, int fa) {
  if (ip[v] <= 0) return make_pair(-INF, -INF);
  vector<pair<long long, long long> > ls;
  int sz = el[v].size();
  for (int i = 0; i < sz; i++) {
    int u = el[v][i];
    if (u == fa) continue;
    ls.push_back(dfs(u, v));
  }
  sort(ls.begin(), ls.end());
  reverse(ls.begin(), ls.end());
  int snz = ls.size();
  long long sm2 = 0;
  for (int i = 0; i < snz; i++) {
    sm2 += ls[i].second;
  }
  long long a1 = 1, a2 = ip[v] - 1;
  for (int i = 0; i < min(ip[v] - 1, snz); i++) {
    a1 += ls[i].first + 1;
    a2--;
  }
  long long k = min(a2, sm2);
  a1 += k;
  a2 -= k;
  return make_pair(a1, a2);
}
int main() {
  cin >> V;
  for (int i = 1; i <= V; i++) cin >> ip[i];
  for (int i = 0; i < V - 1; i++) {
    int u, v;
    cin >> u >> v;
    el[u].push_back(v);
    el[v].push_back(u);
  }
  cin >> RT;
  ip[RT]++;
  long long ans = dfs(RT, -1).first - 1;
  cout << ans << endl;
  return 0;
}
