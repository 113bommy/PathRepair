#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    if (l <= (r / 2))
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
