#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  long long drink, salt, lime;
  drink = (k * l) / n;
  salt = p / np;
  lime = c * d;
  long long ans = min(drink, min(salt, lime)) / n;
  cout << ans;
  return 0;
}
