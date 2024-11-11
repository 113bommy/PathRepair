#include <bits/stdc++.h>
using namespace std;
int co[4], dp[4][12][12][105][105], n1, n2, k1, k2;
long long int func(int i, int c1, int c2, int a1, int a2) {
  if (c1 > co[0] || c2 > co[1]) {
    return 0;
  } else if (a1 == 0 && a2 == 0) {
    return 1;
  } else if (dp[i][c1][c2][a1][a2] != -1) {
    return dp[i][c1][c2][a1][a2];
  } else if (a1 == 0) {
    dp[1][c1][c2 + 1][a1][a2 - 1] = func(1, c1, c2 + 1, a1, a2 - 1);
    return dp[1][c1][c2 + 1][a1][a2 - 1];
  } else if (a2 == 0) {
    dp[0][c1 + 1][c2][a1 - 1][a2] = func(0, c1 + 1, c2, a1 - 1, a2);
    return dp[0][c1 + 1][c2][a1 - 1][a2];
  } else {
    int a = 0, b = 0;
    if (i == 0) {
      a = func(0, c1 + 1, c2, a1 - 1, a2);
      b = func(1, 0, 1, a1, a2 - 1);
    } else {
      a = func(0, 1, 0, a1 - 1, a2);
      b = func(1, c1, c2 + 1, a1, a2 - 1);
    }
    dp[i][c1][c2][a1][a2] = (a % 100000000) + (b % 100000000) % 100000000;
    return dp[i][c1][c2][a1][a2];
  }
}
int main() {
  cin >> n1 >> n2 >> k1 >> k2;
  co[0] = k1;
  co[1] = k2;
  memset(dp, -1, sizeof(dp));
  cout << func(0, 0, 0, n1, n2) << endl;
}
