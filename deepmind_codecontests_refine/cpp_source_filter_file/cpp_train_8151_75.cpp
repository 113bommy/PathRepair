#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int temp = (k * l) / n;
  int temp1 = (c * d);
  int temp2 = p / np;
  int ans = min(temp, temp1);
  ans = min(ans, temp2);
  ans = ans / n;
  cout << ans;
  return 0;
}
