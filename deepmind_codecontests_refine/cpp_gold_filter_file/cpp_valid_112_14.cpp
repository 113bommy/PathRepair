#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  if (a - 1 + b - 1 + c - 1 < m) {
    cout << "NO"
         << "\n";
    return;
  }
  if (b > a) swap(a, b);
  if (c > a) swap(a, c);
  if (c > b) swap(b, c);
  if (a - b - c - 1 > m) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
