#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > e[200];
int deg[105];
inline void dfs(int u, int f, double F) {
  double X = 2 / (double)deg[u];
  for (auto V : e[u]) {
    int v = V.first, id = V.second;
    if (v == f) continue;
    F += X;
    while (F > 2) F -= 2;
    cout << 1 << " " << id << " ";
    if (F <= 1) {
      cout << v << " " << u << " ";
      printf("%.10lf\n", 1 - F);
    } else {
      cout << u << " " << v << " ";
      printf("%.10lf\n", 2 - F);
    }
    dfs(v, u, F + 1);
  }
}
int main(int argc, char** argv) {
  int n;
  cin >> n;
  cout << n - 1 << '\n';
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back({v, i});
    e[v].push_back({u, i});
    ++deg[u], ++deg[v];
  }
  dfs(1, 0, 0.0);
  return 0;
}
