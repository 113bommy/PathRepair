#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[300005][10];
int maskExists[305];
pair<int, int> possible(int v) {
  for (int i = 0; i < 305; i++) maskExists[i] = 0;
  for (int i = 1; i <= n; i++) {
    int mask = 0;
    for (int j = 1; j <= m; j++) mask = (mask << 1) + (mat[i][j] >= v);
    maskExists[mask] = i;
  }
  for (int mask1 = 0; mask1 < (1 << m); mask1++) {
    if (maskExists[mask1]) {
      for (int mask2 = 0; mask2 < (1 << m); mask2++) {
        if (maskExists[mask2]) {
          if ((mask1 | mask2) == (1 << m) - 1)
            return {maskExists[mask1], maskExists[mask2]};
        }
      }
    }
  }
  return {0, 0};
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> mat[i][j];
  int ans = 0;
  pair<int, int> ansIdx = {1, 1};
  for (int step = (1 << 30); step; step >>= 1) {
    pair<int, int> tmp = possible(ans + step);
    if (tmp.first != 0) {
      ans += step;
      ansIdx = tmp;
    }
  }
  cout << ansIdx.first << ' ' << ansIdx.second;
}
