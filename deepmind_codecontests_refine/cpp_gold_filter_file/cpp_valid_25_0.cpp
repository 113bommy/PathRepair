#include <bits/stdc++.h>
using namespace std;
bool equ(string s, string t, int n, int m, int l) {
  if (m == t.length()) return 1;
  if (l == 1 && n == 0) {
    if (m == t.length() - 1) {
      if (s[n] == t[m]) return 1;
    }
    return 0;
  }
  int a, b;
  a = b = 0;
  if (s[n] != t[m]) return 0;
  if (n > 0) a = equ(s, t, n - 1, m + 1, 1);
  if (n < s.length() - 1 && l != 1) {
    b = equ(s, t, n + 1, m + 1, l);
  }
  return a || b;
}
void solve() {
  string s, t;
  cin >> s >> t;
  if (s.length() == 1) {
    if (s == t) {
      cout << "YES";
      return;
    }
    cout << "NO";
    return;
  }
  int ans = 0;
  int j = 0;
  for (auto i : s) {
    if (i == t[0]) {
      ans = equ(s, t, j, 0, 0);
      if (ans == 1) {
        cout << "YES";
        return;
      }
    }
    j++;
  }
  cout << "NO";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
