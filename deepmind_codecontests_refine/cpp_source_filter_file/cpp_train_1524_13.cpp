#include <bits/stdc++.h>
using namespace std;
int n, k;
const long long mod = 1e9 + 7;
long long D[1000002], S[1000002], gt[1000002];
long long pow(long long a, long long n) {
  if (n == 0) return 1;
  long long ans = pow(a, n / 2);
  ans *= ans;
  ans %= mod;
  if (n % 2 == 1) ans *= a;
  ans %= mod;
  return ans;
}
int main() {
  cin >> n >> k;
  gt[0] = 1;
  for (int i = 1; i <= n; i++) gt[i] = (gt[i - 1] * i) % mod;
  for (int i = k + 2; i <= n; i++) {
    D[i] = (i - k - 1) * gt[i - 2];
    D[i] %= mod;
    D[i] += gt[i - 2] * (S[i - 1] - S[n - k - 1]);
    D[i] %= mod;
    S[i] = S[i - 1] + D[i] * pow(gt[i - 1], mod - 2);
    S[i] %= mod;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    long long t = D[i];
    t *= gt[n - 1];
    t %= mod;
    t *= pow(gt[i - 1], mod - 2);
    t %= mod;
    res += t;
    res %= mod;
  }
  cout << res;
}
