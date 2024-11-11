#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int N = 1e6 + 5, M = 240, MAX = 10, T = 3e4, INF = 1e9;
int d[N], w[T], dist[300][M + 5];
vector<int> h[T], pr;
vector<vector<int>> v;
map<vector<int>, int> mp;
int cnt = 0;
vector<int> path;
void f(int max, int prod, int ct) {
  v.push_back(path);
  pr.push_back(prod);
  mp[path] = cnt++;
  if (ct == MAX) return;
  for (int i = 2; i <= max; i++) {
    if (prod * i <= M) {
      path.push_back(i);
      f(i, prod * i, ct + 1);
      path.pop_back();
    }
  }
}
vector<int> getV(int a) {
  vector<int> g;
  while (a > 1) {
    int x = 0, y = d[a];
    while (d[a] == y) {
      a /= d[a];
      x++;
    }
    g.push_back(x + 1);
  }
  sort(g.rbegin(), g.rend());
  return g;
}
int main() {
  f(M, 1, 0);
  map<vector<int>, int> g;
  for (int i = 2; i < N; i++) {
    if (!d[i]) {
      d[i] = i;
      for (long long int j = i * (long long int)i; j < N; j += i) {
        if (!d[j]) d[j] = i;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    vector<int> t = getV(i);
    if (!g.count(t)) {
      int x = g.size();
      g[t] = x;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    vector<int> &c = v[i];
    for (int j = 0; j < c.size(); j++) {
      if (j == 0 || c[j - 1] != c[j]) {
        c[j]++;
        if (mp.count(c)) {
          h[i].push_back(mp[c]);
          h[mp[c]].push_back(i);
        }
        c[j]--;
      }
    }
    if (c.size() < MAX) {
      c.push_back(2);
      if (mp.count(c)) {
        h[i].push_back(mp[c]);
        h[mp[c]].push_back(i);
      }
      c.pop_back();
    }
  }
  for (int i = 0; i < 300; i++) {
    for (int j = 0; j <= M; j++) {
      dist[i][j] = INF;
    }
  }
  for (auto &p : g) {
    fill(w, w + T, -1);
    queue<int> q;
    w[mp[p.first]] = 0;
    q.push(mp[p.first]);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (int to : h[node]) {
        if (w[to] == -1) {
          w[to] = w[node] + 1;
          q.push(to);
        }
      }
    }
    for (int j = 0; j < v.size(); j++) {
      dist[p.second][pr[j]] = min(dist[p.second][pr[j]], w[j]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a = g[getV(a)];
    b = g[getV(b)];
    int ans = INF;
    for (int i = 0; i <= M; i++) ans = min(ans, dist[a][i] + dist[b][i]);
    printf("%d\n", ans);
  }
  return 0;
}
