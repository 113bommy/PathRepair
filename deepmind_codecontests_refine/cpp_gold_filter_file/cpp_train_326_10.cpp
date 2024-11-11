#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) {
    a = b;
  }
}
const long long INF = 1e15;
namespace Dinic {
const long long N = 100 * 1000 + 228;
struct edge {
  long long from, to, cap, flow;
  long long rem() { return cap - flow; }
  edge() {}
  edge(long long _from, long long _to, long long _cap, long long _flow) {
    from = _from;
    to = _to;
    cap = _cap;
    flow = _flow;
  }
};
long long n;
vector<long long> g[N];
long long fir[N], d[N];
vector<edge> e;
long long F = 0;
void add_edge(long long u, long long v, long long c) {
  g[u].push_back((long long)e.size());
  e.push_back(edge(u, v, c, 0LL));
  g[v].push_back((long long)e.size());
  e.push_back(edge(v, u, 0LL, 0LL));
}
bool bfs(long long s, long long t) {
  for (long long i = 1; i <= n; ++i) d[i] = INF;
  d[s] = 0;
  vector<long long> q;
  q.push_back(s);
  for (long long i = 0; i < (long long)q.size(); ++i) {
    long long v = q[i];
    for (long long num : g[v]) {
      long long to = e[num].to;
      if (e[num].rem() && d[v] + 1 < d[to]) {
        d[to] = d[v] + 1;
        q.push_back(to);
      }
    }
  }
  return d[t] != INF;
}
long long dfs(long long v, long long t, long long c = INF) {
  if (v == t) {
    F += c;
    return c;
  }
  for (; fir[v] < (long long)g[v].size(); ++fir[v]) {
    long long i = g[v][fir[v]];
    long long to = e[i].to;
    if (d[v] + 1 == d[to] && e[i].rem()) {
      long long x = dfs(to, t, min(c, e[i].rem()));
      if (x) {
        e[i].flow += x;
        e[i ^ 1].flow -= x;
        return x;
      }
    }
  }
  return 0;
}
long long max_flow(long long s, long long t) {
  F = 0;
  while (bfs(s, t)) {
    for (long long i = 1; i <= n; ++i) fir[i] = 0;
    while (dfs(s, t))
      ;
  }
  return F;
}
};  // namespace Dinic
const long long N = 105;
struct SHIP {
  long long x, a, f, p;
  SHIP() {}
  SHIP(long long _x, long long _a, long long _f, long long _p) {
    x = _x, a = _a, f = _f, p = _p;
  }
};
SHIP ship[N * 1000];
long long d[N][N];
long long value[N * 1000];
vector<pair<long long, long long> > list228[N * 1000];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    d[u][v] = d[v][u] = 1;
  }
  for (long long k = 1; k <= n; ++k) {
    for (long long i = 1; i <= n; ++i) {
      for (long long j = 1; j <= n; ++j) {
        if (d[i][k] != INF && d[k][j] != INF) {
          uin(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
  long long s, b, k;
  cin >> s >> b >> k;
  for (long long i = 1; i <= s; ++i) {
    cin >> ship[i].x >> ship[i].a >> ship[i].f >> ship[i].p;
  }
  for (long long i = 1; i <= b; ++i) {
    long long x, d, g;
    cin >> x >> d >> g;
    list228[x].push_back(make_pair(d, g));
  }
  for (long long i = 1; i <= n; ++i) {
    sort(list228[i].begin(), list228[i].end());
    for (long long j = 1; j < (long long)list228[i].size(); ++j) {
      uax(list228[i][j].second, list228[i][j - 1].second);
    }
  }
  for (long long i = 1; i <= s; ++i) {
    bool ok = 0;
    for (long long v = 1; v <= n; ++v) {
      if (d[ship[i].x][v] > ship[i].f || list228[v].empty()) continue;
      long long l = 0, r = (long long)list228[v].size();
      while (r - l > 1) {
        long long mid = (l + r) >> 1;
        if (list228[v][mid].first <= ship[i].a) {
          l = mid;
        } else {
          r = mid;
        }
      }
      if (list228[v][l].first <= ship[i].a) {
        uax(value[i], list228[v][l].second);
        ok = 1;
      }
    }
    if (!ok) value[i] = -INF;
  }
  for (long long i = 1; i <= s; ++i) {
    if (value[i] != -INF) value[i] -= ship[i].p;
  }
  Dinic::n = s + 2;
  for (long long i = 0; i < k; ++i) {
    long long u, v;
    cin >> u >> v;
    Dinic::add_edge(u, v, INF);
  }
  long long S = s + 1, T = s + 2;
  long long sumpos = 0;
  for (long long i = 1; i <= s; ++i) {
    if (value[i] > 0) {
      Dinic::add_edge(S, i, value[i]);
      sumpos += value[i];
    } else {
      Dinic::add_edge(i, T, -value[i]);
    }
  }
  long long res = sumpos - Dinic::max_flow(S, T);
  cout << res << '\n';
  return 0;
}
