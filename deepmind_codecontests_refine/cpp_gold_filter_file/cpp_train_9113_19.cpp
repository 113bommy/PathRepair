#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = 1e18 + 10;
const int BASE = 1e6 + 3;
long long n, k;
long long count_num2(long long x) {
  long long res = 0;
  while (x > 0) {
    res += x / 2;
    x /= 2;
  }
  return res;
}
long long mul(long long a, long long b) { return (a * b) % BASE; }
long long power(long long x, long long n) {
  if (n == 0) return 1;
  long long tmp = power(x, n / 2);
  tmp = mul(tmp, tmp);
  if (n & 1) tmp = mul(tmp, x);
  return tmp;
}
void process() {
  cin >> n >> k;
  long long p2n = 1;
  bool check = true;
  for (int i = 1; i <= n; i++) {
    p2n *= 2;
    if (p2n >= k) {
      check = false;
      break;
    }
  }
  if (check) {
    cout << 1 << " " << 1;
    return;
  }
  long long num2 = count_num2(k - 1);
  long long numer = 1;
  if (k - 1 >= BASE) {
    numer = 0;
  } else {
    long long p2n = power(2, n);
    for (int i = 1; i <= k - 1; i++) numer = mul(numer, p2n - i);
  }
  long long deno = power(power(2, n), k - 1);
  numer = (deno - numer) % BASE;
  long long rev_gcd = power(power(2, num2), BASE - 2);
  numer = mul(numer, rev_gcd);
  deno = mul(deno, rev_gcd);
  if (numer < 0) numer += BASE;
  if (deno < 0) deno += BASE;
  cout << numer << " " << deno;
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
