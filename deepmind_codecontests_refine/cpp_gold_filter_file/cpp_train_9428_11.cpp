#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 1e5 + 3;
int n, col[2 * N], a[N], b[N];
vector<int> g[2 * N];
void dfs(int u) {
  for (int v : g[u])
    if (!col[v]) {
      if (col[u] == 1)
        col[v] = 2;
      else
        col[v] = 1;
      dfs(v);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i] >> b[i];
    g[a[i]].emplace_back(b[i]);
    g[b[i]].emplace_back(a[i]);
  }
  for (int i = (1); i <= (n); ++i)
    g[2 * i - 1].emplace_back(2 * i), g[2 * i].emplace_back(2 * i - 1);
  for (int i = (1); i <= (2 * n); ++i)
    if (!col[i]) col[i] = 1, dfs(i);
  for (int i = (1); i <= (n); ++i)
    cout << col[a[i]] << ' ' << col[b[i]] << '\n';
  return 0;
}
