#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[1000005];
  scanf("%s", s);
  int mo[30] = {0,    1689, 1698, 1869, 1896, 1968, 1986, 6189, 6198,
                6819, 6891, 6918, 6981, 8169, 8196, 8619, 8691, 8916,
                8961, 9168, 9186, 9618, 9681, 9816, 9861};
  int len = strlen(s);
  if (len == 4) {
    printf("1869");
    return 0;
  }
  int dp[15];
  for (int i = 0; i < len; i++) {
    dp[s[i] - '0']++;
  }
  dp[1]--;
  dp[6]--;
  dp[9]--;
  dp[8]--;
  len -= 4;
  bool flag = false;
  for (int i = 1; i <= 9; i++)
    if (dp[i]) flag = true;
  if (!flag) {
    printf("1869");
    for (int i = 1; i <= dp[0]; i++) printf("0");
    return 0;
  }
  int sum = 0;
  int zhan = 1;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= dp[i]; j++) {
      zhan = sum * 10 + i;
      sum = (zhan) % 7;
    }
  }
  for (int i = 1; i <= dp[0]; i++) sum = (sum * 10) % 7;
  int i;
  for (i = 1; i <= 24; i++)
    if ((sum * 10000 + mo[i]) % 7 == 0) break;
  for (int k = 1; k <= 9; k++) {
    for (int j = 1; j <= dp[k]; j++) {
      printf("%d", k);
    }
  }
  for (int k = 1; k <= dp[0]; k++) printf("0");
  printf("%d", mo[i]);
  return 0;
}
