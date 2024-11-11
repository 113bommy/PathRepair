#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int ans;
  if (n <= 6) {
    ans = 15;
  } else if (n <= 8) {
    ans = 20;
  } else if (n <= 10) {
    ans = 25;
  } else {
    if (n % 2 == 0) {
      ans = (n / 2) * 5;
    } else {
      ans = ((n + 1) / 2) * 5;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
