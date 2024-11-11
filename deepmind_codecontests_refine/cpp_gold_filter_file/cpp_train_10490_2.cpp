#include <bits/stdc++.h>
const long long N = 50050;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;
using namespace std;
int a, b, c, n;
void solve() {
  cin >> a >> b >> c >> n;
  if (a + b - c >= n || c > a || c > b) {
    cout << -1 << "\n";
  } else {
    cout << n - (a + b - c) << "\n";
  }
}
bool mtest = false;
int main() {
  ios_base::sync_with_stdio(0);
  int TE = 1;
  if (mtest) cin >> TE;
  while (TE--) solve();
  return 0;
}
