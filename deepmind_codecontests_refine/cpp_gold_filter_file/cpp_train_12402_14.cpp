#include <bits/stdc++.h>
using namespace std;
long long powmod(long long base, long long exponent, long long mod) {
  long long ans = 1;
  while (exponent) {
    if (exponent & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    exponent /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
const int upperlimit = 1e6 + 100;
const int mod = 1e9 + 7;
int pr[upperlimit];
int fbit[32];
int first_bit(int n) {
  int ans = 0;
  while (n > 0) {
    ans++;
    n /= 2;
  }
  return ans;
}
int main() {
  int n, inp;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &inp);
    pr[i] = pr[i - 1] ^ inp;
  }
  if (pr[n] == 0) {
    printf("%d", -1);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int temp = pr[i];
    for (int j = 31; j >= 0; j--)
      if ((temp ^ fbit[j]) < temp) temp ^= fbit[j];
    if (temp != 0) fbit[first_bit(temp)] = temp;
  }
  int ans = 0;
  for (int i = 31; i > 0; i--)
    if (fbit[i]) ans++;
  printf("%d", ans);
  return 0;
}
