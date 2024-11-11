#include <bits/stdc++.h>
using namespace std;
int32_t seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline int32_t rnd(int32_t l = 0, int32_t r = INT_MAX) {
  return uniform_int_distribution<int32_t>(l, r)(rng);
}
template <typename T, typename G>
ostream& operator<<(ostream& out, const pair<T, G>& a) {
  return out << "(" << a.first << " , " << a.second << ")";
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
  out << "[";
  for (const auto& i : a) out << i << " , ";
  return out << "]";
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& a) {
  out << "{";
  for (const auto& i : a) out << i << " , ";
  return out << "}";
}
template <typename T, typename G>
ostream& operator<<(ostream& out, const map<T, G>& a) {
  out << "<";
  for (const auto& i : a) out << i << " , ";
  return out << ">";
}
template <typename T, size_t N>
typename enable_if<!is_same<typename remove_cv<T>::type, char>::value,
                   ostream&>::type
operator<<(ostream& out, T (&a)[N]) {
  out << '[';
  for (size_t i = 0; i < N; ++i) out << a[i] << " , ";
  out << ']';
  return out;
}
vector<int32_t> adjlst[1000005], compo[1000005], low, tin, lbl;
vector<bool> inst;
int32_t ptr, n, m, lb;
stack<int32_t> scc;
void scc_dfs(int32_t u, int32_t p) {
  ptr++;
  low[u] = ptr;
  tin[u] = ptr;
  inst[u] = true;
  scc.push(u);
  for (auto v : adjlst[u]) {
    if (tin[v] == 0) {
      scc_dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else if (inst[v])
      low[u] = min(low[u], tin[v]);
  }
  if (low[u] == tin[u]) {
    lb++;
    int32_t v;
    do {
      v = scc.top();
      compo[lb].push_back(v);
      lbl[v] = lb;
      inst[v] = false;
      scc.pop();
    } while (v != u);
  }
}
int32_t tarjan() {
  ptr = 0;
  lb = 0;
  low.assign(n + 1, 0);
  tin.assign(n + 1, 0);
  lbl.assign(n + 1, 0);
  inst.assign(n + 1, 0);
  for (int32_t i = 0; i <= n; i++) compo[i].clear();
  while (!scc.empty()) scc.pop();
  for (int32_t i = 1; i <= n; i++)
    if (tin[i] == 0) scc_dfs(i, 0);
  return lb;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int32_t t;
  cin >> t;
  while (t--) {
    int32_t i, u, v;
    cin >> n >> m;
    for (i = 0; i <= n; i++) {
      adjlst[i].clear();
    }
    for (i = 0; i < m; i++) {
      cin >> u >> v;
      if (u != v) adjlst[v].push_back(u);
    }
    int32_t tot = tarjan();
    if (tot == 1) {
      cout << "No\n";
      continue;
    }
    vector<int32_t> l, r;
    l = compo[1];
    vector<int32_t> vis;
    vis.assign(n + 1, 0);
    for (auto v : l) {
      vis[v] = 1;
    }
    for (i = 1; i <= n; i++) {
      if (!vis[i]) r.push_back(i);
    }
    cout << "Yes\n";
    cout << l.size() << " " << r.size() << "\n";
    for (auto v : l) {
      cout << v << " ";
    }
    cout << "\n";
    for (auto v : r) {
      cout << v << " ";
    }
    cout << "\n";
  }
  return 0;
}
