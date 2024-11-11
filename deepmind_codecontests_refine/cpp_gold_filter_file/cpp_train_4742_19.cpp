#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int u, v;
int used[104][104];
int movesx[10] = {0, 0, 1, -1};
int movesy[10] = {1, -1, 0, 0};
char ms[105][105];
int m, n;
void dfs(int rx, int ry) {
  used[ry][rx] = 1;
  for (int i = 0; i < 4; ++i) {
    int xz = rx + movesx[i];
    int yz = ry + movesy[i];
    if (xz < 0 || xz >= m) continue;
    if (yz < 0 || yz >= n) continue;
    if (!used[yz][xz] && ms[yz][xz] == 'B') dfs(xz, yz);
  }
}
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) ms[i][j] = s[j];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[i][j] && ms[i][j] == 'B') {
        dfs(j, i);
        res += 1;
      }
    }
  }
  cout << res << endl;
}
