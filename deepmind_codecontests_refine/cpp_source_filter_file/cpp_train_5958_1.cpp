#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, g, b;
    cin >> n >> g >> b;
    long long l = 0, r = 1e18;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      long long v1 = m / (g + b) * g + min(g, m % (g + b));
      if (v1 >= (n + 1) / 2)
        r = m;
      else
        l = m;
    }
    cout << r << '\n';
  }
  return 0;
}
