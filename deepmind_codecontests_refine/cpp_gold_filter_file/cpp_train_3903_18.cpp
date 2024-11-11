#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int ans = 0, d = 1;
  while (n) {
    if (n % 10 == 7)
      ans += d << 1;
    else
      ans += d;
    d <<= 1;
    n /= 10;
  }
  cout << ans;
  return 0;
}
