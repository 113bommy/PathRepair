#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > E;
vector<vector<int> > edge;
vector<vector<pair<int, int> > > adjlist;
map<pair<int, int>, bool> check;
map<pair<int, int>, bool> id;
const int N = 3e5 + 5;
const long long INF = 1e15;
long long d[N];
int n, m, k, h[N], pa[N];
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
      if (d[v.first] > d[u] + v.second) {
        d[v.first] = d[u] + v.second;
        q.push(pair<int, int>(d[v.first], v.first));
      }
    }
  }
}
void process() {
  for (int u = 1; u <= n; ++u) {
    for (pair<int, int> v : adjlist[u]) {
      if (d[u] == d[v.first] + v.second &&
          check[pair<int, int>(min(v.first, u), max(v.first, u))] == 0) {
        edge[v.first].push_back(u);
        edge[u].push_back(v.first);
        check[pair<int, int>(min(v.first, u), max(v.first, u))] = 1;
        break;
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
  process();
  if (n - 1 <= k) {
    printf("%d\n", n - 1);
    for (int i = 0; i < m; ++i) {
      if (check[E[i]] == 1) printf("%d ", i + 1);
    }
  } else {
    int rem = n - 1 - k;
    dfs(1, 0);
    sort(how_sort.begin(), how_sort.end());
    for (int i = 0; i < k; ++i) {
      id[pair<int, int>(min(pa[how_sort[i].second], how_sort[i].second),
                        max(pa[how_sort[i].second], how_sort[i].second))] = 1;
    }
    printf("%d\n", k);
    for (int i = 0; i < m; ++i) {
      if (id[E[i]] == 1) printf("%d ", i + 1);
    }
  }
}
