#include <bits/stdc++.h>
using namespace std;
int n;
const int mxn = (int)1e5 + 7;
const int mod = 1000000007;
int primes[mxn / 2];
bool sv[mxn];
int psz = 0;
int calc(int n, int p) {
  int ret = 0;
  for (long long i = p; i <= n; i *= p) {
    ret += n / i;
  }
  return ret;
}
int main() {
  for (int i = 2; i < mxn; i++)
    if (!sv[i]) {
      for (int j = i + i; j < mxn; j += i) {
        sv[j] = 1;
      }
      primes[psz++] = i;
    }
  cin >> n;
  --n;
  long long ans = 1;
  for (int i = 0; i < psz && primes[i] <= 2 * n + 1; i++) {
    int pw = calc(2 * n + 1, primes[i]) - calc(n, primes[i]) -
             calc(n + 1, primes[i]);
    long long cp = primes[i];
    while (pw > 0) {
      if (pw & 1) {
        ans = (ans * cp) % mod;
      }
      cp = (cp * cp) % mod;
      pw >>= 1;
    }
  }
  ans = (2 * ans - n - 1 + mod) % mod;
  cout << ans << endl;
  return 0;
}
