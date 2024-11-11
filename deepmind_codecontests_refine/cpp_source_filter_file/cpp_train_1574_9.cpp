#include <bits/stdc++.h>
using namespace std;
int n, b[10], l[10], A;
double prob = 0;
void go(int pos, int rem) {
  if (pos == n) {
    int lim = 1 << n;
    double p = 0;
    double q = 0;
    for (register int mask = (0); mask < (int)(lim); ++mask) {
      double B = 0;
      double tmp = 1;
      for (register int i = (0); i < (int)(n); ++i)
        if (mask & (1 << i)) {
          tmp *= l[i] / 100.;
        } else {
          tmp *= (100 - l[i]) / 100.;
          B += b[i];
        }
      q += tmp;
      double z = A / (A + B + .0);
      if (__builtin_popcount(mask) * 2 < n) tmp *= z;
      p += tmp;
    }
    prob = max(prob, p);
    return;
  }
  for (register int i = (0); i < (int)(rem + 1); ++i) {
    l[pos] += 10 * i;
    if (l[pos] <= 100) go(pos + 1, rem - i);
    l[pos] -= 10 * i;
  }
}
int main() {
  int k;
  cin >> n >> k >> A;
  for (register int i = (0); i < (int)(n); ++i) cin >> b[i] >> l[i];
  go(0, k);
  cout << fixed << setprecision(7) << prob + 1e-8 << endl;
  return 0;
}
