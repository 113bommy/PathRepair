#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
int cnt;
int tn, tin[N], tout[N], answer[N], cover[N << 2], seg[N << 2];
vector<int> adj[N];
vector<pair<int, int>> queries[N];
int query(int id, int f, int t, int qf, int qt) {
  if (seg[id] > 0) return min(qt, t) - max(qf, f) + 1;
  if (qf <= f && t <= qt) return cover[id];
  int m = (f + t) / 2;
  if (qt < m + 1) return query(id << 1, f, m, qf, qt);
  if (qf > m) return query(id << 1 | 1, m + 1, t, qf, qt);
  return query(id << 1, f, m, qf, qt) + query(id << 1 | 1, m + 1, t, qf, qt);
}
void update(int id, int f, int t, int qf, int qt, int v) {
  if (qf <= f && t <= qt) {
    seg[id] += v;
  } else {
    int m = (f + t) / 2;
    if (qf < m + 1) update(id << 1, f, m, qf, qt, v);
    if (qt > m) update(id << 1 | 1, m + 1, t, qf, qt, v);
  }
  if (seg[id] > 0) {
    cover[id] = t - f + 1;
  } else if (f < t) {
    cover[id] = cover[id << 1] + cover[id << 1 | 1];
  } else {
    cover[id] = 0;
  }
}
void dfs(int u, int p) {
  tin[u] = ++tn;
  for (int v : adj[u])
    if (v != p) dfs(v, u);
  tout[u] = tn;
}
void add(int f, int t) {
  int v = query(1, 1, tn, f, t);
  cnt += (t - f + 1) - v;
  update(1, 1, tn, f, t, 1);
}
void rem(int f, int t) {
  update(1, 1, tn, f, t, -1);
  int v = query(1, 1, tn, f, t);
  cnt -= (t - f + 1) - v;
}
void dfs_solve(int u, int p) {
  int old = cnt;
  for (auto q : queries[u]) {
    add(tin[q.first], tout[q.first]);
    add(tin[q.second], tout[q.second]);
  }
  if (cnt > 0) {
    answer[u] = cnt - 1;
  }
  for (int v : adj[u])
    if (v != p) dfs_solve(v, u);
  for (auto q : queries[u]) {
    rem(tin[q.first], tout[q.first]);
    rem(tin[q.second], tout[q.second]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    queries[u].push_back(make_pair(u, v));
    queries[v].push_back(make_pair(u, v));
  }
  dfs_solve(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << answer[i] << ' ';
  }
}
