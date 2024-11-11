#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long mod = 1e9 + 7;
long long n, k;
long long PHI(long long n) {
  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n != 1) ans = ans / n * (n - 1);
  return ans;
}
long long F(long long n, long long k) {
  long long t = n;
  for (long long now = 1; now <= k; now += 2) {
    t = PHI(t);
    if (t == 1) break;
  }
  return t % mod;
}
int main() {
  cin >> n >> k;
  if (k % 2 == 0) k--;
  printf("%lld\n", F(n, k));
}
