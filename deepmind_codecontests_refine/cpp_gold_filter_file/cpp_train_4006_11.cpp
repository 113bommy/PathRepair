#include <bits/stdc++.h>
using namespace std;
int mat[1009][1009];
int main() {
  memset(mat, 0, sizeof mat);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x += 3;
    y += 3;
    mat[x][y] = 1;
    if (mat[x + 1][y] && mat[x][y + 1] && mat[x + 1][y + 1]) {
      cout << i + 1 << endl;
      return 0;
    } else if (mat[x - 1][y] && mat[x][y + 1] && mat[x - 1][y + 1]) {
      cout << i + 1 << endl;
      return 0;
    } else if (mat[x + 1][y] && mat[x][y - 1] && mat[x + 1][y - 1]) {
      cout << i + 1 << endl;
      return 0;
    } else if (mat[x - 1][y] && mat[x][y - 1] && mat[x - 1][y - 1]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << "0" << endl;
  return 0;
}
