#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, n, ans;
  cin >> x >> n;
  if (x % 2 == 0) {
    if (n % 4 == 0) {
      ans = x;
    }
    if (n % 4 == 1) {
      ans = x - 1 - (n / 4) * 4;
    }
    if (n % 4 == 2) {
      ans = x + 1;
    }
    if (n % 4 == 3) {
      ans = x + (ceil(n / 4.00)) * 4;
    }
  } else {
    if (n % 4 == 0) {
      ans = x;
    }
    if (n % 4 == 1) {
      ans = x + 1 + (n / 4) * 4;
    }
    if (n % 4 == 2) {
      ans = x - 1;
    }
    if (n % 4 == 3) {
      ans = x - (ceil(n / 4)) * 4;
    }
  }
  cout << ans;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
