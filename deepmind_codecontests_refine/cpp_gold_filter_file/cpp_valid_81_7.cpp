#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    char c[2] = {'+', '-'};
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + (s[i] == c[i % 2] ? 1 : -1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if ((r - l + 1) % 2) {
        cout << 1 << endl;
      } else {
        cout << (pref[r] - pref[l - 1] == 0 ? 0 : 2) << endl;
      }
    }
  }
  return 0;
}
