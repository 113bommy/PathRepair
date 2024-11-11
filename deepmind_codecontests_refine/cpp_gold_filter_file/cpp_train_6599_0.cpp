#include <bits/stdc++.h>
using namespace std;
inline void Fail() {
  printf("0");
  exit(0);
}
const int maxn = 100005;
int n, q;
char c[maxn];
unsigned int dp[maxn];
int main() {
  scanf("%d%s", &n, c);
  for (int(i) = 0; (i) < n; i++)
    if (c[i] == '?') q++;
  if (n & 1 || q * 2 < n) {
    printf("0");
    return 0;
  }
  dp[0] = 1;
  for (int(i) = 0; (i) < n; i++) {
    int l = i + 1 - n / 2, r = (i + 1) / 2;
    if (c[i] == '?')
      for (int j = r; j >= l && j >= 1; j--) dp[j] += dp[j - 1];
  }
  unsigned int ans = dp[n / 2];
  for (int(i) = 0; (i) < q - n / 2; i++) ans *= 25;
  printf("%I64d", (long long)ans);
  return 0;
}
