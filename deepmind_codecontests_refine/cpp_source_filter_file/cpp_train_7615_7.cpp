#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    long long ans = 0;
    cin >> a >> b;
    while (a) {
      ans += a % b + a / b;
      a /= b;
    }
    cout << ans << endl;
  }
  return 0;
}
