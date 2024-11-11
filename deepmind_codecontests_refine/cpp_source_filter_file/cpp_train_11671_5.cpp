#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
inline bool upmax(T1& a, T2 b) {
  return (a < b ? (a = b, true) : false);
}
template <typename T1, typename T2>
inline bool upmin(T1& a, T2 b) {
  return (b < a ? (a = b, true) : false);
}
const int maxn = (int)1e6 + 20;
const int maxlog = 21;
const int base = (int)1e9 + 9;
const long double eps = (long double)1e-7;
const long double PI = acos(-1.);
const int pp = 41;
const int INF = 1000000000;
struct Edge {
  int a, b, cap, flow;
};
struct MaxFlow {
  int n, s, t;
  vector<int> d, ptr, q;
  vector<Edge> e;
  vector<vector<int> > g;
  MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n) {
    e.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
      ptr[i] = 0;
    }
  }
  void addEdge(int a, int b, int cap) {
    Edge e1 = {a, b, cap, 0};
    Edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
  }
  int getMaxFlow(int _s, int _t) {
    s = _s;
    t = _t;
    int flow = 0;
    for (;;) {
      if (!bfs()) break;
      for (int i = 0; i < n; i++) ptr[i] = 0;
      while (int pushed = dfs(s, INF)) flow += pushed;
    }
    return flow;
  }
  void print(std::ostream& os) {
    for (auto& t : e) {
      os << t.a << " " << t.b << "\n";
    }
  }
  int getAns(int v) {
    for (int i = 0; i < g[v].size(); i++) {
      int id = g[v][i], to = e[id].b;
      int flow = e[id].flow;
      if (!(id & 1) && to == t && !flow) {
        return -1;
      }
      if (id & 1) {
        flow = e[id ^ 1].flow;
        if (flow) {
          e[id ^ 1].flow--;
          e[id].flow++;
          if (to == s) return v;
          return getAns(to);
        }
      } else
        continue;
    }
    return -1;
  }

 private:
  bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    for (int i = 0; i < n; i++) d[i] = -1;
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
      int v = q[qh++];
      for (int i = 0; i < g[v].size(); i++) {
        int id = g[v][i], to = e[id].b;
        if (d[to] == -1 && e[id].flow < e[id].cap) {
          q[qt++] = to;
          d[to] = d[v] + 1;
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int v, int flow) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
      int id = g[v][ptr[v]], to = e[id].b;
      if (d[to] != d[v] + 1) continue;
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
};
int n, m;
vector<pair<int, int> > e;
int N = 0;
int bld(int v, int l, int r) {
  if (l == r) return l + n;
  int mid = (l + r) >> 1;
  e.emplace_back(v + m + n, bld(v + v, l, mid));
  e.emplace_back(v + m + n, bld(v + v + 1, mid + 1, r));
  upmax(N, v + n + m);
  return v + m + n;
}
void upd(int v, int tl, int tr, int l, int r, vector<int>& vs) {
  if (tl == l && tr == r) {
    if (l == r)
      vs.push_back(l + n);
    else
      vs.push_back(v + n + m);
  } else {
    int m = (tl + tr) >> 1;
    if (l <= m) upd(v + v, tl, m, l, min(r, m), vs);
    if (r > m) upd(v + v + 1, m + 1, tr, max(l, m + 1), r, vs);
  }
}
bool used[maxn];
int a[maxn][3];
int kil[maxn];
int cnt[maxn];
int main() {
  scanf("%d%d", &n, &m);
  bld(1, 1, m);
  N += 2;
  int S = 0, T = N - 1;
  MaxFlow flow(N);
  for (auto t : e) {
    int a, b;
    tie(a, b) = t;
    flow.addEdge(a, b, INF);
  }
  for (int i = 1; i <= m; i++) {
    flow.addEdge(i + n, T, 1);
  }
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    if (t == 0) {
      int k;
      scanf("%d", &k);
      flow.addEdge(S, i, 1);
      while (k--) {
        int a;
        scanf("%d", &a);
        flow.addEdge(i, a + n, 1);
      }
    } else if (t == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      vector<int> a;
      upd(1, 1, m, l, r, a);
      flow.addEdge(S, i, 1);
      for (int v : a) {
        flow.addEdge(i, v, 1);
      }
    } else {
      for (int j = 0; j < 3; j++) {
        scanf("%d", &a[i][j]);
        flow.addEdge(i, a[i][j] + n, 1);
      }
      used[i] = true;
      flow.addEdge(S, i, 2);
    }
  }
  cout << flow.getMaxFlow(S, T) << "\n";
  for (int i = 1; i <= m; i++) {
    int pred = flow.getAns(i + n);
    kil[i] = pred;
    if (pred == -1) continue;
    cnt[pred]++;
  }
  for (int i = 1; i <= m; i++) {
    if (!used[i]) continue;
    if (cnt[i] == 0 || cnt[i] == 2) continue;
    assert(cnt[i] == 1);
    for (int j = 0; j < 3; j++) {
      if (kil[a[i][j]] != i) {
        cnt[kil[a[i][j]]]--;
        kil[a[i][j]] = i;
        cnt[i]++;
        break;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (kil[i] != -1) {
      cout << kil[i] << " " << i << "\n";
    }
  }
  return 0;
}
