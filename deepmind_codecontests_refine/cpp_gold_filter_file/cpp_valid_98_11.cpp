#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 5000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    int i = 0;
    for (i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b' || s[i] == 'b' && s[i + 1] == 'a') {
        ok = true;
        break;
      }
    }
    if (ok)
      cout << i + 1 << " " << i + 2 << '\n';
    else
      cout << -1 << " " << -1 << '\n';
  }
  return 0;
}
