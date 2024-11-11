#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
long long a[N], b[N], n, p, sum;
int main() {
  cin >> n >> p;
  for (int i = int(1); i <= int(n); i++) {
    cin >> a[i] >> b[i];
    sum += a[i];
  }
  if (p >= sum) {
    cout << -1;
    return 0;
  }
  double l = 0, r = 1e13, mid;
  for (int i = int(1); i <= int(60); i++) {
    mid = (l + r) / 2.0;
    double tl = 0;
    for (int j = int(1); j <= int(n); j++) {
      tl += max(0.0, mid * a[j] - b[j]);
    }
    if (tl <= p * mid)
      l = mid;
    else
      r = mid;
  }
  cout << l;
}
