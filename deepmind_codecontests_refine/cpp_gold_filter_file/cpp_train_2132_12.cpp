#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long v;
  long long t;
  long long mx;
  long long r;
  Edge() = default;
  Edge(long long v, long long t, long long mx, long long r)
      : v(v), t(t), mx(mx), r(r) {}
};
vector<vector<Edge> > g;
long long n, m;
long long s, t;
vector<long long> ct;
bool bfs() {
  ct.assign(2 * n + 2, -1);
  queue<long long> q;
  q.push(s);
  ct[s] = 0;
  while (!q.empty()) {
    long long nw = q.front();
    q.pop();
    for (auto to : g[nw]) {
      if (to.t < to.mx && ct[to.v] == -1) {
        ct[to.v] = ct[nw] + 1;
        q.push(to.v);
      }
    }
  }
  return ct[t] != -1;
}
vector<long long> p;
long long dfs(long long v, long long mn) {
  if (v == t) return mn;
  for (long long i = p[v]; i < g[v].size(); i++) {
    Edge to = g[v][i];
    if (ct[v] + 1 == ct[to.v] && to.mx != to.t) {
      long long del = dfs(to.v, min(mn, to.mx - to.t));
      if (del != 0) {
        g[v][i].t += del;
        g[to.v][to.r].t -= del;
        return del;
      }
    }
    p[v]++;
  }
  return 0;
}
bool is_prime(long long a) {
  for (long long i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
vector<long long> used;
vector<long long> cura;
vector<vector<long long> > gg;
void get_ans(long long v, long long c) {
  used[v] = c;
  cura.push_back(v);
  for (auto to : gg[v]) {
    if (used[to] != c) {
      get_ans(to, c);
    }
  }
}
signed main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
  }
  cin >> n;
  g.resize(2 * n + 2);
  p.resize(2 * n + 2);
  used.resize(n + 1);
  s = 0, t = 2 * n + 1;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (long long i = 1; i <= n; i++) {
    g[s].emplace_back(i, 0, 2, g[i].size());
    g[i].emplace_back(s, 0, 0, g[s].size() - 1);
  }
  for (long long i = n + 1; i <= 2 * n; i++) {
    g[i].emplace_back(t, 0, 2, g[t].size());
    g[t].emplace_back(i, 0, 0, g[i].size() - 1);
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (v[i] % 2 == 0 && v[j] % 2 == 1) {
        if (is_prime(v[i] + v[j])) {
          g[i + 1].emplace_back(j + n + 1, 0, 1, g[j + n + 1].size());
          g[j + n + 1].emplace_back(i + 1, 0, 0, g[i + 1].size() - 1);
        }
      }
    }
  }
  long long flow = 0;
  while (bfs()) {
    p.assign(2 * n + 2, 0);
    long long fl = 0;
    fl = dfs(s, INT_MAX);
    while (fl != 0) {
      flow += fl;
      fl = dfs(s, INT_MAX);
    }
  }
  if (flow == n) {
    gg.resize(n + 1);
    for (long long i = 1; i <= n; i++) {
      for (auto to : g[i]) {
        if (to.t == to.mx && to.mx == 1) {
          gg[i].push_back(to.v - n);
          gg[to.v - n].push_back(i);
        }
      }
    }
    vector<vector<long long> > ans;
    for (long long i = 1; i <= n; i++) {
      cura.clear();
      if (!used[i] && v[i] % 2 == 0) {
        get_ans(i, i);
        ans.push_back(cura);
      }
    }
    cout << ans.size() << '\n';
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i].size() << " ";
      for (long long j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << '\n';
    }
  } else {
    cout << "Impossible";
  }
  return 0;
}
