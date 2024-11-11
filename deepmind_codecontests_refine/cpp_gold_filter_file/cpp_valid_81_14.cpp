#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], p[maxn], t, n, q;
string s;
inline int get_sum(int l, int r) {
  if (l > r)
    return 0;
  else
    return (l % 2 == 1) ? p[r] - p[l - 1] : p[l - 1] - p[r];
}
signed main() {
  cin >> t;
  for (int afo = 1; afo <= t; ++afo) {
    cin >> n >> q >> s;
    for (int i = 1; i <= n; ++i) {
      a[i] = (s[i - 1] == '+' ? 1 : -1);
    }
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
      p[i] = p[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);
    }
    for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      if (get_sum(l, r) == 0) {
        cout << 0 << endl;
        continue;
      }
      if ((r - l + 1) % 2 == 0) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
