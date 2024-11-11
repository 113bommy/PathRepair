#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, g, b;
    cin >> n >> g >> b;
    long long ans = 0;
    if (n < g) {
      cout << n << endl;
      continue;
    }
    long long k = ((n + 1) / 2) / g;
    if (((n + 1) / 2) % g == 0) {
      ans = k * (g + b) - b;
    } else {
      ans = k * (g + b) + ((n + 1) / 2) % g;
    }
    cout << ans << endl;
  }
  return 0;
}
