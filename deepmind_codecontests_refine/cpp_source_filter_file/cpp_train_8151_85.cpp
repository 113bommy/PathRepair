#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np, mul, mul1, mul2, ans;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  mul = k * l;
  mul = mul / 3;
  mul1 = c * d;
  mul2 = p / np;
  ans = min(mul, min(mul1, mul2));
  ans = ans / n;
  cout << ans;
}
