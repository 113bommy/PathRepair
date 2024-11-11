#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int dp[110][110];
int main() {
  int n, ans = 0;
  cin >> n;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        dp[i][j]++;
      }
    }
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      ans += dp[i][j];
    }
  }
  cout << ans;
  return 0;
}
