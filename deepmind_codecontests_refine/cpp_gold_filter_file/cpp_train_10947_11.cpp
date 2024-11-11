#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return (i < j); }
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
    cout << -1 << '\n';
    return;
  }
  long long count = 0;
  while (n != 1) {
    if (n % 5 == 0) {
      n /= 5;
      count += 3;
    } else if (n % 3 == 0) {
      n /= 3;
      count += 2;
    } else if (n % 2 == 0) {
      n /= 2;
      count++;
    } else {
      cout << -1 << '\n';
      return;
    }
  }
  cout << count << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) solve();
  return 0;
}
