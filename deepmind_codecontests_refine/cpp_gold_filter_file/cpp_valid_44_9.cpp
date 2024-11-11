#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  if ((abs(a - b)) % 2 == 1) {
    cout << "-1\n";
    return;
  }
  if (a == 0 && b == 0) {
    cout << "0\n";
    return;
  }
  if (a == b) {
    cout << "1\n";
    return;
  }
  cout << "2\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
