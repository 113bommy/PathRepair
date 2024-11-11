#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    long long to = 0;
    long long x = 7;
    long long ans = 0;
    while (to != k) {
      if (x == 1) {
        break;
      }
      if (to + x <= k) {
        to += x;
        ans++;
      } else {
        x--;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
