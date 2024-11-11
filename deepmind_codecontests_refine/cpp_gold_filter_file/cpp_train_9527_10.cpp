#include <bits/stdc++.h>
char _;
const int INF = 0x3f3f3f3f;
using namespace std;
int n, m, ans;
char a[12][12][12];
void dfs(int z, int x, int y) {
  if (a[z][x][y] != '.') return;
  ans++;
  a[z][x][y] = 'a';
  dfs(z, x - 1, y);
  dfs(z, x + 1, y);
  dfs(z, x, y + 1);
  dfs(z, x, y - 1);
  dfs(z + 1, x, y);
  dfs(z - 1, x, y);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  string second;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      cin >> second;
      for (int k = 1; k <= z; k++) {
        a[i][j][k] = second[k - 1];
      }
    }
  }
  int cx, cy;
  cin >> cx >> cy;
  dfs(1, cx, cy);
  cout << ans;
}
