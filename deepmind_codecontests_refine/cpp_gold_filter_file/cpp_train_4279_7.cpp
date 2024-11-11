#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, m, i, j;
  int dp[1010][1010];
  int dp2[1010];
  for (i = 0; i < 1010; i++) {
    for (j = 0; j < 1010; j++) dp[i][j] = 0;
  }
  cin >> n >> m >> q;
  string str1, str2;
  cin >> str1;
  cin >> str2;
  int flag, k;
  for (i = 0; i < n; i++) {
    flag = 0;
    k = i;
    for (j = 0; j < m; j++) {
      if (k > n - 1 || str2[j] != str1[k]) {
        flag = 1;
        break;
      }
      k++;
    }
    if (flag == 0)
      dp2[i] = 1;
    else
      dp2[i] = 0;
  }
  int val1, val2;
  for (j = 0; j < n; j++) {
    for (i = j; i >= 0; i--) {
      val1 = 0;
      val2 = 0;
      if (i + m - 1 <= j) val1 = dp2[i];
      if (i + 1 <= j) val2 = dp[i + 1][j];
      dp[i][j] = val1 + val2;
    }
  }
  int num1, num2;
  while (q--) {
    cin >> num1 >> num2;
    cout << dp[num1 - 1][num2 - 1] << endl;
  }
  return 0;
}
