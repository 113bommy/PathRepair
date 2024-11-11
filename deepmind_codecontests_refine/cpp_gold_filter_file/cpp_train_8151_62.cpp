#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int a = (k * l) / nl;
  int b = (c * d);
  int x = p / np;
  int min;
  if ((a <= b) && (a <= x)) min = a;
  if ((a >= b) && (b <= x)) min = b;
  if ((x <= b) && (a >= x)) min = x;
  int ans = min / n;
  cout << ans;
  return 0;
}
