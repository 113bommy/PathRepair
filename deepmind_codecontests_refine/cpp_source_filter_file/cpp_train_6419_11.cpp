#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
long long int dis[N];
vector<pair<long long int, long long int> > adj[N];
vector<pair<long long int, long long int> > adj2[N];
long long int maxdis[N];
long long int cost[N];
void di(long long int src) {
  for (long long int i = 1; i <= 100; i++) dis[i] = INT_MAX;
  set<pair<long long int, long long int> > s;
  dis[src] = 0;
  s.insert(make_pair(0, src));
  while (s.size()) {
    src = (s.begin())->second;
    long long int dist = (s.begin())->first;
    s.erase(s.begin());
    for (long long int i = 0; i < adj[src].size(); i++) {
      if (dis[adj[src][i].first] > dist + adj[src][i].second) {
        if (s.find(make_pair(dis[adj[src][i].first], adj[src][i].first)) !=
            s.end())
          s.erase(s.find(make_pair(dis[adj[src][i].first], adj[src][i].first)));
        dis[adj[src][i].first] = dist + adj[src][i].second;
        s.insert(make_pair(dis[adj[src][i].first], adj[src][i].first));
      }
    }
  }
}
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int src, des;
  cin >> src >> des;
  for (long long int i = 0; i < m; i++) {
    long long int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back(make_pair(y, w));
    adj[y].push_back(make_pair(x, w));
  }
  for (long long int i = 1; i <= n; i++) cin >> maxdis[i] >> cost[i];
  for (long long int i = 1; i <= n; i++) {
    di(i);
    for (long long int j = 1; j <= n; j++) {
      if (dis[j] <= maxdis[i]) adj2[i].push_back(make_pair(j, cost[i]));
    }
  }
  for (long long int i = 1; i <= n; i++) {
    adj[i].clear();
    for (long long int j = 0; j < adj2[i].size(); j++)
      adj[i].push_back(adj2[i][j]);
  }
  di(src);
  if (dis[des] == INT_MAX) dis[des] = -1;
  cout << dis[des] << endl;
}
