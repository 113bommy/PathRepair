#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 3e5 + 5;
int vis[N], n, m, s, id, a, b;
char mx[N], mn[N];
vector<pair<int, pair<int, int>>> adj[N];
void getMax() {
  vis[s] = 1;
  queue<int> q;
  q.push(s);
  fill(mx, mx + id, '?');
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto e : adj[u]) {
      int v = e.first;
      int x = e.second.first;
      int f = e.second.second;
      if (x < n && mx[x] != '?') continue;
      mx[x] = f ? '+' : '-';
      if (vis[v]) continue;
      vis[v] = 1;
      q.push(v);
    }
  }
  a = count(vis, vis + 1 + n, 1);
}
void getMin() {
  vis[s] = 2;
  queue<int> q;
  q.push(s);
  fill(mn, mn + id, '?');
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto e : adj[u]) {
      int v = e.first;
      int x = e.second.first;
      int f = e.second.second;
      if (x < n && mn[x] == '?') {
        mn[x] = f ? '-' : '+';
        continue;
      }
      if (vis[v] == 2) continue;
      vis[v] = 2;
      q.push(v);
    }
  }
  b = count(vis, vis + 1 + n, 2);
}
int main() {
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    if (t == 1)
      adj[u].push_back({v, {n, 0}});
    else {
      adj[u].push_back({v, {id, 1}});
      adj[v].push_back({u, {id++, 0}});
    }
  }
  getMax();
  getMin();
  for (int i = 0; i < id; i++) {
    if (mx[i] == '?') mx[i] = '+';
    if (mn[i] == '?') mn[i] = '+';
  }
  mn[id] = mx[id] = '\0';
  printf("%d\n%s\n%d\n%s", a, mx, b, mn);
  return 0;
}
