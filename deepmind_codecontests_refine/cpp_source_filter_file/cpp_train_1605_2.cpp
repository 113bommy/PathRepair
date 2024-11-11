#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int p = power(a, b / 2);
  if (b % 2 == 0)
    return p * p;
  else
    return a * p * p;
}
long int gcd(long int a, long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long int n, l, r, ql, qr, i, ri, le, s = 0, ls = 0, rs = 0, ms = INT_MAX;
  cin >> n >> l >> r >> ql >> qr;
  long int w[n];
  for (i = 0; i < n; i++) {
    cin >> w[i];
    s += w[i];
  }
  if (l >= r) {
    ri = n / 2 + n % 2;
    le = n / 2;
    for (i = 0; i < n / 2; i++) ls += w[i];
    rs = s - ls;
    for (i = n / 2 - 1; i >= 0; i--) {
      ms = min(ms, l * ls + r * rs + (ri - le - 1 > 0 ? ri - le - 1 : 0) * qr);
      ls -= w[i];
      rs += w[i];
      le--;
      ri++;
    }
    ms = min(ms, l * ls + r * rs + (ri - le - 1 > 0 ? ri - le - 1 : 0) * qr);
  } else {
    le = n / 2 + n % 2;
    ri = n / 2;
    for (i = n - 1; n - 1 - i < n / 2; i--) rs += w[i];
    ls = s - rs;
    for (i = n / 2 + n % 2; i < n; i++) {
      ms = min(ms, l * ls + r * rs + (le - ri - 1 > 0 ? le - ri - 1 : 0) * ql);
      rs -= w[i];
      ls += w[i];
      le++;
      ri--;
    }
    ms = min(ms, l * ls + r * rs + (le - ri - 1 > 0 ? le - ri - 1 : 0) * qr);
  }
  cout << ms;
}
