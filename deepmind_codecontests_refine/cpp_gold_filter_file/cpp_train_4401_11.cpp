#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  cin >> a[0];
  bool f = false;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i - 1] != a[i]) f = true;
  }
  if (f)
    cout << 1 << endl;
  else
    cout << n << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
