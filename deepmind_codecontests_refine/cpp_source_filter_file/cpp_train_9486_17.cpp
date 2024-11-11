#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > E;
vector<vector<int> > edge;
vector<vector<pair<int, int> > > adjlist;
map<pair<int, int>, bool> check;
const int N = 3e5 + 5;
const long long INF = 1e15;
long long d[N];
int n, m, k, h[N], pa[N], lst[N];
vector<pair<int, int> > how_sort;
void dijkstra() {
  for (int i = 1; i <= n; ++i) d[i] = INF;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  d[1] = 0;
  q.push(pair<int, int>(0, 1));
  while (!q.empty()) {
    int u = q.top().second;
    long long dist = q.top().first;
    q.pop();
    if (d[u] != dist) continue;
    for (pair<int, int> v : adjlist[u]) {
      if (v.first == lst[u]) continue;
      if (d[v.first] > d[u] + v.second) {
        d[v.first] = d[u] + v.second;
        lst[v.first] = u;
        q.push(pair<int, int>(d[v.first], v.first));
      } else {
        check[pair<int, int>(min(u, v.first), max(u, v.first))] = 1;
      }
    }
  }
}
void dfs(int u, int p) {
  for (int v : edge[u]) {
    if (v == p) continue;
    h[v] = h[u] + 1;
    how_sort.push_back(pair<int, int>(h[v], v));
    pa[v] = u;
    dfs(v, u);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  adjlist.assign(n + 1, vector<pair<int, int> >());
  edge.assign(n + 1, vector<int>());
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adjlist[u].push_back(pair<int, int>(v, c));
    adjlist[v].push_back(pair<int, int>(u, c));
    E.push_back(pair<int, int>(min(u, v), max(u, v)));
  }
  dijkstra();
  for (int i = 0; i < m; ++i) {
    if (check.count(E[i]))
      continue;
    else {
      edge[E[i].first].push_back(E[i].second);
      edge[E[i].second].push_back(E[i].first);
    }
  }
  if (n - 1 <= k) {
    printf("%d\n", n - 1);
    for (int i = 0; i < m; ++i) {
      if (check[E[i]] == 1)
        continue;
      else
        printf("%d ", i + 1);
    }
  } else {
    int rem = n - 1 - k;
    dfs(1, 0);
    sort(how_sort.begin(), how_sort.end());
    reverse(how_sort.begin(), how_sort.end());
    for (int i = 0; i < rem; ++i) {
      check[pair<int, int>(min(pa[how_sort[i].second], how_sort[i].second),
                           max(pa[how_sort[i].second], how_sort[i].second))] =
          1;
    }
    printf("%d\n", k);
    for (int i = 0; i < m; ++i) {
      if (check[E[i]] == 1)
        continue;
      else
        printf("%d ", i + 1);
    }
  }
}
