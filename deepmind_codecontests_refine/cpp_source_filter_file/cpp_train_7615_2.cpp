#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    int ans = 0;
    while (n > 0) {
      ans += n % k;
      n /= k;
      if (n > 0) ans++;
    }
    cout << ans << "\n";
  }
}
