#include <bits/stdc++.h>
using namespace std;
long long k, n, b, t, z = 1;
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  int u = 0, ans = 0;
  cin >> k >> b >> n >> t;
  while (u <= n) {
    if (z > t) return cout << (n - (u - 1)) << "\n", 0;
    z = ((k * z) + b);
    ++u;
  }
  cout << 0 << "\n";
  return 0;
}
