#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, K;
vector<int> adj[N];
int dep[N], trace[N];
struct FakeCycle {
  int type;
  int u, v, k;
};
vector<FakeCycle> Leave;
void dfs(int u, int dady = 0) {
  trace[u] = dady;
  dep[u] = dep[dady] + 1;
  bool flag_leave = 1;
  vector<int> typeMod, typeFool;
  for (int v : adj[u]) {
    if (v == dady) continue;
    if (!dep[v])
      flag_leave = 0, dfs(v, u);
    else {
      if ((dep[u] - dep[v] + 1) % 3 != 0)
        typeMod.push_back(v);
      else
        typeFool.push_back(v);
    }
  }
  if (flag_leave) {
    if (typeMod.size())
      Leave.push_back({0, typeMod[0], u, -1});
    else {
      assert(typeFool.size() >= 2);
      if (dep[typeFool[0]] > dep[typeFool[1]]) swap(typeFool[0], typeFool[1]);
      Leave.push_back({1, typeFool[0], typeFool[1], u});
    }
  }
}
void solve_cycle() {
  cout << "CYCLES\n";
  for (int coo = 0; coo < K; coo++) {
    if (Leave[coo].type == 0) {
      int lst = Leave[coo].v;
      int fst = Leave[coo].u;
      std::vector<int> cycle;
      cycle.push_back(lst);
      while (cycle.back() != fst) cycle.push_back(trace[cycle.back()]);
      cout << cycle.size() << '\n';
      for (int u : cycle) cout << u << ' ';
      cout << '\n';
    } else {
      int lst = Leave[coo].v;
      int fst = Leave[coo].u;
      std::vector<int> cycle;
      cycle.push_back(lst);
      while (cycle.back() != fst) cycle.push_back(trace[cycle.back()]);
      cout << cycle.size() + 1 << '\n';
      cout << Leave[coo].k << ' ';
      for (int u : cycle) cout << u << ' ';
      cout << '\n';
    }
  }
}
int main() {
  if (fopen("main.in", "r"))
    assert(freopen("main.in", "r", stdin));
  else if (fopen("1104E"
                 ".inp",
                 "r"))
    assert(
        freopen("1104E"
                ".inp",
                "r", stdin)),
        assert(freopen("1104E"
                       ".out",
                       "w", stdout));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> K;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  if (*max_element(dep + 1, dep + 1 + n) >= n / K) {
    vector<int> path;
    int lst = max_element(dep + 1, dep + 1 + n) - dep;
    path.push_back(lst);
    while (path.back() != 1) path.push_back(trace[path.back()]);
    cout << "PATH\n";
    cout << path.size() << '\n';
    for (int u : path) cout << u << ' ';
    cout << '\n';
  } else {
    solve_cycle();
  }
}
