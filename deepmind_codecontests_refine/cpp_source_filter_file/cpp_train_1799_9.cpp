#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, ans = 0, n = 1;
    cin >> x;
    while (x > 0) {
      long long int a = (n * (n + 1)) / 2;
      if (x >= a) {
        x = x - a;
        ans++;
      } else
        break;
      n = n + 2;
    }
    cout << ans << '\n';
  }
}
