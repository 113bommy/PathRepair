#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int kl = (k * l) / nl, cd = c * d, pnp = p / np;
  int ans = (min(kl, min(cd, pnp))) / n;
  cout << ans;
  return 0;
}
