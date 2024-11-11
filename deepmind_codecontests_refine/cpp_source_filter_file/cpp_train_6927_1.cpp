#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool smin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool smax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const long long N = (long long)5e3 + 10;
long long n, m, pos[N], cur = 0, d[N];
vector<long long> adj[N], rev[N], st, nodes[N];
bool mark[N];
void dfs(long long v) {
  if (mark[v]++) return;
  for (long long u : adj[v]) dfs(u);
  st.push_back(v);
}
void scc(long long v) {
  if (mark[v]++) return;
  pos[v] = cur;
  nodes[cur].push_back(v);
  for (long long u : rev[v]) scc(u);
}
bool sink(long long col) {
  for (long long v : nodes[col]) {
    for (long long u : adj[v]) {
      if (pos[v] != pos[u]) return 0;
    }
  }
  return 1;
}
long long bfs(long long v) {
  memset(d, -1, sizeof d);
  long long ret = n + 1;
  deque<long long> dq;
  d[v] = 0;
  dq.push_back(v);
  while (!dq.empty()) {
    long long bv = dq.front();
    dq.pop_front();
    for (long long u : adj[bv]) {
      if (d[u] != -1) {
        smin(ret, d[bv] - d[u] + 1);
      } else {
        d[u] = d[bv] + 1;
        dq.push_back(u);
      }
    }
  }
  if (ret == n + 1) ret = 0;
  return ret;
}
long long find_cyc(long long col) {
  long long ret = n + 1;
  for (long long u : nodes[col]) {
    smin(ret, bfs(u));
  }
  if (ret == n + 1) ret = 0;
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    rev[v].push_back(u);
  }
  for (long long i = 0; i < n; ++i) dfs(i);
  memset(mark, 0, sizeof mark);
  for (; !st.empty(); st.pop_back()) {
    long long v = st.back();
    if (mark[v]) continue;
    scc(v);
    ++cur;
  }
  long long res = n;
  for (long long com = 0; com < cur; ++com) {
    if (sink(com)) {
      long long cyc = find_cyc(com);
      if (cyc < 2) continue;
      res += ((long long)998 * cyc);
      ++res;
    }
  }
  cout << res << '\n';
}
