#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = n / 2;
    if (ans % 2 == 0) ans--;
    if (n < 3)
      cout << 0 << "\n";
    else
      cout << ans << "\n";
  }
}
