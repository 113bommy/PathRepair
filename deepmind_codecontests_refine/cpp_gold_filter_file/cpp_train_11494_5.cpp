#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
using ii = pair<int, int>;
using ll = long long;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
bool vis[N];
int n;
void dfs(int u) {
  vis[u] = 1;
  if (u == 1) {
    cout << "0 1";
    return;
  }
  if (!vis[(u + n) >> 1])
    dfs((u + n) >> 1);
  else
    dfs(u >> 1);
  cout << " " << u;
}
int main() {
  cin >> n;
  if (n & 1) {
    cout << -1 << '\n';
    return 0;
  }
  dfs(0);
  return 0;
}
