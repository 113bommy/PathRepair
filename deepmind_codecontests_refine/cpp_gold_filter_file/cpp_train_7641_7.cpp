#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAXN = 100005;
const int MAXV = 1000010;
inline long long gcd(long long n1, long long n2) {
  return n2 == 0 ? abs(n1) : gcd(n2, n1 % n2);
}
int n;
int grid[505][505];
string ans;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char vc[] = {'D', 'R', 'U', 'L'};
bool is_ok(int x, int y, int d) {
  x += dx[d], y += dy[d];
  while (x >= 0 && x < n && y >= 0 && y < n) {
    if (grid[x][y] == 1) return true;
    if (grid[x][y] != 0) return false;
    x += dx[d], y += dy[d];
  }
  return false;
}
void dfs(int x0, int y0) {
  int aux = grid[x0][y0];
  if (!aux) ans += '1';
  grid[x0][y0] = 2;
  for (int k = 0; k < 4; ++k) {
    if (!is_ok(x0, y0, k)) continue;
    ans += vc[k];
    dfs(x0 + dx[k], y0 + dy[k]);
    ans += vc[(k + 2) % 4];
  }
  ans += '2';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x0, y0;
  while (cin >> n >> x0 >> y0) {
    x0--, y0--;
    ans.clear();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) cin >> grid[i][j];
    dfs(x0, y0);
    bool ok = true;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) ok = false;
    if (ok) {
      cout << "YES" << endl;
      cout << ans << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
