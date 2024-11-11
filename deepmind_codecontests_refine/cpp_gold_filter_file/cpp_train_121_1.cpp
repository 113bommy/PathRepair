#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long B = 1e15;
long long dis[300009];
vector<pair<int, int> > adj[300009];
pair<pair<int, int>, int> arr[300009];
long long ans[300009];
int ata[300009];
set<int> s[300009];
int tap(int x) {
  if (ata[x] == x) return x;
  return ata[x] = tap(ata[x]);
}
void merge(int x, int y, long long w) {
  if ((x = tap(x)) == (y = tap(y))) return;
  if (s[x].size() < s[y].size()) swap(x, y);
  for (__typeof((s[y]).begin()) it = (s[y]).begin(); it != (s[y]).end(); it++) {
    if (s[x].count(*it))
      ans[*it] = w;
    else
      s[x].insert(*it);
  }
  s[y].clear();
  ata[y] = x;
}
int main() {
  int n, m, k, qr;
  scanf("%d%d%d%d", &n, &m, &k, &qr);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    arr[i] = make_pair(make_pair(u, v), w);
  }
  for (int i = 1; i <= qr; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    s[u].insert(i);
    s[v].insert(i);
  }
  queue<int> q;
  for (int i = 1; i <= k; i++) q.push(i);
  for (int i = k + 1; i <= n; i++) dis[i] = B;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    for (__typeof((adj[nd]).begin()) it = (adj[nd]).begin();
         it != (adj[nd]).end(); it++)
      if (umin(dis[it->first], dis[nd] + it->second)) q.push(it->first);
  }
  vector<pair<long long, pair<int, int> > > edge;
  for (int i = 1; i <= m; i++) {
    int u = arr[i].first.first, v = arr[i].first.second, w = arr[i].second;
    edge.push_back(make_pair(w + dis[u] + dis[v], make_pair(u, v)));
  }
  sort(edge.begin(), edge.end());
  for (int i = 1; i <= n; i++) ata[i] = i;
  for (__typeof((edge).begin()) it = (edge).begin(); it != (edge).end(); it++)
    merge(it->second.first, it->second.second, it->first);
  for (int i = 1; i <= qr; i++) printf("%lld\n", ans[i]);
  return 0;
}
