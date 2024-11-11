#include <bits/stdc++.h>
using namespace std;
int V, E;
int cap[40000];
int cost[40000], dist[200], pot[200];
int to[40000], pre[40000], last[200], path[200];
bool used[200];
priority_queue<pair<int, int> > q;
void init(int n) {
  int i;
  V = n;
  E = 0;
  for (int i = 0; i < V; i++) last[i] = -1;
}
void add_edge(int x, int y, int w, int c) {
  cap[E] = w;
  cost[E] = c;
  to[E] = y;
  pre[E] = last[x];
  last[x] = E;
  E++;
  cap[E] = 0;
  cost[E] = -c;
  to[E] = x;
  pre[E] = last[y];
  last[y] = E;
  E++;
}
pair<int, int> search(int s, int t) {
  int ansf = 0;
  int ansc = 0;
  int i;
  for (int i = 0; i < V; i++) used[i] = false;
  for (int i = 0; i < V; i++) dist[i] = 1.0E+9;
  dist[s] = 0;
  path[s] = -1;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    if (used[x]) continue;
    used[x] = true;
    for (int e = last[x]; e >= 0; e = pre[e])
      if (cap[e] > 0) {
        int tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
        if (tmp < dist[to[e]] && !used[to[e]]) {
          dist[to[e]] = tmp;
          path[to[e]] = e;
          q.push(make_pair(-dist[to[e]], to[e]));
        }
      }
  }
  for (int i = 0; i < V; i++) pot[i] += dist[i];
  if (used[t]) {
    ansf = (1 << 29);
    for (int e = path[t]; e >= 0; e = path[to[e ^ 1]]) ansf = min(ansf, cap[e]);
    for (int e = path[t]; e >= 0; e = path[to[e ^ 1]]) {
      ansc += cost[e] * ansf;
      cap[e] -= ansf;
      cap[e ^ 1] += ansf;
    }
  }
  return make_pair(ansf, ansc);
}
pair<int, int> mincostflow(int s, int t) {
  int ansf = 0;
  int ansc = 0;
  int i;
  while (1) {
    pair<int, int> p = search(s, t);
    if (!used[t]) break;
    ansf += p.first;
    ansc += p.second;
  }
  return make_pair(ansf, ansc);
}
int mn[200], mx[200];
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    mn[i] = 1e9;
    mx[i] = -1;
  }
  for (int i = 0; i < q; i++) {
    int ty, l, r, v;
    cin >> ty >> l >> r >> v;
    for (int j = l; j <= r; j++) {
      if (ty == 1) {
        mx[j] = max(mx[j], v);
      } else {
        mn[j] = min(mn[j], v);
      }
    }
  }
  init(2 * n + 5);
  for (int i = 1; i <= n; i++)
    if (mx[i] > mn[i]) {
      puts("-1");
      return 0;
    }
  int src = 2 * n + 1;
  int snk = src + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) add_edge(src, i, 1, 2 * j - 1);
  for (int i = 1; i <= n; i++) {
    if (mn[i] == 1e9) mn[i] = n;
    if (mx[i] == -1) mx[i] = 1;
    for (int j = mx[i]; j <= mn[i]; j++) add_edge(j, i + n, 1, 0);
  }
  for (int i = 1; i <= n; i++) add_edge(i + n, snk, 1, 0);
  cout << mincostflow(src, snk).second << endl;
  return 0;
}
