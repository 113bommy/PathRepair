#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int INF = INT32_MAX;
constexpr int MAXN = 2e6 + 10;
constexpr double eps = 1e-8;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using Tri = tuple<int, int, int>;
using Vec = vector<int>;
template <class T>
void Min(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void Max(T &a, T b) {
  if (b > a) a = b;
}
ll N, M, K, T;
vector<Vec> gph;
vector<bool> seen;
vector<int> sz, dist;
vector<Tri> ans;
void FindCentroid(int u, int &c) {
  seen[u] = true;
  sz[u] = 1;
  int ma = 0;
  for (int v : gph[u]) {
    if (!seen[v]) {
      FindCentroid(v, c);
      ma = max(ma, sz[v]);
      sz[u] += sz[v];
    }
  }
  if (ma <= N / 2 && (N - sz[u]) <= N / 2) c = u;
}
struct Grp {
  int tot;
  Vec nodes;
  Grp(int node) {
    tot = sz[node];
    nodes.emplace_back(node);
  }
  bool operator<(const Grp &rhs) const { return tot > rhs.tot; }
  void Join(const Grp &rhs) {
    tot += rhs.tot;
    for (int n : rhs.nodes) {
      nodes.emplace_back(n);
    }
  }
};
void FindAns(int cen, const Grp &g, int st, int step) {
  queue<Pii> que;
  for (int c : g.nodes) {
    que.emplace(cen, c);
    seen[c] = true;
  }
  while (!que.empty()) {
    auto e = que.front();
    que.pop();
    dist[e.second] = st;
    ans.emplace_back(e.first, e.second, st - dist[e.first]);
    st += step;
    for (int v : gph[e.second]) {
      if (!seen[v]) {
        seen[v] = true;
        que.emplace(e.second, v);
      }
    }
  }
}
void Solution() {
  if (N == 1) return;
  if (N == 2) {
    cout << "1 2 1\n";
    return;
  }
  seen.assign(N + 1, false);
  sz.assign(N + 1, 0);
  int cen = 1;
  FindCentroid(1, cen);
  seen.assign(N + 1, false);
  sz.assign(N + 1, 0);
  int tmp;
  FindCentroid(cen, tmp);
  priority_queue<Grp> pq;
  for (int v : gph[cen]) {
    pq.emplace(v);
  }
  while (pq.size() > 2) {
    auto a = pq.top();
    pq.pop();
    auto b = pq.top();
    pq.pop();
    b.Join(a);
    pq.emplace(b);
  }
  auto a = pq.top();
  pq.pop();
  auto b = pq.top();
  pq.pop();
  seen.assign(N + 1, false);
  dist.assign(N + 1, 0);
  seen[cen] = true;
  FindAns(cen, a, 1, 1);
  FindAns(cen, b, a.tot + 1, a.tot + 1);
  for (auto &t : ans) {
    cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N) {
    gph.assign(N + 1, Vec());
    int u, v;
    for (int i = (int)(0); i < (int)(N - 1); ++i) {
      cin >> u >> v;
      gph[u].emplace_back(v);
      gph[v].emplace_back(u);
    }
    Solution();
  }
  return 0;
}
