#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 9;
long long power(long long x, long long y) {
  if (y == 1) return x;
  if (y == 0) return 1;
  long long temp = power(x, y / 2);
  temp %= mod;
  temp *= temp;
  temp %= mod;
  if (y % 2) temp *= x % mod;
  return temp % mod;
}
long long fact[1000000 + 9];
int main() {
  long long n;
  cin >> n;
  for (int i = 2; i <= 1e6 + 9; i++) {
    if (fact[i] > 0) {
      continue;
    }
    for (int l = i * 2; l <= 1e6; l += i) {
      fact[l] = i;
    }
  }
  long long ans = n;
  for (int i = n - fact[n] + 1; i <= n; i++) {
    ans = min(ans, i - fact[i] + 1);
  }
  cout << ans;
}
