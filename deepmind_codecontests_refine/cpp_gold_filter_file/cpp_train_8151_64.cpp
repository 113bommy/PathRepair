#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  long long ml = k * l / nl;
  long long slices = c * d;
  long long salt = p / np;
  long long minimum = min(ml, slices);
  cout << (min(minimum, salt)) / n << "\n";
  return 0;
}
