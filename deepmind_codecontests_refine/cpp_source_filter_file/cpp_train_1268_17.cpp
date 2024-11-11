#include <bits/stdc++.h>
using std::vector;
struct two_sat {
  vector<vector<int>> G;
  int new_var() {
    int res = G.size();
    G.emplace_back();
    G.emplace_back();
    return res;
  }
  void implies(int u, int v) { G[u].push_back(v); }
  int size() { return G.size(); }
  bool run(vector<bool>& color) {
    vector<bool> in_stk(size());
    int stk_n = 0, dfn_n = 0, scc_n = 0;
    vector<int> stk(size()), dfn(size(), -1), scc(size());
    std::function<int(int)> tarjan = [&](int u) {
      int low = dfn[u] = dfn_n++;
      stk[stk_n++] = u;
      in_stk[u] = true;
      for (const int v : G[u]) {
        if (dfn[v] < 0)
          low = std::min(low, tarjan(v));
        else if (in_stk[v])
          low = std::min(low, dfn[v]);
      }
      if (low == dfn[u]) {
        do {
          int v = stk[--stk_n];
          in_stk[v] = false;
          scc[v] = scc_n;
        } while (stk[stk_n] != u);
        scc_n++;
      }
      return dfn[u] = low;
    };
    for (int i = 0; i < size(); i++)
      if (dfn[i] < 0) tarjan(i);
    color.clear();
    for (int i = 0; i < size(); i += 2) {
      if (scc[i] == scc[i + 1]) return false;
      color.push_back(dfn[i] < dfn[i + 1]);
    }
    return true;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  int n, p, M, m;
  std::cin >> n >> p >> M >> m;
  two_sat solver;
  vector<int> radio_var(p);
  for (int i = 0; i < p; i++) radio_var[i] = solver.new_var();
  for (int i = 0, u, v; i < n; i++) {
    std::cin >> u >> v;
    u = radio_var[u - 1];
    v = radio_var[v - 1];
    solver.implies(u ^ 1, v);
    solver.implies(v ^ 1, u);
  }
  vector<int> low(p), high(p);
  for (int i = 0; i < p; i++) {
    std::cin >> low[i] >> high[i];
    --low[i];
  }
  for (int i = 0, u, v; i < m; i++) {
    std::cin >> u >> v;
    u = radio_var[u - 1];
    v = radio_var[v - 1];
    solver.implies(u, v ^ 1);
    solver.implies(v, u ^ 1);
  }
  vector<int> power_var(++M);
  for (int i = 0; i < M; i++) power_var[i] = solver.new_var();
  for (int i = M - 1; 0 < i; i--) {
    int u = power_var[i];
    int v = power_var[i - 1];
    solver.implies(u, v);
    solver.implies(v ^ 1, u ^ 1);
  }
  for (int i = 0; i < p; i++) {
    solver.implies(radio_var[i], power_var[low[i]]);
    solver.implies(power_var[low[i]] ^ 1, radio_var[i] ^ 1);
    solver.implies(radio_var[i], power_var[high[i]] ^ 1);
    solver.implies(power_var[high[i]], radio_var[i] ^ 1);
  }
  vector<bool> color;
  if (not solver.run(color))
    std::cout << -1 << "\n";
  else {
    int counter = 0;
    for (int i = 0; i < p; i++)
      if (color[radio_var[i] / 2]) counter++;
    int power = 0;
    for (int i = 0; i < M; i++)
      if (color[power_var[i] / 2]) power = i + 1;
    std::cout << counter << " " << power << "\n";
    for (int i = 0; i < p; i++)
      if (color[radio_var[i] / 2]) std::cout << i + 1 << " ";
  }
  return 0;
}
