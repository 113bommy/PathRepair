#include <bits/stdc++.h>
using namespace std;
const int N = 5100;
int a[N];
int dp[N][N][2];
const int inf = 1e9;
int n;
int solve(int i, int j, int side) {
  if (i <= 0 || j > n) {
    return inf;
  }
  if (i == 1 && j == n) {
    return 0;
  }
  int &ans = dp[i][j][side];
  if (ans != -1) {
    return ans;
  }
  int my_color;
  if (side) {
    my_color = a[i];
  } else {
    my_color = a[j];
  }
  ans = min(solve(i - 1, j, 0) + (a[i - 1] != my_color),
            solve(i, j + 1, 1) + (a[j + 1] != my_color));
  return ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int best = 1e9;
  for (int i = 1; i <= n; i++) {
    best = min(best, solve(i, i, 0));
  }
  cout << best << endl;
  return 0;
}
