#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, l, c, d, p, nl, np;
  int ans;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  ans = min({(k * l) / nl, c * d, p / np}) / n;
  cout << ans;
}
