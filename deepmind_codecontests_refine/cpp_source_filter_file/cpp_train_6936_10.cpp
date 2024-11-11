#include <bits/stdc++.h>
using namespace std;
const long long int maxi = 1000005;
long long int spf[maxi], fact[maxi];
long long int power(long long int x, long long int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    long long int tmp = power(x, n / 2);
    tmp *= tmp;
    tmp %= 1000000007;
    return tmp;
  } else {
    long long int tmp = power(x, n - 1);
    tmp *= x;
    tmp %= 1000000007;
    return tmp;
  }
}
void fill() {
  fact[0] = 1;
  for (long long int i = 1; i < maxi; i++) {
    spf[i] = i;
    fact[i] = fact[i - 1] * i;
    fact[i] %= 1000000007;
  }
  for (long long int i = 2; i * i < maxi; i++) {
    if (spf[i] == i) {
      for (long long int j = i * i; j < maxi; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}
long long int modInv(long long int n, long long int p) {
  return power(n, p - 2);
}
long long int calulate(long long int n, long long int r) {
  long long int ans = 1;
  if (r == 0) {
    return 1;
  }
  ans *= fact[n];
  ans %= 1000000007;
  ans *= modInv(fact[r], 1000000007);
  ans %= 1000000007;
  ans *= modInv(fact[n - r], 1000000007);
  ans %= 1000000007;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fill();
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    long long int ans = power(2, y - 1);
    while (x > 1) {
      long long int tmpPow = 0;
      long long int p = spf[x];
      while (x % p == 0) {
        tmpPow++;
        x /= p;
      }
      ans *= calulate(y + tmpPow - 1, tmpPow);
      ans %= 1000000007;
    }
    cout << ans << '\n';
  }
  return 0;
}
