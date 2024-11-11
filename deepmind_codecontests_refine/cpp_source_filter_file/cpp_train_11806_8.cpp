#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 1e9 + 47;
const long long LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace MaxFlow {
const int MAX = 1 << 7;
struct edge {
  int from;
  int to;
  int cap;
  int flow;
};
int n;
int source;
int sink;
int d[MAX];
int ptr[MAX];
vector<edge> e;
vector<int> g[MAX];
void add(int u, int v, int w) {
  g[u].push_back((int)((e).size()));
  e.push_back({u, v, w, 0});
  g[v].push_back((int)((e).size()));
  e.push_back({v, u, 0, 0});
}
bool bfs() {
  queue<int> q;
  q.push(source);
  for (int i = (0); i < (n); ++i) d[i] = -1;
  d[source] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto i : g[v]) {
      int to = e[i].to;
      if (d[to] != -1) continue;
      if (e[i].flow == e[i].cap) continue;
      q.push(to);
      d[to] = d[v] + 1;
    }
  }
  return d[sink] != -1;
}
int dfs(int v, int flow) {
  if (!flow) return 0;
  if (v == sink) return flow;
  while (1) {
    if (ptr[v] == (int)((g[v]).size())) break;
    int id = g[v][ptr[v]];
    int to = e[id].to;
    if (d[to] != d[v] + 1) {
      ++ptr[v];
      continue;
    }
    int push = dfs(to, min(flow, e[id].cap - e[id].flow));
    if (push == 0) {
      ++ptr[v];
      continue;
    }
    e[id].flow += push;
    e[id ^ 1].flow -= push;
    return push;
  }
  return 0;
}
long long dinic() {
  cerr << "Don't forget about constant: " << MAX << endl;
  long long flow = 0;
  while (1) {
    if (!bfs()) break;
    for (int i = (0); i < (n); ++i) ptr[i] = 0;
    while (int push = dfs(source, INF)) flow += push;
  }
  return flow;
}
};  // namespace MaxFlow
const int N = 1 << 7;
int n, m;
int ne_vsi(vector<int> b, vector<int> c) {
  int ans = -1;
  for (int i = (0); i < ((int)((b).size())); ++i) {
    if (i > (int)((c).size())) break;
    int curr = 0;
    bool ok = 1;
    for (int j = (0); j < (i + 1); ++j) {
      if (b[j] > c[(int)((c).size()) - j - 1]) ok = 0;
      curr -= b[j];
      curr += c[(int)((c).size()) - j - 1];
    }
    if (ok) ans = max(ans, curr);
  }
  return ans;
}
vector<int> a, b, c;
int vsi() {
  multiset<int> mt(c.begin(), c.end());
  for (auto i : a) {
    auto it = mt.upper_bound(i);
    if (it == mt.end()) return 0;
    mt.erase(it);
  }
  vector<int> cc(mt.begin(), mt.end());
  for (auto i : b) {
    auto it = mt.lower_bound(i);
    if (it == mt.end()) return 0;
    mt.erase(it);
  }
  int ans = 0;
  for (auto i : cc) ans += i;
  for (auto i : b) ans -= i;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (s == "ATK")
      b.push_back(x);
    else
      a.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  c.resize(m);
  for (int i = (0); i < (m); ++i) cin >> c[i];
  sort(c.begin(), c.end());
  int ans = 0;
  ans = max(ans, vsi());
  ans = max(ans, ne_vsi(b, c));
  cout << ans << endl;
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
