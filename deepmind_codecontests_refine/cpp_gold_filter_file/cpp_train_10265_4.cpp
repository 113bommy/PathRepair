#include <bits/stdc++.h>
using namespace std;
const int N = 21;
const long long mod = 998244353LL;
string s[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, end = -1;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (char c : s[i]) {
      if (c == '1' && end == -1) end = i;
    }
  }
  if (end == -1) {
    cout << "0\n";
    return 0;
  }
  int ans = 100 * 200;
  for (int S = 0; S < (1 << n); ++S) {
    int l1, r1, last = 0, rs = 0;
    for (int i = n - 1; i >= end + 1; --i) {
      l1 = -1;
      for (int j = 1; j <= m; ++j) {
        if (s[i][j] == '1') {
          if (l1 == -1) l1 = j;
          r1 = j;
        }
      }
      if (l1 == -1) {
        l1 = m + 1;
        r1 = 0;
      }
      if (last) {
        if (S & (1 << i)) {
          rs += 2 * ((m + 1) - l1);
          last = 1;
        } else {
          rs += m + 1;
          last = 0;
        }
      } else {
        if (S & (1 << i)) {
          rs += m + 1;
          last = 1;
        } else {
          rs += 2 * r1;
          last = 0;
        }
      }
    }
    l1 = -1;
    for (int j = 1; j <= m; ++j) {
      if (s[end][j] == '1') {
        if (l1 == -1) l1 = j;
        r1 = j;
      }
    }
    if (l1 == -1) {
      l1 = m + 1;
      r1 = 0;
    }
    if (last) {
      rs += m + 1 - l1;
    } else {
      rs += r1;
    }
    ans = min(ans, rs + (n - end) - 1);
  }
  cout << ans << "\n";
  return 0;
}
