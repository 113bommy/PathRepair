#include <bits/stdc++.h>
using namespace std;
long long int mod = pow(10, 9) + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long int n;
    string x;
    cin >> n >> x;
    vector<char> s(n + 1);
    for (long long int i = 1; i <= n; i++) {
      s[i] = x[i - 1];
    }
    long long int l1, r1, l2, r2;
    r1 = -1;
    for (long long int i = 1; i <= n; i++) {
      if (s[i] == '0') {
        r1 = i;
        break;
      }
    }
    if (r1 == -1) {
      l1 = 1;
      r1 = n / 2;
      l2 = r1 + 1;
      r2 = n;
    } else if (r1 > n / 2) {
      l1 = 1;
      l2 = 1;
      r2 = r1 - 1;
    } else {
      l1 = r1;
      r1 = n;
      l2 = l1 + 1;
      r2 = n;
    }
    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
  }
  return 0;
}
