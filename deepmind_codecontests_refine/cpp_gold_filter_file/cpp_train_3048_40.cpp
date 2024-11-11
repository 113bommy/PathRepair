#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long a, b, x = 0;
    cin >> a >> b;
    long long two = 1;
    long long ans = 0;
    while (a > 0 or b > 0) {
      if (a % 2 != b % 2) ans += two;
      two *= 2;
      a /= 2;
      b /= 2;
    }
    cout << ans;
    cout << endl;
  }
}
