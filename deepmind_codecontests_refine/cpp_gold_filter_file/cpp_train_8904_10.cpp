#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    vector<vector<int> > grid;
    int h, w;
    cin >> h >> w;
    grid.assign(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &grid[i][j]);
      }
    }
    int diff1 = 0;
    int diff2 = 0;
    for (int j = 0; j < w; j++) {
      diff1 += grid[h / 2 - 1][j] - grid[h / 2][j];
      diff2 += grid[0][j] - grid[h - 1][j];
    }
    if (abs(diff1) > abs(diff2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
