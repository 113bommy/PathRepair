#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3, MOD = 998244353;
void solve() {
  string s;
  cin >> s;
  set<char> st;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    st.insert(s[i]);
  }
  int id = 0;
  while (id <= n - 1 && !st.empty()) {
    auto it = st.rbegin();
    for (int i = id; i < n; i++) {
      if (s[i] == *it) {
        cout << s[i];
        id = i;
      }
    }
    st.erase(*it);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  for (int tc = 1; tc <= tt; ++tc) {
    solve();
  }
}
