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
      ans += a % b + 1;
      a /= b;
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
