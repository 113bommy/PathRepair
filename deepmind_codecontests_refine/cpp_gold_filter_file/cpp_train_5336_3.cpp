#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 << " " << n / 2;
  } else {
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        cout << (i - 1) * (n / i) << " " << n / i << endl;
        return;
      }
    }
    cout << 1 << " " << n - 1 << endl;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
