#include <bits/stdc++.h>
using namespace std;
long long memo[30 + 2][30 + 2][50 + 2];
bool used[30 + 2][30 + 2][50 + 2];
long long dp(int x, int y, int k) {
  if (k == 0) return 0;
  if ((x * y) == k) return 0;
  if ((x * y) < k) return INT_MAX;
  if ((x == 1) || (y == 1)) return 1;
  if (used[x][y][k]) return memo[x][y][k];
  used[x][y][k] = 1;
  long long &dev = memo[x][y][k] = INT_MAX;
  for (int j = 0; j <= k; j++) {
    for (int i = 1; i < x; i++) {
      dev = min(dev, (long long)y * y + dp(i, y, j) + dp(x - i, y, k - j));
    }
  }
  for (int j = 0; j <= k; j++) {
    for (int i = 1; i < y; i++) {
      dev = min(dev, (long long)x * x + dp(x, i, j) + dp(x, y - i, k - j));
    }
  }
  return dev;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    cout << dp(x, y, k) << '\n';
  }
}
