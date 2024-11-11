#include <bits/stdc++.h>
int num[10000];
int dp[1000];
int pre[1000];
int main() {
  int a[4];
  int b[4];
  int ans = 0;
  for (int i = 1; i < 4; ++i) scanf("%d", a + i);
  for (int i = 1; i < 4; ++i) scanf("%d", b + i);
  for (int i = 1; i < 4; ++i)
    if (a[i] == b[i]) ans++;
  if (ans)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
