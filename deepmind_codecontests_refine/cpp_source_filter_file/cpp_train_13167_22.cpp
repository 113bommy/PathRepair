#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[300000 + 1000];
long long dist[300000 + 1000], from[300000 + 1000];
long long mindist[300000 + 1000];
bool vis[300000 + 1000];
map<pair<int, int>, pair<int, long long> > bcc;
int main() {
  long long int n, m, source;
  long long int x, y;
  long long weight;
  vector<pair<long long int, pair<long long int, long long> > > edge;
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    cin >> x >> y >> weight;
    adj[x].push_back(y);
    adj[y].push_back(x);
    edge.push_back(make_pair(x, make_pair(y, weight)));
    bcc[make_pair(x, y)] = make_pair(i, weight);
    bcc[make_pair(y, x)] = make_pair(i, weight);
  }
  for (int i = 0; i <= n; i++) {
    dist[i] = LONG_MAX;
    mindist[i] = LONG_MAX;
  }
  long long int cnt = 0LL;
  priority_queue<pair<long long, long long int>,
                 vector<pair<long long, long long int> >,
                 greater<pair<long long, long long int> > >
      pq;
  cin >> source;
  dist[source] = 0;
  from[source] = source;
  bcc[make_pair(source, source)] = make_pair(0, 0LL);
  vector<long long int> answ;
  for (long long int i = 0; i < (long long int)adj[source].size(); i++) {
    long long int dest = adj[source][i];
    long long weit = bcc[make_pair(source, dest)].second;
    if (dist[source] + weit < dist[dest]) {
      dist[dest] = dist[source] + weit;
      from[dest] = source;
      pq.push(make_pair(dist[dest], dest));
    }
  }
  cnt = 0;
  while (pq.empty() == 0) {
    pair<long long int, long long int> topp = pq.top();
    pq.pop();
    cnt++;
    int source, dest;
    long long weit;
    source = topp.second;
    for (long long int i = 0; i < (long long int)adj[source].size(); i++) {
      dest = adj[source][i];
      weit = bcc[make_pair(source, dest)].second;
      if (dist[source] + weit < dist[dest]) {
        dist[dest] = dist[source] + weit;
        from[dest] = source;
        pq.push(make_pair(dist[dest], dest));
        mindist[dest] = weit;
      } else if (dist[source] + weit == dist[dest] && mindist[dest] > weit) {
        dist[dest] = dist[source] + weit;
        from[dest] = source;
        mindist[dest] = weit;
      }
    }
  }
  long long cost = 0;
  for (long long int i = 1; i <= n; i++) {
    if (i != source) {
      answ.push_back(bcc[make_pair(i, from[i])].first);
      cost += bcc[make_pair(i, from[i])].second;
    }
  }
  cout << cost << "\n";
  for (long long int i = 0; i < (long long int)edge.size(); i++) {
    int u, v;
    u = edge[i].first;
    v = edge[i].second.first;
    if (from[u] == v || from[v] == u) {
      cout << i + 1LL << " ";
    }
  }
  return 0;
}
