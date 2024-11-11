#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int dt[100005];
int a[26];
char ch1[100005];
char ch2[100005];
int gao(void) {
  int i;
  int l1 = strlen(ch1 + 1);
  int l2 = strlen(ch2 + 1);
  for (i = 1; i <= l1; i++) {
    if (dp[i] < dt[i]) return 0;
  }
  return 1;
}
int main() {
  scanf("%s", ch1 + 1);
  scanf("%s", ch2 + 1);
  int l1 = strlen(ch1 + 1);
  int l2 = strlen(ch2 + 1);
  dp[0] = 0;
  int i;
  for (i = 0; i <= 25; i++) a[i] = -(1 << 30);
  a[ch2[1] - 'a'] = 1;
  for (i = 1; i <= l1; i++) {
    dp[i] = a[ch1[i] - 'a'];
    if (dp[i] < l2 && dp[i] >= 1)
      a[ch2[dp[i] + 1] - 'a'] = max(a[ch2[dp[i] + 1] - 'a'], dp[i] + 1);
  }
  dt[l1 + 1] = l2 + 1;
  for (i = 0; i <= 25; i++) a[i] = (1 << 30);
  a[ch2[l2] - 'a'] = l2;
  for (i = l1; i >= 1; i--) {
    dt[i] = a[ch2[i] - 'a'];
    if (dt[i] <= l2 && dt[i] > 1)
      a[ch2[dt[i] - 1] - 'a'] = min(a[ch2[dt[i] - 1] - 'a'], dt[i] - 1);
  }
  int z = gao();
  if (z)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
