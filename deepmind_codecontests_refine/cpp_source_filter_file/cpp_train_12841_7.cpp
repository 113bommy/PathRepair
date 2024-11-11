#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MAX = 1e9 + 5;
int i, j, k, n, m, arr[305][305], dp[305][305][305];
int top(int x, int y, int x2, int y2) {
  if (x == x2 && y == y2) return arr[x][y];
  return arr[x][y] + arr[x2][y2];
}
int f(int x, int x2, int adim) {
  int y = adim - x + 1, y2 = adim - x2 + 1;
  if (x == n && y == n && x2 == n && y2 == n) return 0;
  if (y > n || x > n || y2 > n || x2 > n) return -100000;
  int &r = dp[x][y][adim];
  if (r != -1) return r;
  return r = max(max(f(x + 1, x2 + 1, adim + 1) + top(x + 1, y, x2 + 1, y2),
                     f(x + 1, x2, adim + 1) + top(x + 1, y, x2, y2 + 1)),
                 max(f(x, x2 + 1, adim + 1) + top(x, y + 1, x2 + 1, y2),
                     f(x, x2, adim + 1) + top(x, y + 1, x2, y2 + 1)));
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
  cout << f(1, 1, 1) + arr[1][1];
  return 0;
}
