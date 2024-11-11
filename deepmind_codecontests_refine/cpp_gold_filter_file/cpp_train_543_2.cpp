#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    if (n == 1)
      cout << "0"
           << "\n";
    else {
      for (long long i = 3; i <= n; i += 2) {
        ans += (i * 4 - 4) * (i - 1) / 2;
      }
      cout << ans << endl;
    }
  }
}
