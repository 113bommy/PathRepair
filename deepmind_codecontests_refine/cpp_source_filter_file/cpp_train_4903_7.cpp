#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int n, m, q, ans;
vector<int> nei[maxn];
bool mark[maxn];
void dfs(int v) {
  mark[v] = true;
  for (auto u : nei[v])
    if (!mark[u]) dfs(u);
}
void dfs_all() {
  for (int i = 0; i < m + n - 1; i++) {
    if (!mark[i]) dfs(i), ans++;
  }
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0, a, b; i < q; i++) {
    cin >> a >> b;
    a--, b--;
    nei[a].push_back(b + n);
    nei[b + n].push_back(a);
  }
  dfs_all();
  cout << ans - 1 << endl;
}
