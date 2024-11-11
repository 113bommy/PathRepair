#include <bits/stdc++.h>
using namespace std;
int a[101][2501];
int main() {
  a[0][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int j = 0; j <= 25 * i; j++)
      for (int k = 0; k < 26; k++)
        if (j - k >= 0 && j - k <= 25 * (i - 1))
          a[i][j] = (a[i][j] + a[i - 1][j - k]) % 1000000007;
  int t;
  scanf("%d", &t);
  for (int cases = 0; cases < t; cases++) {
    char s[101];
    scanf("%s", s);
    int n = strlen(s), total = 0;
    for (int i = 0; i < n; i++) total += s[i] - 'a';
    int ans = a[n][total] - 1;
    if (ans < 0) ans += 1000000007;
    printf("%d\n", ans);
  }
  return 0;
}
