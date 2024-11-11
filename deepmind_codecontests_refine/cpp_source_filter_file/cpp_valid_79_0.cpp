#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const double Pi = acos(-1);
using namespace std;
int debug = 01;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int a = -1, b = -1, c = 0, d = 0, e = 0;
  for (auto x : s) {
    if (x == '1' || x == '4' || x == '6' || x == '8' || x == '9') {
      cout << "1\n" << x << "\n";
      return;
    }
    if (x == '3') a = c, d++;
    if (x == '7') b = c, e++;
    c++;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '2' || s[i] == '5') {
      cout << "2\n" << s[0] << s[i] << "\n";
      return;
    }
    if ((s[0] == '2' || s[i] == '5') && (s[i] == '7')) {
      cout << "2\n" << s[0] << s[i] << "\n";
      return;
    }
  }
  if (d > 1)
    cout << "2\n33\n";
  else if (e > 1)
    cout << "2\n77\n";
  else
    cout << n << "\n" << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tst = 1;
  cin >> tst;
  for (int T = 1; T <= tst; T++) {
    solve();
  }
}
