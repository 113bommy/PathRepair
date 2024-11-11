#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tes;
  cin >> tes;
  ;
  while (tes--) {
    long long n;
    cin >> n;
    ;
    string s;
    cin >> s;
    long long x = 0, y = 0;
    for (long long i = (0); i <= (n - 1); i++) {
      if (s[i] == '1') break;
      x = i;
      cout << 0;
    }
    for (long long i = (n - 1); i >= (0); i--) {
      if (s[i] == '0') break;
      y++;
    }
    if (x + y != n) cout << 0;
    for (long long i = (1); i <= (y); i++) cout << 1;
    cout << '\n';
  }
}
