#include <bits/stdc++.h>
using namespace std;
bool noprime[5000010] = {false};
int fac[5000010];
long long dp[5000010];
void _init() {
  memset(noprime, 0, sizeof(noprime));
  for (int i = 1; i < 5000010; i++) {
    fac[i] = i;
  }
  for (int i = 2; i < 5000010; i++) {
    if (noprime[i] == false) {
      for (int j = 2; j * i < 5000010; j++) {
        fac[i * j] = min(fac[i * j], i);
        noprime[i * j] = true;
      }
    }
  }
  dp[2] = 1;
  for (int i = 3; i < 5000010; i++) {
    if (!noprime[i]) {
      dp[i] = (i * (i - 1)) / 2;
      dp[i] %= 1000000007ll;
    } else {
      dp[i] = dp[fac[i]] * (i / fac[i]) + dp[i / fac[i]];
      dp[i] %= 1000000007ll;
    }
  }
}
int main() {
  _init();
  long long t, l, r;
  while (scanf("%lld%lld%lld", &t, &l, &r) != EOF) {
    long long mi = 1;
    long long ans = 0;
    for (int i = l; i <= r; i++) {
      ans += (mi * dp[i]) % 1000000007ll;
      ans %= 1000000007ll;
      mi *= t;
      mi %= 1000000007ll;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
