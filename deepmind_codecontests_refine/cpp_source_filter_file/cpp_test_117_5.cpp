#include <bits/stdc++.h>
using namespace std;
int n, m;
const int max_n = 1e6 + 1;
string G[max_n];
int sx, sy;
pair<int, int> mov[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int possible_route(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int xn = x + mov[i].first, yn = y + mov[i].second;
    if (0 <= xn && xn < n && 0 <= yn && yn < m && G[xn][yn] != '#') cnt++;
  }
  return cnt;
}
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int xn = x + mov[i].first, yn = y + mov[i].second;
    if (xn < 0 || xn >= n || yn < 0 || yn >= m) continue;
    if (G[xn][yn] == '.' && possible_route(xn, yn) <= 2) {
      G[xn][yn] = '+';
      dfs(xn, yn);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> G[i];
    int j = G[i].find('L');
    if (j != -1) sx = i, sy = j;
  }
  dfs(sx, sy);
  for (int i = 0; i < n; i++) cout << G[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
