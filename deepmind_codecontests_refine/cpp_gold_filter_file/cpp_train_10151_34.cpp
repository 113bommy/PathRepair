#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (1) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}
long long int lcm(long long int a, long long int b) {
  long long int t = gcd(a, b);
  return (a / t) * b;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, w, b, l, r;
  cin >> t >> w >> b;
  if (w == b) {
    cout << "1/1";
    return 0;
  }
  if (w < b) {
    l = w;
    r = b;
  } else {
    r = w;
    l = b;
  }
  if (t < l) {
    cout << "1/1";
    return 0;
  }
  long long int lc = lcm(l, r);
  long long int t1 = lc;
  long long int ans = l - 1;
  if (lc < 0) lc = t + 1;
  t1 = (t / lc) * lc;
  ans += (t / lc) * l;
  if (t - t1 < l) {
    ans = ans - l + t - t1 + 1;
  }
  long long int s = gcd(l, r);
  if (w / s > t / b) ans = l - 1;
  long long int g = gcd(ans, t);
  cout << (ans / g) << '/' << (t / g);
  return 0;
}
