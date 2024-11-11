#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int i, j, n, m, k;
  long long int l, r;
  cin >> n >> l >> r;
  bool var1 = 0;
  long long int var2 = 0, var = 0;
  if (r == (n * (n - 1LL)) + 1LL) {
    var1 = 1;
    r--;
  } else {
    long long int o = 0;
    while (o < 2) o++;
  }
  long long int o = 0;
  for (i = 1; i <= n; i++) {
    var2 += (n - i) * 2LL;
    if (o == 1) {
      o = 0;
    } else if (var2 >= l) {
      var2 -= (n - i) * 2LL;
      var = i;
      break;
    } else {
      o = 0;
    }
  }
  var2 = l - var2;
  long long int p = var2;
  long long int var3 = 1;
  var2 = (var + var2 / 2 + var2 % 2);
  if (l <= r && (p % 2LL == 0)) {
    cout << var2 << " ";
    l++;
    var2++;
  } else {
    o = 0;
  }
  o = 0;
  while (l <= r && o == 0) {
    if (var2 > n) {
      var++;
      var2 = var + 1;
    }
    if (o == 1)
      o = 0;
    else
      o = 0;
    if ((var3 % 2) == 1)
      cout << var << " ";
    else {
      cout << var2 << " ";
      var2++;
    }
    l++;
    var3 = 1 - var3;
  }
  o = 1;
  if (var1) cout << o << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, j, n, m, k;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
