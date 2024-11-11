#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
const int INF = 0x7FFFFFFF;
const double eps = 1e-8;
const double pi = acos(-1.0);
int n;
vector<int> g[MAXN];
void init() {
  int x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) g[i].clear();
  cout << n - 1 << endl;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(i);
    g[y].push_back(i);
    cout << 2 << ' ' << x << ' ' << y << endl;
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size() - 1; j++)
      cout << g[i][j] << ' ' << g[i][j] + 1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  init();
  solve();
  return 0;
}
