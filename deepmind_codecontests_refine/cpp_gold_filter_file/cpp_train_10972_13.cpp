#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 9;
long long add(long long a, long long b) {
  if (a + b < 0) return a + b + mod;
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
long long mult(long long a, long long b) { return (a * b) % mod; }
long long myPow(long long a, long long k) {
  if (k == 0) return (long long)1;
  if (k & (long long)1)
    return mult(myPow(a, k - 1), a);
  else {
    long long t = myPow(a, k / 2);
    return mult(t, t);
  }
}
int main() {
  long long k, n, m;
  cin >> n >> m >> k;
  long long l1 = -1, r1 = (long long)1e9;
  while (r1 - l1 > 1) {
    long long m1 = (l1 + r1) / 2;
    long long newS = m - m1 * k;
    long long newL = n - m1 * k;
    if (newS < 0 || newL <= 0)
      r1 = m1;
    else {
      long long tt = newL / k;
      if (newL - tt >= newS)
        r1 = m1;
      else
        l1 = m1;
    }
  }
  long long ans = mult(add(myPow(2, r1 + 1), -2), k);
  ans = add(ans, m - k * r1);
  cout << ans;
  return 0;
}
