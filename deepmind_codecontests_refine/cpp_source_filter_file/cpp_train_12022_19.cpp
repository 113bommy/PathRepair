#include <bits/stdc++.h>
using namespace std;
int n, l[8], r[8], tr = 1000000;
double lessp(int l, int r, int p) {
  if (p < l) return 0;
  if (p > r) return 1;
  return (p - l) * 1.0 / (r - l + 1);
}
double calc(int v) {
  double p1 = 1;
  for (int i = 1; i <= n; i++) p1 *= lessp(l[i], r[i], v);
  for (int i = 1; i <= n; i++) {
    double p0 = (1 - lessp(l[i], r[i], v));
    for (int j = 1; j <= n; ++j)
      if (i != j) p0 *= lessp(l[j], r[j], v);
    p1 += p0;
  }
  return 1 - p1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    tr = min(tr, r[i]);
  }
  double ans = 0;
  for (int i = 1; i <= tr; i++) ans += calc(i);
  cout.precision(10);
  cout << ans;
  return 0;
}
