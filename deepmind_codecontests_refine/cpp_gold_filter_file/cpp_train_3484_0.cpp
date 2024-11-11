#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1e3 + 5;
const int MAXE = 1e3 + 5;
const int INF = (1 << 29);
const int N = 1e2 + 5;
int capacity[MAXE], flow[MAXE];
int n, m, dat[N], last[MAXV], level[MAXV], used[MAXV], to[MAXE], _prev[MAXE],
    a[N], b[N];
set<int> primes;
struct MaxFlow {
  int V, E;
  MaxFlow(int n) {
    V = n;
    E = 0;
    for (int i = 0; i < V; i++) last[i] = -1;
  }
  void addEdge(int x, int y, int val) {
    capacity[E] = val;
    flow[E] = 0;
    to[E] = y;
    _prev[E] = last[x];
    last[x] = E;
    E++;
    capacity[E] = 0;
    flow[E] = 0;
    to[E] = x;
    _prev[E] = last[y];
    last[y] = E;
    E++;
  }
  bool bfs(int v, int t) {
    for (int i = 0; i < V; i++) level[i] = -1;
    queue<int> q;
    q.push(v);
    level[v] = 0;
    while (!q.empty()) {
      int nxt = q.front();
      q.pop();
      for (int i = last[nxt]; i >= 0; i = _prev[i]) {
        if (level[to[i]] == -1 && capacity[i] > flow[i]) {
          q.push(to[i]);
          level[to[i]] = level[nxt] + 1;
        }
      }
    }
    return (level[t] != -1);
  }
  int dfs(int v, int t, int val) {
    if (v == t) return val;
    for (int i = used[v]; i >= 0; used[v] = i = _prev[i]) {
      if (level[to[i]] > level[v] && capacity[i] > flow[i]) {
        int tmp = dfs(to[i], t, min(val, capacity[i] - flow[i]));
        if (tmp > 0) {
          flow[i] += tmp;
          flow[i ^ 1] -= tmp;
          return tmp;
        }
      }
    }
    return 0;
  }
  int maxflow(int v, int t) {
    while (bfs(v, t)) {
      for (int i = 0; i < V; i++) used[i] = last[i];
      while (dfs(v, t, INF) != 0)
        ;
    }
    int ans = 0;
    for (int i = last[v]; i >= 0; i = _prev[i]) ans += flow[i];
    return ans;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> dat[i];
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    if (a[i] & 1) swap(a[i], b[i]);
  }
  for (int i = 0; i < n; i++) {
    int tmp = dat[i];
    for (int d = 2; d * d <= tmp; d++) {
      if (tmp % d == 0) {
        primes.insert(d);
        while (tmp % d == 0) {
          tmp /= d;
        }
      }
    }
    if (tmp > 1) primes.insert(tmp);
  }
  int ans = 0;
  for (int p : primes) {
    MaxFlow mf(n + 2);
    for (int i = 0; i < n; i++) {
      int tmp = dat[i], cnt = 0;
      while (tmp % p == 0) {
        tmp /= p;
        cnt++;
      }
      if (i % 2 == 0)
        mf.addEdge(n, i, cnt);
      else
        mf.addEdge(i, n + 1, cnt);
    }
    for (int i = 0; i < m; i++) mf.addEdge(a[i], b[i], 100);
    ans += mf.maxflow(n, n + 1);
  }
  cout << ans << "\n";
  return 0;
}
