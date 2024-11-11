#include <bits/stdc++.h>
using namespace std;
long long int dp[101];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int p, y, n, i, j;
  cin >> p >> y;
  while (y > p) {
    n = sqrt(y);
    for (i = 2; i <= n; i++)
      if (y % i == 0) break;
    if (i == n + 1) {
      cout << y;
      return 0;
    } else if (i > p) {
      cout << y;
      return 0;
    }
    y--;
  }
  cout << -1;
  return 0;
}
