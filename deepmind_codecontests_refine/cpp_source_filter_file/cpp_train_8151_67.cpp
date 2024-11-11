#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, l, c, d, p, nl, np;
  while (cin >> n >> k >> l >> c >> d >> p >> nl >> np) {
    long long a = (k * l) / n;
    long long b = (c * d);
    long long c = (p / np);
    cout << min(a, min(b, c)) / n << endl;
  }
  return 0;
}
