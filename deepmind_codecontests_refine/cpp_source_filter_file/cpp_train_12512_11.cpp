#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  const int SQ = sqrt(n);
  vector<int> st((n + SQ - 1) / SQ);
  vector<int> beg(n);
  for (int i = 0; i < n; ++i) {
    st[i / SQ] |= 1 << (s[i] - 'a');
    beg[i] = i / SQ;
  }
  int Q;
  cin >> Q;
  for (; Q--;) {
    int t;
    cin >> t;
    if (t == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos -= 1;
      s[pos] = c;
      int j = beg[pos];
      int new_mask = 0;
      for (int i = j * SQ; i < j + SQ; ++i) {
        new_mask |= 1 << (s[i] - 'a');
      }
      st[j] = new_mask;
    }
    if (t == 2) {
      int l, r;
      cin >> l >> r;
      l -= 1;
      r -= 1;
      int ans = 0;
      for (int i = l; i <= r;) {
        if (beg[i] * SQ == i && i + SQ <= r) {
          ans |= st[beg[i]];
          i += SQ;
        } else {
          ans |= (1 << (s[i] - 'a'));
          i += 1;
        }
      }
      cout << __builtin_popcount(ans) << '\n';
    }
  }
}
