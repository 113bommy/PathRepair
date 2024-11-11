#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e6 + 100;
const int M = 2e3 + 5;
vector<int> g[M];
int used[M];
void dfs(int v, int p = -1) {
  used[v] = 1;
  for (auto &to : g[v]) {
    if (!used[to])
      dfs(to, v);
    else if (to != p) {
      cout << "no";
      exit(0);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int l, r;
    cin >> l >> r;
    g[l].push_back(r);
    g[r].push_back(l);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
}
