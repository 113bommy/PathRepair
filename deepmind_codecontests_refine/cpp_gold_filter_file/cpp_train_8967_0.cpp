#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e6 + 3;
long long int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  long long int r;
  scanf("%lld", &r);
  return r;
}
void ex_(long long int x) {
  printf("! %lld", x);
  exit(0);
}
long long int pows(long long int now, int num) {
  if (num == 0) return 1;
  if (num == 1) return now;
  long long int nn = pows(now, num / 2);
  if (num % 2 == 0) return (nn * nn) % mod;
  return (((nn * nn) % mod) * now) % mod;
}
long long int dp[11][11], dp2[11], dp3[11];
int main(void) {
  for (int e = 0; e <= 10; e++) dp2[e] = (query(e));
  dp[0][0] = 1;
  for (int e = 1; e <= 10; e++) {
    long long int x = 1;
    for (int p = 0; p <= 10; p++) {
      dp[e][p] = x;
      x = (x * (long long int)e) % mod;
    }
  }
  for (int e = 0; e <= 10; e++) {
    for (int p = 10; p > e; p--) {
      for (int r = e + 1; r <= 10; r++) {
        dp[p][r] = (dp[p][r] - dp[p - 1][r] + mod) % mod;
      }
      dp2[p] = (dp2[p] - dp2[p - 1] + mod) % mod;
    }
  }
  long long int x = 1;
  for (int e = 1; e <= 10; e++) {
    x = (x * (long long int)e) % mod;
    dp2[e] = (dp2[e] * pows(x, mod - 2)) % mod;
    for (int p = e; p <= 10; p++)
      dp[e][p] = (dp[e][p] * pows(x, mod - 2)) % mod;
  }
  dp3[10] = dp2[10];
  for (int e = 9; e >= 0; e--) {
    for (int p = 10; p > e; p--) {
      dp2[e] = (dp2[e] - (dp[e][p] * dp3[p]) % mod + mod) % mod;
    }
    dp3[e] = dp2[e];
  }
  for (int e = 0; e < mod; e++) {
    long long int val = 0, x = 1;
    for (int p = 0; p <= 10; p++) {
      val = (val + (dp3[p] * x) % mod) % mod;
      x = (x * (long long int)e) % mod;
    }
    if (val == 0) {
      printf("! %d", e);
      return 0;
    }
  }
  printf("! -1");
  return 0;
}
