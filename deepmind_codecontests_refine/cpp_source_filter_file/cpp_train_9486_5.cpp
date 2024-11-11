#include <bits/stdc++.h>
using namespace std;
struct comp {
  bool operator()(const pair<long long, long long>& a,
                  const pair<long long, long long>& b) {
    return a.second > b.second;
  }
};
vector<pair<long long, long long> > edge;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               comp>
    Q;
vector<pair<long long, long long> > edg[500005];
vector<long long> ed[500005];
long long id[500005];
long long dis[500005];
long long par[500005];
long long k;
bool vis[500005];
map<pair<long long, long long>, long long> pos;
vector<long long> BFS(long long s, long long k) {
  memset(vis, false, sizeof vis);
  queue<long long> Q;
  Q.push(s);
  vis[s] = true;
  vector<long long> v;
  while (!Q.empty() and k) {
    long long u = Q.front();
    Q.pop();
    long long n = ed[u].size(), i;
    for (i = 1; i <= n; i++) {
      if (vis[ed[u][i - 1]] or !k) continue;
      vis[ed[u][i - 1]] = true;
      if (u != ed[u][i - 1])
        ;
      v.push_back(pos[{u, ed[u][i - 1]}]);
      k--;
      Q.push(ed[u][i - 1]);
    }
  }
  return v;
}
int main() {
  long long n, m, a, b, c, t, i, j, beg;
  string s;
  cin >> n >> m >> k;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    edg[a].push_back(make_pair(b, c));
    edg[b].push_back(make_pair(a, c));
    pos[{a, b}] = i + 1;
    pos[{b, a}] = i + 1;
  }
  m = k;
  beg = 1;
  for (i = 1; i <= n; i++) par[1] = 1, dis[i] = 10000000000000, vis[i] = false;
  dis[beg] = 0;
  Q.push(make_pair(beg, 0));
  while (!Q.empty()) {
    long long a = Q.top().first;
    Q.pop();
    if (vis[a]) continue;
    k = edg[a].size();
    for (i = 1; i <= k; i++) {
      b = edg[a][i - 1].first;
      c = edg[a][i - 1].second;
      if (!vis[b] && dis[b] > dis[a] + c) {
        dis[b] = dis[a] + c;
        par[b] = a;
        Q.push(make_pair(b, dis[b]));
      }
    }
    vis[a] = true;
  }
  for (i = 2; i <= n; i++) {
    b = i, a = par[i];
    if (pos[{a, b}] == 0) {
      cout << a << ' ' << b << endl;
      cout << "FUCK you";
      return 0;
    }
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  vector<long long> res = BFS(1, m);
  cout << res.size() << endl;
  for (i = 0; i < res.size(); i++) cout << res[i] << ' ';
  return 0;
}
