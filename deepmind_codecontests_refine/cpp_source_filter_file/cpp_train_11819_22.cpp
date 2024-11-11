#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
template <typename T>
void chmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void chmax(T &a, const T &b) {
  a = max(a, b);
}
struct FastIO {
  FastIO() {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
} fastiofastio;
const ll INF = 1LL << 60;
template <class T>
struct dinic {
  struct edge {
    int to;
    T cap;
    int rev;
    bool isrev;
  };
  vector<vector<edge>> G;
  vector<int> level, iter;
  void bfs(int s) {
    level.assign(G.size(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (que.size()) {
      int v = que.front();
      que.pop();
      for (auto i : G[v]) {
        if (i.cap > 0 && level[i.to] < 0) {
          level[i.to] = level[v] + 1;
          que.push(i.to);
        }
      }
    }
  }
  T dfs(int v, const int t, T f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < (ll)G[v].size(); ++i) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        T d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  dinic() {}
  dinic(int n) : G(n), level(n), iter(n) {}
  void add_edge(int from, int to, T cap) {
    G[from].push_back({to, cap, (int)G[to].size(), false});
    G[to].push_back({from, 0, (int)G[from].size() - 1, true});
  }
  T max_flow(int s, int t) {
    T flow = 0;
    while (1) {
      bfs(s);
      if (level[t] < 0) return flow;
      iter.assign(G.size(), 0);
      T f;
      while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
  }
  friend ostream &operator<<(ostream &out, const dinic &a) {
    out << endl;
    for (int i = 0; i < (int)a.G.size(); i++) {
      for (auto &e : a.G[i]) {
        if (e.isrev) continue;
        auto &rev_e = a.G[e.to][e.rev];
        out << i << "->" << e.to << " (flow: " << rev_e.cap << "/"
            << e.cap + rev_e.cap << ")" << endl;
      }
    }
    return out;
  }
};
int main(void) {
  ll n, b, q;
  cin >> n >> b >> q;
  vector<PII> p(q + 1);
  for (ll i = (ll)0; i < (ll)q; ++i) cin >> p[i].first >> p[i].second;
  p[q] = PII(b, n);
  sort(p.begin(), p.end());
  ;
  vector<ll> a(q + 1), x(q + 1);
  for (ll i = (ll)0; i < (ll)q + 1; ++i) {
    a[i] = p[i].first;
    x[i] = p[i].second - (i == 0 ? 0 : p[i - 1].second);
    if (x[i] < 0 || a[i] - (i == 0 ? 0 : a[i - 1]) < x[i]) {
      cout << "unfair" << endl;
      return 0;
    }
  };
  ;
  dinic<ll> flow(q + 1 + 5 + 2);
  ll s = q + 1 + 5, t = q + 1 + 5 + 1;
  for (ll i = (ll)0; i < (ll)q + 1; ++i) flow.add_edge(s, i, x[i]);
  for (ll i = (ll)0; i < (ll)5; ++i) flow.add_edge(q + i, t, n / 5);
  for (ll i = (ll)0; i < (ll)q + 1; ++i) {
    ll lb = (i == 0 ? 0 : a[i - 1]) + 1, ub = a[i];
    vector<ll> num(5);
    for (ll j = (ll)lb; j < (ll)ub + 1; ++j) num[j % 5]++;
    for (ll j = (ll)0; j < (ll)5; ++j) {
      ;
      flow.add_edge(i, q + j, num[j]);
    }
  }
  if (flow.max_flow(s, t) == n)
    cout << "fair" << endl;
  else
    cout << "unfair" << endl;
  ;
  return 0;
}
