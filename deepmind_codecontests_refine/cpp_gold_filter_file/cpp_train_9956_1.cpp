#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
int32_t main() {
  ios::sync_with_stdio(0);
  long long a, b, k;
  cin >> a >> b >> k;
  long long x = a * 10;
  for (long long i = 1; i < 1000 * 1000; i++) {
    long long c = x / b;
    if (c == k) return cout << i << endl, 0;
    x -= c * b;
    x *= 10;
  }
  cout << -1 << endl;
}
