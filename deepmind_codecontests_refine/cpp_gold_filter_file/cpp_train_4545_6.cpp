#include <bits/stdc++.h>
using namespace std;
int dp[5555];
char res[5555], s[5555];
int main(void) {
  scanf("%s", &s);
  int m = 1, k = 1;
  int n = strlen(s);
  while (m * 2 <= n) m *= 2, k++;
  m--;
  for (int i = 0; i <= m; i++) dp[i] = 1;
  for (int i = 0; i < n - m; i++) {
    char x = 'z';
    for (int j = 0; j <= m; j++)
      if (dp[j]) x = min(x, s[i + j]);
    for (int j = i; j < n; j++)
      if (s[j] != x) dp[j - i] = 0;
    for (int j = 0; j < 15; j++)
      for (int k = 0; k <= m; k++)
        if (k & (1 << j)) dp[k] |= dp[k ^ (1 << j)];
    res[i] = x;
  }
  res[n - m] = 0;
  printf("%s\n", res);
}
