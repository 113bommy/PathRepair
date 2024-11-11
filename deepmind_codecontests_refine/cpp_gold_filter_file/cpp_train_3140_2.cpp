#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
const int maxn = 2020;
long long dp[maxn][maxn];
long long rev[maxn + maxn];
int pt[maxn];
char s[maxn];
int main() {
  scanf("%s", s);
  rev[1] = 1;
  for (int i = 2; i <= 4000; i++)
    rev[i] = (rev[mod % i] * (mod - mod / i)) % mod;
  if (s[0] == '/' || s[0] == '*') {
    printf("0\n");
    return 0;
  }
  int len = strlen(s);
  for (int i = (0); i < (int)(len - 1); ++i)
    if ((s[i] < '0' || s[i] > '9') && (s[i + 1] == '/' || s[i + 1] == '*')) {
      printf("0\n");
      return 0;
    }
  if (s[len - 1] < '0' || s[len - 1] > '9') {
    printf("0\n");
    return 0;
  }
  int con = 0;
  int div = 0;
  for (int i = (0); i < (int)(len); ++i) {
    if (s[i] < '0' || s[i] > '9')
      con++;
    else if (con || i == 0) {
      pt[div++] = con - 1;
      con = 0;
    }
  }
  pt[0]++;
  dp[div - 1][1] = 1;
  for (int i = (int)(div - 1) - 1; i >= 0; --i) {
    int mx = div - i;
    long long comb = 1;
    for (int j = (0); j < (int)(mx + 1); ++j) {
      for (int k = (j); k < (int)(mx + 1); ++k) {
        dp[i][k] += 1LL * (dp[i + 1][k - j] * comb);
      }
      dp[i][j] %= mod;
      comb = comb * (pt[i] + j + 1) % mod * rev[j + 1] % mod;
    }
  }
  printf("%d\n", dp[0][div]);
  return 0;
}
