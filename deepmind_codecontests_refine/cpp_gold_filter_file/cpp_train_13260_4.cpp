#include <bits/stdc++.h>
using namespace std;
char str[1000010];
int dp[1000010][2];
int a[1000010], b[1000011];
int main() {
  scanf("%s", str);
  int n = strlen(str);
  n++;
  for (int i = 0; i < n - 1; i++) a[i + 1] = str[i] - '0';
  while (n > 0 && a[n - 1] == 0) n--;
  for (int i = 0; i < n; i++) b[i] = 1 - a[i];
  b[n - 1]++;
  a[0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i][0] = dp[i + 1][0] + a[i];
    if (b[i] == 0) dp[i][0] = min(dp[i][0], dp[i + 1][1] + 1);
    dp[i][1] = dp[i + 1][1] + b[i];
    if (a[i] == 0) dp[i][1] = min(dp[i][1], dp[i + 1][0] + 1);
  }
  printf("%d\n", dp[0][0]);
}
