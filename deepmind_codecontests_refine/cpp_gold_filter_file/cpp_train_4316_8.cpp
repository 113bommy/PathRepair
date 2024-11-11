#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool f(long long x, long long y, long long z) {
  if ((k - x - y - z) < 0 || (k - x - y - z) % 3 != 0) return false;
  long long m = max(x, max(y, z)), p = n - (k + 3 * m - (x + y + z));
  if (p < 0 || p % 3 != 0) return false;
  return true;
}
int main() {
  int t;
  ios_base::sync_with_stdio(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long d1, d2;
    cin >> n >> k >> d1 >> d2;
    long long d = max(d1, d2);
    if (f(0ll, d1, d1 + d2) || f(d1 + d2, d2, 0ll) || f(d1, 0ll, d2) ||
        f(d - d1, d, d - d2))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
