#include <bits/stdc++.h>
using namespace std;
long long int p = 998244353;
long long int modpower(long long int base, long long int power,
                       long long int mod = p) {
  long long int ans = 1;
  base %= p;
  while (power) {
    if (power & 1) {
      ans *= base;
      ans %= p;
    }
    base *= base;
    base %= p;
    power >>= 1;
  }
  return ans;
}
long long int fact[200007];
long long int invfact[200007];
void computefactorial() {
  fact[0] = 1;
  for (int i = 1; i < 200007; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= p;
  }
  invfact[200006] = modpower(fact[200006], p - 2);
  for (int i = 200005; i >= 0; i--) {
    invfact[i] = (i + 1) * invfact[i + 1];
    invfact[i] %= p;
  }
}
long long int ncr(int n, int r) {
  return ((fact[n] * invfact[n - r]) % p * invfact[r]) % p;
}
long long int solve() {
  long long int n, k;
  cin >> n >> k;
  int h[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    if (i) {
      if (h[i] != h[i - 1]) {
        count++;
      }
    }
  }
  if (h[0] != h[n - 1]) {
    count++;
  }
  long long int ans = 0;
  for (int i = 1; i <= count; i++) {
    long long int curr = ncr(count, i);
    curr *= modpower(k - 2, count - i);
    curr %= p;
    if (i & 1) {
      curr *= modpower(2, i - 1);
      curr %= p;
      ans += curr;
      ans % p;
    } else {
      long long int curr2 = modpower(2, i);
      curr2 -= ncr(i, (i >> 1));
      if (curr2 < 0) {
        curr2 += p;
      }
      curr2 *= invfact[2];
      curr2 %= p;
      curr *= curr2;
      curr %= p;
      ans += curr;
      ans % p;
    }
  }
  ans *= modpower(k, n - count);
  ans %= p;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  computefactorial();
  cout << solve();
}
