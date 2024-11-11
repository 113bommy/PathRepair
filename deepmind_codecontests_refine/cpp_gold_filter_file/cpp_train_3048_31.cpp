#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long x = a & b;
    long long ans = (a ^ x) + (b ^ x);
    cout << ans << '\n';
  }
  return 0;
}
