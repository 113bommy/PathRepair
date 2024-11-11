#include <bits/stdc++.h>
using namespace std;
const long long MX = 100000;
const long long MOD = 1000000007;
long long fast_exp(long long base, long long exp, long long mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}
long long dp1[11111];
long long dp2[11111];
long long dp3[11111];
int main() {
  long long k, n1, n2, n3, t1, t2, t3;
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  for (int i = 1; i <= k; i++) {
    if (i <= n1)
      dp1[i] = t1;
    else
      dp1[i] = dp1[i - n1] + t1;
  }
  for (int i = 1; i <= k; i++) {
    if (i <= n2)
      dp2[i] = dp1[i] + t2;
    else
      dp2[i] = t2 + max(dp1[i], dp2[i - n2]);
  }
  for (int i = 1; i <= k; i++) {
    if (i <= n3)
      dp3[i] = t3 + dp2[i];
    else
      dp3[i] = t3 + max(dp2[i], dp3[i - n2]);
  }
  long long mx = -1;
  for (int i = 1; i <= k; i++) mx = max(mx, dp3[i]);
  cout << mx;
  return 0;
}
