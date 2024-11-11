#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  long long int c = 0;
  if (a % b == 0) cout << 0 << endl;
  if (a % b != 0) {
    long long int ans = b - (a % b);
    cout << ans << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
