#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  while (n--) {
    long long int k, x;
    cin >> k >> x;
    if (k == 1) {
      cout << x << endl;
    } else {
      long long int ans = 9 * (k - 1);
      ans += x;
      cout << ans << endl;
    }
  }
  return 0;
}
