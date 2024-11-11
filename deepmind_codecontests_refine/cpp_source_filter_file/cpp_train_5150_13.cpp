#include <bits/stdc++.h>
using namespace std;
const double LIM = 0.0000001;
int main() {
  int n, pr = 0, t;
  double min = 0, max = 1001;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    if (max > (t + 1) * 10.0 / i) max = (t + 1) * 10.0 / i;
    if (min < t * 10.0 / i) min = t * 10.0 / i;
    pr = t;
  }
  if ((int)((min + LIM) * (n + 1) / 10) == (int)((max - LIM) * (n + 1) / 10)) {
    cout << "unique\n";
    cout << (int)((min + LIM) * (n + 1) / 10);
  } else
    cout << "not unique";
  return 0;
}
