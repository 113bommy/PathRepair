#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int c[1000001];
long long int ans = 0;
int exgcd(long long &x, long long int &y, int a, int b) {
  int t = a;
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    t = exgcd(y, x, b, a % b);
    y -= x * a / b;
  }
  return t;
}
void getC() {
  c[0] = c[n] = 1;
  for (int i = 1; i <= n / 2; i++) {
    long long int rev_i, y;
    exgcd(rev_i, y, i, 998244353);
    rev_i = (rev_i + 998244353) % 998244353;
    c[i] = c[n - i] = c[i - 1] * (n + 1 - i) % 998244353 * rev_i % 998244353;
  }
}
long long powx(long long int x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long xt = powx(x, y / 2);
  if (y & 1) {
    return xt * xt % 998244353 * x % 998244353;
  } else {
    return (xt * xt) % 998244353;
  }
}
long long int getAns0() {
  long long ans0 = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      ans0 += c[i] * powx(3, n * (n - i) + i) * 2;
    else
      ans0 -= c[i] * powx(3, n * (n - i) + i) * 2;
    ans0 %= 998244353;
  }
  ans0 += 998244353;
  return ans0 % 998244353;
}
int main() {
  cin >> n;
  if (n == 1) {
    cout << 3 << endl;
    return 0;
  }
  getC();
  long long int ans = getAns0();
  for (int i = 0; i <= n - 1; i++) {
    long long item =
        3 * c[i] *
        (powx((-powx(3, i) + 1) % 998244353, n) - powx(-powx(3, i), n)) %
        998244353;
    if (i & 1)
      ans += item;
    else
      ans -= item;
    ans %= 998244353;
  }
  ans += 998244353;
  cout << ans % 998244353 << endl;
  return 0;
}
