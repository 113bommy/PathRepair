#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np, ans, ans1;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  ans = min((k * l) / nl, (c * d));
  ans1 = (min(ans, (p / np))) / n;
  cout << ans1 << endl;
}
