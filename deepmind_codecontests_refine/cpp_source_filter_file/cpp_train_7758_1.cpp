#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int s, t;
vector<pair<int, int> > data[50];
bool seen[50][50];
int flow[50][50];
vector<pair<int, int> > graph[50];
int l[50];
vector<pair<int, int> > lvl[50];
int ptr[50];
bool mklvl() {
  for (int i = 0; i < n; i++) lvl[i].clear();
  memset(l, -1, sizeof(l));
  queue<int> q;
  q.push(s);
  l[s] = 0;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (pair<int, int> e : graph[a]) {
      int b = e.first;
      if (e.second > flow[a][b]) {
        if (l[b] == -1) {
          l[b] = l[a] + 1;
          q.push(b);
        }
        if (l[b] > l[a]) lvl[a].push_back({b, e.second - flow[a][b]});
      }
    }
  }
  return l[t] != -1;
}
int dfs(int a, int f) {
  if (a == t) return f;
  while (ptr[a] < lvl[a].size()) {
    int b = lvl[a][ptr[a]].first;
    int ec = lvl[a][ptr[a]].second;
    int af = dfs(b, min(ec, f));
    if (af == -1)
      ptr[a]++;
    else {
      flow[a][b] += af;
      flow[b][a] -= af;
      if (af == ec)
        ptr[a]++;
      else
        lvl[a][ptr[a]] = {b, ec - af};
      return af;
    }
  }
  return -1;
}
int maxflow() {
  memset(flow, 0, sizeof(flow));
  while (mklvl()) {
    memset(ptr, 0, sizeof(ptr));
    while (dfs(s, INT_MAX) > 0)
      ;
  }
  int f = 0;
  for (int i = 0; i < n; i++) {
    f += flow[s][i];
  }
  return f;
}
void construct(double c) {
  for (int i = 0; i < n; i++) {
    graph[i].clear();
    for (pair<int, int> e : data[i]) {
      graph[i].push_back({e.first, floor(min(1e9, e.second / c))});
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    if (!seen[a][b]) data[a].push_back({b, c});
    if (!seen[b][a]) data[b].push_back({a, 0});
    seen[a][b] = true;
  }
  s = 0;
  t = n - 1;
  double hi = 1e9, lo = 0.0;
  while (hi - lo > 1e-9) {
    double mid = (hi + lo) / 2;
    construct(mid);
    if (maxflow() >= x) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  printf("%.7f\n", hi * x);
}
