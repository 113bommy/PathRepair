#include <bits/stdc++.h>
using namespace std;
int cnt[10];
long long dp[20];
long long cho[40][40];
int main() {
  string S;
  cin >> S;
  for (char c : S) {
    cnt[c - '0']++;
  }
  cho[0][0] = 1;
  for (int i = 1; i < 40; i++) {
    cho[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      cho[i][j] = cho[i - 1][j] + cho[i - 1][j - 1];
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= 10; i++) {
    i %= 10;
    if (cnt[i]) {
      long long ndp[20];
      memset((ndp), (0), sizeof(ndp));
      if (dp[0] == 1) {
        for (int j = 1; j <= cnt[i]; j++) {
          ndp[j] = 1;
        }
      } else {
        for (int j = 1; j < 20; j++) {
          if (dp[j]) {
            int nplace = (i == 0 ? j : j + 1);
            int ndig = cnt[i];
            for (int k = 1; k <= ndig; k++) {
              ndp[j + ndig] += dp[j] * cho[ndig + nplace - 1][nplace - 1];
            }
          }
        }
      }
      memcpy(dp, ndp, sizeof(ndp));
    }
    if (i == 0) {
      break;
    }
  }
  long long ans = 0;
  for (int i = 1; i < 20; i++) {
    ans += dp[i];
  }
  cout << ans << endl;
}
