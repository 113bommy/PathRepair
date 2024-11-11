#include <bits/stdc++.h>
char strin[100100];
int dp[100100];
int arr[30][2];
int len;
int main() {
  scanf("%s", strin);
  len = strlen(strin);
  memset(arr, 0xff, sizeof arr);
  memset(dp, 0xff, sizeof dp);
  arr[strin[len - 1] - 'a'][0] = 1;
  arr[strin[len - 1] - 'a'][1] = len - 1;
  for (int i = len - 2; i >= 0; i--) {
    int nowlen = 1;
    for (int j = 0; j < 26; j++)
      if (arr[j][0] != -1) {
        dp[i] = arr[j][1];
        nowlen = arr[j][0] + 1;
      }
    if (arr[strin[i] - 'a'][0] < nowlen) {
      arr[strin[i] - 'a'][0] = nowlen;
      arr[strin[i] - 'a'][1] = i;
    }
  }
  for (int j = 25; j >= 0; j--)
    if (arr[j][0] != -1) {
      int t = arr[j][1];
      while (t != -1) {
        printf("%c", strin[t]);
        t = dp[t];
      }
      break;
    }
  printf("\n");
}
