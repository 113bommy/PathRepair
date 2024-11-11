#include <bits/stdc++.h>
using namespace std;
const int N = 150;
const int inf = 1e9 + 50;
const int mod = 1e9 + 7;
bool st[N][N], col[N][N];
int n;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, -2, 2, 1, -1, -1, 1};
bool valid(int x, int y) { return x >= 0 && x < n && y < n && y >= 0; }
void sol(int x, int y, bool val) {
  st[x][y] = 1;
  col[x][y] = val;
  for (int i = 0; i < 8; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (valid(a, b) && !st[a][b]) sol(a, b, val ^ 1);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> n;
  sol(0, 0, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (col[i][j])
        cout << "W";
      else
        cout << "B";
    }
    cout << "\n";
  }
}
