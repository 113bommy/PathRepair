#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long l = 0, r = 1e9;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (m + 2 * m > n) {
      r = m;
    } else {
      l = m;
    }
  }
  if (l + 2 * l == n) {
    cout << l << " " << l << endl;
  } else if (l + 2 * l + 2 == n) {
    cout << l << " " << l + 1 << endl;
  } else {
    cout << l + 1 << " " << l << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (true) {
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
  } else {
    solve();
  }
}
