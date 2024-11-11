#include <bits/stdc++.h>
using namespace std;
const int64_t M = 1e6 + 5;
int64_t n, a[M];
unordered_map<int64_t, int64_t> st, en;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t t;
  cin >> t;
  while (t--) {
    cin >> n;
    st.clear();
    en.clear();
    for (int64_t i = 0; i < n; i++) {
      cin >> a[i];
      if (st.find(a[i]) == st.end()) {
        st[a[i]] = i;
        en[a[i]] = i;
      } else
        en[a[i]] = i;
    }
    if (n < 6) {
      cout << "0 0 0\n";
      continue;
    }
    int64_t g = 0, s = 0, b = 0, cnt = 0, i = 0;
    while (i < n) {
      int64_t cur = en[a[i]] - st[a[i]] + 1;
      if (cnt + cur > n / 2) break;
      if (!g)
        g += cur, cnt += cur;
      else if (!s || s <= g)
        s += cur, cnt += cur;
      else
        b += cur, cnt += cur;
      i += cur;
    }
    if (!g || !s || !b || g > s || g > b) {
      cout << "0 0 0\n";
      continue;
    }
    cout << g << " " << s << " " << b << "\n";
  }
  return 0;
}
