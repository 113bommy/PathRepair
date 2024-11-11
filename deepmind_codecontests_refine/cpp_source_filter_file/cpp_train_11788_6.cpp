#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 2;
void solve() {
  string x;
  cin >> x;
  bool flg = false;
  int mn = 0, zero = 0;
  for (int i = 0; i < (int)(x.size()); ++i) {
    if (x[i] == '0')
      zero++;
    else if (x[i] == '1' && !flg)
      flg = true, zero = 0;
    else if (x[i] == '1' && flg)
      mn += zero, flg = false;
  }
  cout << mn << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
