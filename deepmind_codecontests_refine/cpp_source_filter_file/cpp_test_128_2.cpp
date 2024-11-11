#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << (n / 2) - 1 << " " << n / 2 << " " << 1 << endl;
  } else {
    for (int i = 3; i < 8; i += 2) {
      if (gcd(i, n - i - 1) == 1) {
        cout << i << " " << n - 1 - i << " " << 1 << endl;
        break;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
