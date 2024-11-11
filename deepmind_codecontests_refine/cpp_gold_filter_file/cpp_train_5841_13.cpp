#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int a, b, c, d, e1, e2;
bool vis[1005][1005];
void init() {
  for (long long int i = 0; i < 1005; i++) {
    for (long long int j = 0; j < 1005; j++) {
      vis[i][j] = false;
    }
  }
}
bool dfs(long long int x, long long int y) {
  vis[x][y] = true;
  if (x <= 0 || x > n || y <= 0 || y > n || x == c || y == d ||
      (abs(x - c) == abs(y - d))) {
    return 0;
  } else if (x == e1 && y == e2) {
    return 1;
  }
  bool ans = 0;
  if (vis[x + 1][y] == false) {
    ans = ans | dfs(x + 1, y);
  }
  if (vis[x - 1][y] == false) {
    ans = ans | (dfs(x - 1, y));
  }
  if (vis[x][y + 1] == false) {
    ans = ans | (dfs(x, y + 1));
  }
  if (vis[x + 1][y + 1] == false) {
    ans = ans | (dfs(x + 1, y + 1));
  }
  if (vis[x - 1][y - 1] == false) {
    ans = ans | (dfs(x - 1, y - 1));
  }
  if (vis[x - 1][y + 1] == false) {
    ans = ans | (dfs(x - 1, y + 1));
  }
  if (vis[x + 1][y - 1] == false) {
    ans = ans | (dfs(x + 1, y - 1));
  }
  if (vis[x][y - 1] == false) {
    ans = ans | (dfs(x, y - 1));
  }
  return ans;
}
void solve() {
  cin >> n;
  cin >> c >> d >> a >> b >> e1 >> e2;
  init();
  if (dfs(a, b)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1;
  while (tests--) {
    solve();
  }
}
