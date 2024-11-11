#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool Max(T1& a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T1, typename T2>
bool Min(T1& a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
struct MaxFlow {
  static const int inf = 1e9;
  vector<int> last, used, level, q, cap, to, prev;
  vector<int> good;
  int n, qi, qj;
  void init(int _n, int m = 0) {
    n = _n;
    last.assign(n, -1);
    q.resize(n);
    cap.clear();
    to.clear();
    prev.clear();
    if (m > 0) {
      cap.reserve(m * 2);
      to.reserve(m * 2);
      prev.reserve(m * 2);
    }
  }
  void add(int x, int y, int c, int c2 = 0, int hasf = 0) {
    prev.push_back(last[x]);
    last[x] = cap.size();
    cap.push_back(c);
    to.push_back(y);
    good.push_back(hasf);
    prev.push_back(last[y]);
    if (c2 >= 0)
      last[y] = cap.size();
    else
      c2 = 0;
    cap.push_back(c2);
    to.push_back(x);
    good.push_back(0);
  }
  bool bfs(int s, int t) {
    level.assign(n, -1);
    qi = qj = 0;
    level[s] = 0;
    q[qj++] = s;
    while (qi < qj) {
      int cur = q[qi++];
      int next_level = level[cur] + 1;
      for (int i = last[cur]; i >= 0; i = prev[i])
        if (level[to[i]] == -1 && cap[i]) {
          level[to[i]] = next_level;
          if (to[i] == t) return 1;
          q[qj++] = to[i];
        }
    }
    return 0;
  }
  int dfs(int v, int t, int maxf) {
    if (v == t) return maxf;
    int f = 0;
    for (int i = used[v]; i >= 0; used[v] = i = prev[i])
      if (level[to[i]] > level[v] && cap[i]) {
        int ret = dfs(to[i], t, min(maxf - f, cap[i]));
        cap[i] -= ret;
        cap[i ^ 1] += ret;
        if ((f += ret) == maxf) break;
      }
    return f;
  }
  int maxFlow(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
      used = last;
      ans += dfs(s, t, inf);
    }
    return ans;
  }
} mf;
const int N = 1000;
vector<pair<int, int> > g[N], rg[N];
int pre[N], nxt[N];
int ansc[N], ansf[N];
void solve() {
  int n, m, s, t, u, v, gg;
  cin >> n >> m >> s >> t;
  mf.init(n + 1, m);
  for (int i = 0; i < (m); ++i) {
    cin >> u >> v >> gg;
    if (gg) {
      mf.add(u, v, 1, N, gg);
      g[u].push_back({v, i});
      rg[v].push_back({u, i});
    } else
      mf.add(u, v, 1, 0, gg);
  }
  for (int i = 1; i <= (n); ++i) pre[i] = nxt[i] = -1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (auto& e : g[i])
      if (pre[e.first] < 0) {
        pre[e.first] = e.second;
        q.push(e.first);
      }
  }
  q.push(t);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (auto& e : rg[i])
      if (nxt[e.first] < 0) {
        nxt[e.first] = e.second;
        q.push(e.first);
      }
  }
  for (int i = 0; i < (m); ++i)
    if (mf.good[i * 2] && ansf[i] == 0) {
      ansf[i]++;
      int from = mf.to[i * 2 + 1];
      int to = mf.to[i * 2];
      while (from != s) {
        if (pre[from] < 0) break;
        ansf[pre[from]]++;
        from = mf.to[pre[from] * 2 + 1];
      }
      while (to != t) {
        if (nxt[to] < 0) break;
        ansf[nxt[to]]++;
        to = mf.to[nxt[to] * 2];
      }
    }
  int mxf = mf.maxFlow(s, t);
  for (int i = 0; i < (m); ++i) {
    int from = mf.to[i * 2 + 1];
    int to = mf.to[i * 2];
    bool crit = mf.level[from] >= 0 && mf.level[to] < 0;
    if (mf.good[i * 2]) {
      ansc[i] = ansf[i] + 1;
      if (crit) ansc[i]--;
    } else {
      ansc[i] = 1;
    }
  }
  cout << mxf << '\n';
  for (int i = 0; i < (m); ++i) cout << ansf[i] << ' ' << ansc[i] << '\n';
}
void init() {}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  init();
  int TC = 1;
  for (int TI = 1; TI <= (TC); ++TI) {
    solve();
  }
  return 0;
}
