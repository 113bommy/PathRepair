#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int n, m, q, depth[N], down[N], up[N], father[N];
vector<int> g[N];
int comp[N], diam[N];
vector<int> dist[N];
map<pair<int, int>, long long> memo;
struct sume_partiale {
  vector<long long> s;
  sume_partiale(const vector<int>& pe = {}) {
    s.resize(pe.size());
    for (int i = 0; i < pe.size(); ++i) {
      if (i) s[i] = s[i - 1];
      s[i] += pe[i];
    }
  }
  long long query(int i, int j) {
    if (i == 0) {
      return s[j];
    }
    return s[j] - s[i - 1];
  }
};
sume_partiale partiale[N];
void read() {
  cin >> n >> m >> q;
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
}
void dfsComp(int node, int colour) {
  comp[node] = colour;
  for (auto itr : g[node]) {
    if (!comp[itr]) {
      father[itr] = node;
      depth[itr] = depth[node] + 1;
      dfsComp(itr, colour);
    }
  }
}
void getTrees() {
  for (int i = 1, cnt = 0; i <= n; ++i) {
    if (!comp[i]) {
      dfsComp(i, ++cnt);
    }
  }
}
void dfsDown(int node) {
  for (auto it : g[node]) {
    if (it != father[node]) {
      dfsDown(it);
      down[node] = max(down[node], down[it] + 1);
    }
  }
}
void dfsUp(int node, int best = 0) {
  up[node] = depth[node] + best;
  int mx1 = 0, mx2 = 0, ind_best = 0;
  for (auto it : g[node]) {
    if (it == father[node]) continue;
    if (down[it] + 1 == down[node]) {
      ind_best = it;
    }
    if (down[it] + 1 > mx1) {
      mx2 = mx1;
      mx1 = down[it] + 1;
    } else if (down[it] + 1 > mx2)
      mx2 = down[it] + 1;
  }
  for (auto it : g[node]) {
    if (it == father[node]) continue;
    int value = 0;
    if (it == ind_best)
      value = max(best, -depth[node] + mx2);
    else
      value = max(best, -depth[node] + mx1);
    dfsUp(it, value);
  }
}
void build_down_and_up() {
  for (int i = 1; i <= n; ++i)
    if (!father[i]) dfsDown(i);
  for (int i = 1; i <= n; ++i)
    if (!father[i]) dfsUp(i);
  for (int i = 1; i <= n; ++i) {
    dist[comp[i]].push_back(max(up[i], down[i]));
    diam[comp[i]] = max(diam[comp[i]], max(up[i], down[i]));
  }
  for (int i = 1; i <= n; ++i)
    if (!dist[i].empty()) {
      sort(dist[i].begin(), dist[i].end());
      partiale[i] = sume_partiale(dist[i]);
    }
}
long long fast_query(int a, int b) {
  long long sum = 0;
  if (dist[a].size() > dist[b].size()) {
    swap(a, b);
  }
  if (memo.find(make_pair(a, b)) != end(memo)) return memo[make_pair(a, b)];
  long long x = max(diam[a], diam[b]);
  for (auto it : dist[a]) {
    int st(0), dr(dist[b].size() - 1), pos = -1, mid;
    while (st <= dr) {
      mid = (st + dr) / 2;
      if (dist[b][mid] + it + 1 <= x)
        st = mid + 1, pos = mid;
      else
        dr = mid - 1;
    }
    sum += x * (pos + 1);
    ++pos;
    if (pos < dist[b].size())
      sum += (1LL * it + 1) * (1LL * dist[b].size() - pos) +
             partiale[b].query(pos, dist[b].size() - 1);
  }
  return memo[{a, b}] = sum;
}
void answerQueries() {
  while (q--) {
    int a, b;
    cin >> a >> b;
    a = comp[a];
    b = comp[b];
    if (a == b) {
      cout << -1 << '\n';
      continue;
    }
    long long DivBy = dist[a].size() * dist[b].size();
    cout << fixed << setprecision(7) << (1.0 * fast_query(a, b) / DivBy)
         << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  read();
  getTrees();
  build_down_and_up();
  answerQueries();
  return 0;
}
