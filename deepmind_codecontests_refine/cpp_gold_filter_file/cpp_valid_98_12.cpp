#include <bits/stdc++.h>
using namespace std;
const int maxn = 400505;
const int inf = 0x3f3f3f3f;
int n, m, k;
void YES() {
  cout << "YES"
       << "\n";
}
void NO() {
  cout << "NO"
       << "\n";
}
void solve() {
  cin >> n;
  string s;
  cin >> s;
  bool b1 = 0, b2 = 0;
  for (auto i : s) {
    if (i == 'a')
      b1 = 1;
    else
      b2 = 1;
  }
  if (b1 && b2) {
    for (int i = 0; i < n - 1; i++)
      if (s[i] != s[i + 1]) {
        cout << i + 1 << ' ' << i + 2 << "\n";
        return;
      }
  } else {
    cout << -1 << ' ' << -1 << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tn = 1;
  cin >> tn;
  for (int __ = 1; __ <= tn; __++) {
    solve();
  }
}
