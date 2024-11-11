#include <bits/stdc++.h>
using namespace std;
int main() {
  long long nx2 = 1, nc2;
  long long h1, h2, a1, a2, x1, x2, b, c, m;
  cin >> m;
  cin >> h1 >> a1 >> x1 >> b;
  cin >> h2 >> a2 >> x2 >> c;
  long long sum1 = 0, sum2 = 0;
  while (h1 != a1 && sum1 <= m) {
    h1 = (h1 * x1 + b) % m;
    h2 = (h2 * x2 + c) % m;
    sum1++;
  }
  if (h1 != a1) {
    cout << -1;
    return 0;
  }
  if (h2 == a2) {
    cout << sum1;
    return 0;
  }
  long long sum3 = 0;
  while (sum2 <= m && (h1 != a1) || sum2 == 0) {
    h1 = (x1 * h1 + b) % m;
    sum2++;
    nx2 = (nx2 * x2) % m;
    nc2 = (nc2 * x2 + c) % m;
  }
  if (h1 != a1) {
    cout << -1;
    return 0;
  }
  while (sum3 <= m && h2 != a2) {
    h2 = (nx2 * h2 + nc2) % m;
    sum3++;
  }
  cout << (h2 == a2 ? sum1 + sum2 * sum3 : -1) << endl;
  return 0;
}
