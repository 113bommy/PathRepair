#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b) {
  return a + b > 1000000007 ? a + b - 1000000007 : a + b;
}
char s[100100], t[100100];
int k[100100], ns, nt, dp1[100100], dp2[100100], dp[100100], lps[100100];
int main() {
  scanf("%s%s", s, t);
  ns = strlen(s);
  nt = strlen(t);
  k[0] = 0;
  int i = 0, j = 1;
  while (j < nt)
    if (t[i] == t[j])
      k[j++] = ++i;
    else if (i != 0)
      i = k[i - 1];
    else
      k[j++] = 0;
  memset(lps, 0, sizeof(lps));
  i = j = 0;
  while (i < ns) {
    if (s[i] == t[j]) {
      i++;
      j++;
    }
    if (j == nt) {
      lps[i - 1] = nt;
      j = k[j - 1];
    } else if (i < ns && s[i] != t[j])
      if (j != 0)
        j = k[j - 1];
      else
        i++;
  }
  if (nt == 1 && s[0] == t[0]) dp[0] = dp1[0] = dp2[0] = 1;
  for (long long i = 1; i < ns; i++) {
    if (lps[i] != nt)
      dp1[i] = dp1[i - 1];
    else
      dp1[i] = add(dp2[i - nt], i - nt + 2);
    dp[i] = add(dp1[i], dp[i - 1]);
    dp2[i] = add(dp2[i - 1], dp[i]);
  }
  printf("%d\n", dp[ns - 1]);
  return 0;
}
