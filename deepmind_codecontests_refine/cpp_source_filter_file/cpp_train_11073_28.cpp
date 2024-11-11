#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  if (n > 2) {
    for (long long int i = 0; i < n - 1; i++) cout << 1 << " ";
    cout << 0 << endl;
  } else
    cout << -1 << endl;
}
void testcase() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
