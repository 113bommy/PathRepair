#include <bits/stdc++.h>
using namespace std;
mt19937 rnd((size_t)time(nullptr));
vector<vector<int>> g;
vector<long long> p;
vector<long long> h;
vector<long long> acc;
int n, m;
void dfs(int v, int pr, bool &can) {
  acc[v] = 0;
  for (int u : g[v]) {
    if (u == pr) {
      continue;
    }
    dfs(u, v, can);
    acc[v] += acc[u];
    p[v] += p[u];
  }
  if ((h[v] + p[v]) % 2 == 1) {
    can = false;
    return;
  }
  long long a = (h[v] + p[v]) / 2;
  if (a < acc[v] || a > p[v]) {
    can = false;
    return;
  }
  acc[v] = a;
}
int main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n >> m;
    g.clear();
    p.clear();
    g.resize(n);
    p.resize(n);
    h.resize(n);
    acc.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    bool can = true;
    dfs(0, -1, can);
    if (can) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  cout << endl;
  return 0;
}
