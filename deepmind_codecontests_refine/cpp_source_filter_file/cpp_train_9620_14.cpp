#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int dp[1000010];
int main() {
  int i, j, n, top = 0;
  scanf("%s", s + 1);
  for (i = 1; s[i] == 'F'; i++) top++;
  for (i; s[i]; i++)
    if (s[i] == 'F') {
      top++;
      if (i - top >= dp[top - 1])
        dp[top] = i - top;
      else
        dp[top] = dp[top - 1] + 1;
    }
  printf("%d\n", dp[top]);
  return 0;
}
