#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
char s[N], t[N];
long long dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  scanf("\n%s %s", s, t);
  dp[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] * 2;
    if (s[i - 1] == 'b') {
      dp[i]--;
    }
    if (t[i - 1] == 'a') {
      dp[i]--;
    }
    dp[i] = min(dp[i], k + 10LL);
  }
  long long sum = 0LL;
  for (int i = 1; i <= n; i++) {
    sum += min(dp[i], k);
  }
  printf("%lld\n", sum);
  return 0;
}
