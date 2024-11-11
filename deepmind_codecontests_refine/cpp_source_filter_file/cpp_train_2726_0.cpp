#include <bits/stdc++.h>
using namespace std;
int h, w;
int r[1000];
int c[1000];
int grid[1000][1000];
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) cin >> r[i];
  for (int i = 0; i < w; i++) cin >> c[i];
  bool poss = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < r[i]; j++) {
      if (grid[i][j] == -1) poss = false;
      grid[i][j] = 1;
    }
    if (r[i] >= w) continue;
    if (grid[i][r[i]] == 1) poss = false;
    grid[i][r[i]] = -1;
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < c[i]; j++) {
      if (grid[j][i] == -1) poss = false;
      grid[j][i] = 1;
    }
    if (c[i] >= h) continue;
    if (grid[c[i]][i] == 1) poss = false;
    grid[c[i]][i] = -1;
  }
  if (!poss) {
    cout << -1 << '\n';
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 0) ans = (ans * 2) % 1000000007;
    }
  }
  cout << ans << '\n';
  return 0;
}
