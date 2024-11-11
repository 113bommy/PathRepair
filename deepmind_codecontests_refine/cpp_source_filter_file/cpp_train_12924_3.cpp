#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
char a[N];
inline int sum(int x, int start) {
  if (x < 0) x += 11;
  int ans = (x * start + x * (x - 1) / 2);
  ans %= 11;
  if (ans < 0) ans += 11;
  return ans;
}
int dp[11][11][11], dp2[11][11][11];
int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  long long ans = 0;
  for (int i = 0; i < 11; i++)
    for (int j = 0; j < 11; j++)
      for (int k = 0; k < 11; k++) dp[i][j][k] = n;
  a[n + 1] = '0';
  for (int i = n; i >= 1; i--) {
    for (int ord = 0; ord < 11; ord++) {
      for (int pre = 0; pre < 11; pre++) {
        for (int cur = 0; cur < 11; cur++) {
          if (a[i + 1] - '0' < ord) {
            int new_pre = pre + cur;
            if (new_pre >= 11) new_pre -= 11;
            int new_ord = new_pre;
            new_ord += sum(ord - pre - 1, pre + 1);
            new_ord += a[i + 1] - '0' + 1;
            if (new_ord >= 11) new_ord -= 11;
            if (new_ord >= 11) new_ord -= 11;
            int new_cur = sum(cur, pre + 1);
            dp2[ord][pre][cur] = dp[new_ord][new_pre][new_cur];
          } else
            dp2[ord][pre][cur] = i;
        }
      }
    }
    for (int i = 0; i < 11; i++)
      for (int j = 0; j < 11; j++)
        for (int k = 0; k < 11; k++) dp[i][j][k] = dp2[i][j][k];
    if (a[i] != '0') {
      ans += dp[a[i] - '0'][0][9] - i + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
