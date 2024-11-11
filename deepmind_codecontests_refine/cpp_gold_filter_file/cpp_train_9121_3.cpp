#include <bits/stdc++.h>
using namespace std;
char s[1000] =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
char ss[1000] = "What are you doing while sending \"";
char c[1000] = "\"? Are you busy? Will you send \"";
char cc[1000] = "\"?";
long long dp[100007];
char print(long long n, long long m) {
  if (!n) return s[m - 1];
  if (m <= 34) return ss[m - 1];
  m -= 34;
  if (m <= dp[n - 1]) return print(n - 1, m);
  m -= dp[n - 1];
  if (m <= 32) return c[m - 1];
  m -= 32;
  if (m <= dp[n - 1]) return print(n - 1, m);
  m -= dp[n - 1];
  return cc[m - 1];
}
int main() {
  long long n, m;
  int q;
  dp[0] = 75;
  for (int i = 1; i <= 100000; i++) {
    if (dp[i - 1] > 1e18)
      dp[i] = dp[i - 1];
    else
      dp[i] = 68 + (dp[i - 1] << 1);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%lld%lld", &n, &m);
    if (m > dp[n])
      printf(".");
    else
      printf("%c", print(n, m));
  }
  return 0;
}
