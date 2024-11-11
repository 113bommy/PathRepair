#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 1;
long long int n, m, i, j, l, k, x, y, a, b, cnt[3], sum[3];
void solve() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int lst = 0, maxi = -1;
  long long int val = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      val++;
    } else {
      maxi = max(maxi, val);
      val = 0;
    }
  }
  maxi = max(maxi, val);
  cout << maxi + 1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
