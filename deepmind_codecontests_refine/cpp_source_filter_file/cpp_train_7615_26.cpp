#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    int ans = 0;
    while (n) {
      ans = ans + n % k;
      n = n - n % k;
      if (n >= k) {
        n = n / k;
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
