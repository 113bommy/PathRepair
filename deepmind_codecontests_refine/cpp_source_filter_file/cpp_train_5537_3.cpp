#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long i, a1, a2, k1, k2, res1 = 0, res2 = 0, sum, SUM, c, temp;
  cin >> a1 >> a2 >> k1 >> k2 >> SUM;
  sum = SUM;
  temp = (k1 - 1) * a1 + (k2 - 1) * a2;
  if (sum - temp > 0) {
    if (sum - temp < a1 + a2)
      cout << sum - temp;
    else
      cout << a1 + a2;
  } else
    cout << 0;
  if (k1 > k2) {
    c = k1;
    k1 = k2;
    k2 = c;
    c = a1;
    a1 = a2;
    a2 = c;
  }
  if (a1 < sum / k1) {
    res2 += a1;
    sum -= a1 * k1;
  } else {
    res2 += sum / k1;
    sum -= res2 * a1;
  }
  if (a2 < sum / k2) {
    res2 += a2;
    sum -= a2 * k2;
  } else {
    res2 += sum / k2;
    sum -= res2 * a2;
  }
  cout << " " << res2;
  return 0;
}
