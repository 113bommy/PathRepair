#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40;
const int oo = 1e9 + 7;
int n, grid[MAXN][MAXN], factor[MAXN][MAXN];
int mid;
int mul(int a, int b) {
  if (a == 0) return b;
  return -b;
}
int solveColum(int y) {
  int res = 0;
  res += mul(factor[mid][y], grid[mid][y]);
  res += mul(factor[mid][y + mid], grid[mid][y + mid]);
  for (int x = 1; x < mid; x++) {
    factor[x][y] = 1;
    factor[x + mid][y] = factor[x][y] ^ factor[mid][y];
    factor[x][y + mid] = factor[x][mid] ^ factor[x][y];
    factor[x + mid][y + mid] = factor[x + mid][y] ^ factor[x + mid][mid];
    int s = 0;
    s += mul(factor[x][y], grid[x][y]);
    s += mul(factor[x + mid][y], grid[x + mid][y]);
    s += mul(factor[x][y + mid], grid[x][y + mid]);
    s += mul(factor[x + mid][y + mid], grid[x + mid][y + mid]);
    res += abs(s);
  }
  return res;
}
int solve() {
  int res = 0;
  for (int y = 1; y < mid; y++) {
    int temp = -oo;
    factor[mid][y] = 0;
    factor[mid][y + mid] = factor[mid][mid] ^ factor[mid][y];
    temp = max(temp, solveColum(y));
    factor[mid][y] = 1;
    factor[mid][y + mid] = factor[mid][mid] ^ factor[mid][y];
    temp = max(temp, solveColum(y));
    res += temp;
  }
  for (int x = 1; x <= n; x++) res += mul(factor[x][mid], grid[x][mid]);
  return res;
}
int main() {
  cin >> n;
  mid = (n + 1) / 2;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      cin >> grid[x][y];
    }
  }
  int res = -oo;
  for (int mask = 0; mask < (1 << mid); mask++) {
    for (int x = 1; x <= mid; x++)
      if (mask & (1 << (x - 1)) > 0)
        factor[x][mid] = 1;
      else
        factor[x][mid] = 0;
    for (int x = mid + 1; x <= n; x++)
      factor[x][mid] = factor[mid][mid] ^ factor[x - mid][mid];
    res = max(res, solve());
  }
  cout << res;
  return 0;
}
