#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100][100];
int dp[100][100][11];
int solve(int x, int y, int rem) {
  if (y == -1 || y == m) {
    return INT_MIN;
  }
  if (x == -1) {
    return ((rem == 0) ? 0 : INT_MIN);
  }
  if (dp[x][y][rem] != -1) {
    return dp[x][y][rem];
  }
  int r = (rem + a[x][y]) % k;
  return dp[x][y][rem] = max(a[x][y] + solve(x - 1, y - 1, r),
                             a[x][y] + solve(x - 1, y + 1, r));
}
void print(int x, int y, int rem) {
  int r = (rem + a[x][y]) % k;
  int right = INT_MIN, left = INT_MIN;
  if (y + 1 != m) {
    right = dp[x - 1][y + 1][r];
  }
  if (y - 1 != -1) {
    left = dp[x - 1][y - 1][r];
  }
  if (right > left) {
    cout << "R";
    if (x == 1) {
      return;
    }
    print(x - 1, y + 1, r);
  } else {
    cout << "L";
    if (x == 1) {
      return;
    }
    print(x - 1, y - 1, r);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  k++;
  memset(dp, -1, sizeof(dp));
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  int ans = INT_MIN, index;
  for (int i = 0; i < m; i++) {
    int temp = solve(n - 1, i, 0);
    if (ans < temp) {
      ans = temp;
      index = i;
    }
  }
  if (ans < 0) {
    cout << -1;
  } else {
    cout << ans << "\n";
    cout << index + 1 << "\n";
    print(n - 1, index, 0);
  }
  return 0;
}
