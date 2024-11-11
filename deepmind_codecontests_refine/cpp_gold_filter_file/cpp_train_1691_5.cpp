#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 5;
const int MOD = 998244353;
const long long ooll = 1e18 + 5;
const int N = 2e5 + 15;
const int lgN = 18;
int n, i, v[N], pos[N], val[N];
void solve() {
  cin >> n;
  multiset<int> st;
  for (i = 1; i <= n; ++i) {
    cin >> v[i];
    pos[v[i]] = i;
  }
  set<int> posns;
  for (i = n; i > 0; --i) {
    int cur = pos[i];
    if (posns.empty()) {
      posns.insert(cur);
      val[cur] = cur;
      st.insert(cur);
    } else {
      auto it = posns.lower_bound(cur);
      if (it == posns.begin()) {
        int j = n + 1;
        if (it != posns.end()) {
          j = *it;
        }
        posns.insert(cur);
        val[cur] = cur;
        st.insert(val[cur]);
        if (j <= n) {
          auto jt = st.find(val[j]);
          st.erase(jt);
          val[j] -= val[cur];
          st.insert(val[j]);
        }
      } else {
        int j = n + 1;
        if (it != posns.end()) {
          j = *it;
        }
        --it;
        int k = *it;
        posns.insert(cur);
        val[cur] = cur - k;
        st.insert(val[cur]);
        if (j <= n) {
          auto jt = st.find(val[j]);
          st.erase(jt);
          val[j] -= val[cur];
          st.insert(val[j]);
        }
      }
    }
    auto it = st.end();
    --it;
    if (*it != val[cur]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}
int main() {
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    solve();
  }
  return 0;
}
