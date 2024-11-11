#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> m(n + 1), p(n + 1), pref(n + 1, 0);
  multiset<int> st;
  vector<vector<int> > x(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> m[i] >> p[i];
    pref[m[i]]++;
    x[m[i]].push_back(p[i]);
  }
  for (int i = 1; i < n; ++i) {
    pref[i] += pref[i - 1];
  }
  long long ans = 0, cur = 0;
  for (int i = n - 1; i >= 1; --i) {
    for (auto it : x[i]) {
      st.insert(it);
    }
    if (pref[i - 1] + cur < i) {
      for (int j = 0; j < i - pref[i - 1] - cur; ++j) {
        ans += *st.begin();
        st.erase(st.begin());
      }
      cur += i - pref[i - 1] - cur;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
