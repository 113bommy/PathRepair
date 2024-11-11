#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 5e4 + 10;
int a[N];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << (a[0] + a[1] > a[n - 1] ? "-1" : "1 2 " + to_string(n)) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
