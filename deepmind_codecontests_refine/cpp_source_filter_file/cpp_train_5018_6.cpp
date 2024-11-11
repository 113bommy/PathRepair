#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long r, g;
    cin >> r >> g;
    long long ans = 0, x = r - g;
    if (x < 0) {
      x = -x;
    }
    ans += x % 5;
    x %= 5;
    ans += x / 2;
    x %= 2;
    ans += x / 1;
    x %= 1;
    cout << ans << endl;
  }
}
