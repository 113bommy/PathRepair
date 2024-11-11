#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > g[300007];
vector<pair<pair<long long, long long>, long long> > edge[300007];
long long dist[300007], par[300007], visit[300007], e[300007], src[300007],
    dest[300007];
map<pair<long long, long long>, long long> ma;
void djikstra(long long s, long long n) {
  long long i;
  for (i = 1; i <= n; i++) {
    dist[i] = 999999999999999;
    visit[i] = 0;
  }
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      q;
  q.push(make_pair(0, s));
  dist[s] = 0;
  e[s] = 0;
  pair<long long, long long> top;
  long long u;
  while (!q.empty()) {
    top = q.top();
    q.pop();
    u = top.second;
    for (i = 0; i < g[u].size(); i++) {
      if (g[u][i].second + top.first < dist[g[u][i].first]) {
        dist[g[u][i].first] = g[u][i].second + top.first;
        e[g[u][i].first] = g[u][i].second;
        par[g[u][i].first] = u;
        q.push(make_pair(dist[g[u][i].first], g[u][i].first));
      } else if (g[u][i].second + top.first == dist[g[u][i].first]) {
        if (g[u][i].second < e[g[u][i].first]) {
          e[g[u][i].first] = g[u][i].second;
          par[g[u][i].first] = u;
        }
      }
    }
  }
}
int main() {
  long long n, m, i, x, y, w, s;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y >> w;
    g[x].push_back(make_pair(y, w));
    g[y].push_back(make_pair(x, w));
    src[i] = x;
    dest[i] = y;
  }
  for (i = 1; i <= n; i++) par[i] = i;
  cin >> s;
  djikstra(s, n);
  long long c = 0;
  for (i = 1; i <= n; i++) c += e[i];
  cout << c << endl;
  for (i = 1; i <= m; i++) {
    if (par[src[i]] == dest[i] || par[dest[i]] == src[i]) cout << i << " ";
  }
  return 0;
}
