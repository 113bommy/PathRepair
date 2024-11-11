#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3E5 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << n << endl;
      return 0;
    }
    int ans = 0;
    while (n >= k) {
      ans += n - n / k * k;
      n = n / k * k;
      while (n % k == 0) {
        n /= k;
        ans++;
      }
    }
    ans += n;
    cout << ans << endl;
  }
}
