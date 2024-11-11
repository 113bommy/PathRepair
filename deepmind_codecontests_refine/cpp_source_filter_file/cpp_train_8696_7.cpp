#include <bits/stdc++.h>
std::vector<bool> V;
std::vector<std::vector<std::pair<int, int>>> G;
std::vector<long long> A;
std::vector<long long> D;
std::vector<int> R;
long long C = 0;
void dfs(int v, long long md, bool c = false) {
  if (V[v]) return;
  if (c) ++C;
  V[v] = true;
  if (md > A[v]) {
    R.push_back(v);
  }
  for (const auto& n : G[v]) {
    auto nmd = std::max(md + n.second, 0ll);
    dfs(n.first, nmd, nmd > A[n.first]);
  }
}
int main() {
  int n;
  std::cin >> n;
  V.resize(n + 1, false);
  G.resize(n + 1);
  A.resize(n + 1);
  D.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 2; i <= n; ++i) {
    int p;
    int c;
    std::cin >> p >> c;
    G[i].push_back(std::make_pair(p, c));
    G[p].push_back(std::make_pair(i, c));
  }
  dfs(1, 0);
  std::cout << C << "\n";
}
