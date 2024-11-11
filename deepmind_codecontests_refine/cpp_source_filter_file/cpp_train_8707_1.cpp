#include <bits/stdc++.h>
using namespace std;
struct DP {
  int lis, one, two;
};
DP dp1[2001][2001];
int dp2[2001][2001], a[2001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  for (int i = n; i > 0; i--) {
    for (int j = i; j > 0; j--) {
      dp1[j][i] = dp1[j + 1][i];
      if (a[j] == 2) {
        dp1[j][i].two++;
        dp1[j][i].lis++;
      } else {
        dp1[j][i].one++;
        dp1[j][i].lis = max(dp1[j][i].lis, dp1[j][i].one);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = i; j < n + 1; j++) {
      ans = max(ans, dp1[1][i - 1].one + dp1[i][j].lis + dp1[j + 1][n].two);
    }
  }
  cout << ans << '\n';
  return 0;
}
