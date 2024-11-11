#include <bits/stdc++.h>
using namespace std;
long long int getsum(long long int y) { return (y * (y + 1)) / 2; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t, x, ans, i;
  cin >> t;
  while (t--) {
    cin >> x;
    ans = 0;
    for (i = 1; getsum((1LL << i) - 1) <= x; i++) {
      ans++;
      x -= getsum((1LL << i) - 1);
    }
    cout << ans << "\n";
  }
}
