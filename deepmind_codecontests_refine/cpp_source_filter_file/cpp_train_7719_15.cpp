#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 1 << endl;
    return;
  }
  if (n == m) {
    cout << 0 << endl;
    return;
  }
  if (n - m < m) {
    cout << n - m << endl;
    return;
  }
  if (n - m > m) {
    cout << m << endl;
    return;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
