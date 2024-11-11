#include <bits/stdc++.h>
using namespace std;
long long n, l, r;
long long expo(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) x = (x * y);
    y = (y * y);
    b = b / 2;
  }
  return x;
}
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long func() {
  long long ans = 0;
  if (n == 1)
    ans = r - l + 1;
  else if (n == 2)
    ans = (r - l + 1) * (r - l);
  else if (n <= log2(r) + 2) {
    for (long long den = 1;; den++) {
      long long val1 = expo(den, n - 1);
      if (val1 > r) break;
      for (long long num = den + 1;; num++) {
        long long val2 = expo(num, n - 1);
        if (val2 > r) break;
        if (gcd(den, num) == 1) {
          long long R = r / val2;
          long long L = l / val1 + (l % val1 != 0);
          ans += max(R - L + 1, 0LL);
        }
      }
    }
  }
  if (n > 2) ans = ans * 2LL;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> l >> r;
  cout << func() << endl;
}
