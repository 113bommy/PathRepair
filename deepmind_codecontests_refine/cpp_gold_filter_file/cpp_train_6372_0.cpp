#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x, cnt = 0;
  long long ans = 0;
  string s;
  char c;
  cin >> n >> k >> s;
  set<char> st;
  for (int i = 0; i < k; i++) {
    cin >> c;
    st.insert(c);
  }
  for (int i = 0; i < n; i++) {
    if (st.find(s[i]) == st.end()) {
      if (cnt % 2 == 0)
        ans += ((cnt / 2) * (cnt + 1));
      else
        ans += (cnt * (cnt + 1) / 2);
      cnt = 0;
    } else
      cnt++;
  }
  if (cnt) {
    if (cnt % 2 == 0)
      ans += ((cnt / 2) * (cnt + 1));
    else
      ans += (cnt * (cnt + 1) / 2);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
