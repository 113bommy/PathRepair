#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int inf = 1e9 + 7;
int q;
string second[3];
bool was[4][N];
int n, k;
void dfs(int z, int x, int y) {
  if (x == 2 && y == n) {
    int g = second[x][y - 1] - '0';
    if (z == 1 && (g == 1 || g == 2)) {
      was[x][y] = 1;
    } else if (z != 1 && g != 1 && g != 2)
      was[x][y] = 1;
    return;
  }
  was[x][y] = 1;
  int g = second[x][y - 1] - '0';
  if (z == 1) {
    if ((g == 1 || g == 2) && was[x][y + 1] == 0 && y < n) {
      dfs(1, x, y + 1);
    }
    if (g != 1 && g != 2) {
      if (x == 2 && was[1][y] == 0) {
        dfs(2, x - 1, y);
      } else if (x == 1 && was[2][y] == 0) {
        dfs(3, x + 1, y);
      }
    }
  } else {
    if ((g == 1 || g == 2)) {
      return;
    }
    if (was[x][y + 1] == 0 && y < n) dfs(1, x, y + 1);
  }
}
int main() {
  cin >> q;
  for (int tr = 1; tr <= q; ++tr) {
    cin >> n;
    cin >> second[1] >> second[2];
    dfs(1, 1, 1);
    if (was[2][n] == 1) {
      cout << "YES";
    } else
      cout << "NO";
    cout << endl;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= n; ++j) was[i][j] = 0;
  }
}
