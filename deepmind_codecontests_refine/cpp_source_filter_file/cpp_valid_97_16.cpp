#include <bits/stdc++.h>
using namespace std;
const int N = 510;
char all[N][N];
int res[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void f() {
  for (int i = 1; i <= n; i++) {
    int z = 1;
    for (int j = 1; j <= m; j++) {
      if (j % 2 == 0 && all[i][j] == '.')
        res[i][j] = 1;
      else if (j % 2 == 1 && all[i][j] == '.')
        res[i][j] = 4;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> all[i][j];
    }
  }
  int p = 0;
  int ok = 1;
  for (int i = 1; i <= n; i++) {
    p = 0;
    for (int j = 1; j <= m; j++) {
      if (all[i][j] == 'X') {
        p ^= (all[i - 1][j] == 'X');
        int z = 0;
        for (int k = 0; k < 4; k++) {
          int a = i + dx[k], b = j + dy[k];
          if (a < 1 || a > n || b < 1 || b > m) continue;
          if (all[a][b] == 'X') continue;
          z++;
        }
        if (z % 2 == 1) {
          cout << "NO";
          return 0;
        }
        if (z == 0)
          res[i][j] = -1;
        else if (z == 2)
          res[i][j] = 5;
        else if (z == 4)
          res[i][j] = 10;
      } else {
        res[i][j] = ((j + p) & 1) ? 1 : 4;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
