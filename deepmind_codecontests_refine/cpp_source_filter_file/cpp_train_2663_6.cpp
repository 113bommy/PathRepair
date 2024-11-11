#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N];
int ans3[N];
char str[N];
int a[30];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str + 1);
  for (int i = 0; i < 26; i++) scanf("%d", &a[i]);
  dp[0] = 1;
  int ans2 = 1;
  ans3[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    ans3[i] = ans3[i - 1] + 1;
    int mlen = a[str[i] - 'a'];
    for (int j = i - 1; j >= 1; j--) {
      int len = i - j + 1;
      mlen = min(mlen, a[str[j] - 'a']);
      if (mlen < len) break;
      ans2 = max(ans2, len);
      dp[i] = (dp[i] + dp[j - 1]) % 1000000007;
      ans3[i] = min(ans3[i], ans3[j - 1] + 1);
    }
  }
  printf("%d\n", dp[n]);
  printf("%d\n", ans2);
  printf("%d\n", ans3[n]);
  return 0;
}
