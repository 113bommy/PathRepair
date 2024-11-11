#include <bits/stdc++.h>
using namespace std;
long long sol;
long long res[2550][2550];
int n;
char s[5500];
long long compute(int l, int r) {
  long long ans = res[l][r];
  int i, j;
  for (i = l; i > 0 && s[i << 1] == '*'; i--) ans *= (s[(i << 1) - 1] - '0');
  for (j = r + 1; j <= (n >> 1) && s[j << 1] == '*'; j++)
    ans *= (s[(j << 1) + 1] - '0');
  if (i > 0) ans += res[0][i - 1];
  if (j <= (n >> 1)) ans += res[j][n >> 1];
  return ans;
}
int main() {
  int k;
  scanf("%s\n", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i += 2) {
    res[i >> 1][i >> 1] = s[i] - '0';
    for (int j = i + 2; j <= n; j++)
      if (s[j - 1] == '+')
        res[i >> 1][j >> 1] = res[i >> 1][(j - 2) >> 1] + s[j] - '0';
      else {
        long long P = s[j] - '0';
        for (k = j - 1; k >= i && s[k] == '*'; k -= 2) P *= (s[k - 1] - '0');
        if (k >= i) P += res[i >> 1][(k - 1) >> 1];
        res[i >> 1][j >> 1] = P;
      }
  }
  for (int i = 0; i <= (n >> 1); i++)
    for (int j = i; j <= (n >> 1); j++) {
      int x = compute(i, j);
      if (x > sol) sol = x;
    }
  printf("%I64d\n", sol);
  return 0;
}
