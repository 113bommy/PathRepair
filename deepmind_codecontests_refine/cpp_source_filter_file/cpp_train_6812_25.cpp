#include <bits/stdc++.h>
using namespace std;
const int MN = 100 + 5;
const int MW = 1000 + 5;
int dp[MN][MN][MW], n, m, k;
int arr[MN][MN];
int solve(int x, int y, int w) {
  if (x < 0 || y < 0 || y == m) return 0;
  w -= arr[x][y];
  if (w < 0) return 0;
  if (dp[x][y][w] != -1) return dp[x][y][w];
  if (x == 0 && !w) return 1;
  return dp[x][y][w] = solve(x - 1, y - 1, w) | solve(x - 1, y + 1, w);
}
void my_print(int x, int y, int w) {
  if (x < 0 || y < 0 || y == m) return;
  w -= arr[x][y];
  if (w < 0) return;
  int ans1 = solve(x - 1, y - 1, w);
  int ans2 = solve(x - 1, y + 1, w);
  if (ans1) {
    cout << "L";
    my_print(x - 1, y - 1, w);
  } else if (ans2) {
    cout << "R";
    my_print(x - 1, y + 1, w);
  }
}
int main() {
  fill(&dp[0][0][0], &dp[0][0][0] + MN * MN * MW, -1);
  cin >> n >> m >> k;
  k++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      arr[i][j] = ch - '0';
    }
  int ans = -1, p;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= MW; j++) {
      if (j % k) continue;
      if (solve(n - 1, i, j) && j > ans) {
        ans = j;
        p = i;
      }
    }
  if (ans == -1)
    cout << ans;
  else {
    cout << ans << endl << p + 1 << endl;
    my_print(n - 1, p, ans);
  }
  return 0;
}
