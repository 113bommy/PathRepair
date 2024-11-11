#include <bits/stdc++.h>
using namespace std;
int N, M, X;
vector<vector<pair<int, long long>>> G;
long double scale;
const long long INF = 1e18;
vector<vector<long long>> cap;
vector<long long> level, ptr;
bool mf_bfs(long long s, long long t) {
  queue<long long> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    long long v = q.front();
    q.pop();
    for (auto p : G[v]) {
      long long u = p.first;
      if (cap[v][u] > 0 && level[u] == -1) {
        level[u] = level[v] + 1;
        q.push(u);
      }
    }
  }
  return level[t] != -1;
}
long long mf_dfs(long long v, long long pushed, long long t) {
  if (pushed == 0) return 0;
  if (v == t) return pushed;
  for (long long& cid = ptr[v]; cid < (long long)G[v].size(); cid++) {
    long long u = G[v][cid].first;
    if (level[v] + 1 != level[u] || cap[v][u] < 1) continue;
    long long tr = mf_dfs(u, min(pushed, cap[v][u]), t);
    if (tr == 0) continue;
    cap[v][u] -= tr;
    cap[u][v] += tr;
    return tr;
  }
  return 0;
}
long long maxflow(long long s, long long t) {
  long long N = G.size();
  level.resize(N);
  ptr.resize(N);
  cap = vector<vector<long long>>(N, vector<long long>(N));
  cap[0][1] = X;
  for (long long i = 1; i < N; i++) {
    for (auto p : G[i]) {
      cap[i][p.first] += (long long)(((long double)p.second) / scale);
    }
  }
  long long f = 0;
  while (true) {
    fill(level.begin(), level.end(), -1);
    if (!mf_bfs(s, t)) break;
    fill(ptr.begin(), ptr.end(), 0);
    while (long long pushed = mf_dfs(s, INF, t)) {
      f += pushed;
    }
  }
  return f;
}
long double error(long double a, long double b) {
  return abs(a - b) / max((long double)1.0, b);
}
int main() {
  cin >> N >> M >> X;
  G.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    G[b].push_back({a, 0});
  }
  G[0].push_back({1, X});
  G[1].push_back({0, 0});
  long double l = 1e-7, r = 2000000;
  while (error(l, r) > 1e-10) {
    scale = (l + r) / 2;
    long long fl = maxflow(0, N);
    if (fl == X) {
      l = scale;
    } else {
      r = scale;
    }
  }
  cout << setprecision(20) << fixed << l * X << endl;
  return 0;
}
