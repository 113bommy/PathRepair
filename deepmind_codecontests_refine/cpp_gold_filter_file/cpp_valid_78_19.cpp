#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll m, n;
  cin >> m >> n;
  if (n / 2 < m)
    cout << n % m << endl;
  else {
    if (n % 2 == 0)
      cout << n - (n / 2 + 1) << endl;
    else
      cout << n / 2 << endl;
  }
  return;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
