#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int len;
int gao(int x) {
  int ci = 2;
  while (x <= len) {
    if (dp[x] + dp[x - 1] == 9)
      ci++;
    else
      break;
    x++;
  }
  return ci;
}
int main() {
  char s[100005];
  scanf("%s", s);
  len = strlen(s);
  for (int i = 0; i < len; i++) dp[i + 1] = s[i] - '0';
  long long int ans = 0;
  int i = 1;
  while (i <= len) {
    if (dp[i] + dp[i + 1] == 9) {
      int x = gao(i + 2);
      if (x % 2 == 0) {
        i += x - 1;
        continue;
      } else {
        ans += (x + 1) / 2;
        i += x - 1;
        continue;
      }
    }
    i++;
  }
  if (ans == 0)
    printf("1");
  else
    printf("%I64d", ans);
  return 0;
}
