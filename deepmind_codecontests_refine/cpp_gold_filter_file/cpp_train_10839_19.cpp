#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, k, ans = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> k;
    ans = (a - b) * (k / 2);
    if (k % 2) {
      ans += a;
    }
    cout << ans << endl;
  }
}
