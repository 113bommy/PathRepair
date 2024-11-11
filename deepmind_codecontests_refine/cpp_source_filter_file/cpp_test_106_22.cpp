#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  cout << 2 << " ";
  for (int i = 1; i <= n; i++) {
    cout << i + 2 << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
