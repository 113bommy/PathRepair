#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e3 + 10;
string a[mxn];
bool vis[mxn][mxn];
int n, m;
bool dfs(int i, int j) {
  if (i < 0 || i > m - 1 || j < 0 || j > n - 1) return 0;
  if (a[i][j] == '.' || vis[i][j]) return 0;
  vis[i][j] = 1;
  dfs(i + 1, j);
  dfs(i, j + 1);
  dfs(i - 1, j);
  dfs(i, j - 1);
  return 1;
}
void solve() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int x = 0, y = 0;
  for (int i = 0; i < m; i++) {
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        if (j && c) {
          if (a[i][j - 1] == '.') c++;
        }
        if (c == 0) c++;
      }
    }
    if (c > 1) {
      cout << -1;
      return;
    }
    if (c == 0) y = 1;
  }
  for (int j = 0; j < n; j++) {
    int c = 0;
    for (int i = 0; i < m; i++) {
      if (a[i][j] == '#') {
        if (i && c) {
          if (a[i - 1][j] == '.') c++;
        }
        if (c == 0) c++;
      }
    }
    if (c > 1) {
      cout << -1;
      return;
    }
    if (c == 0) x = 1;
  }
  if (x + y == 1) {
    cout << -1;
    return;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (dfs(i, j)) ans += 1;
    }
  }
  cout << ans;
}
int main() { solve(); }
