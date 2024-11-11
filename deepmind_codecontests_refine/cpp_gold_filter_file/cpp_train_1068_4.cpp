#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    set<int> st;
    int n, k;
    cin >> n >> k;
    int p;
    for (int i = 1; i <= n; i++) {
      cin >> p;
      st.insert(p);
    }
    if (st.size() != 1 && k == 1) {
      cout << -1 << endl;
    } else {
      int ans, len;
      len = st.size();
      if (len <= k) {
        cout << 1 << endl;
      } else {
        ans = 1 + (len - k) / (k - 1) + ((len - k) % (k - 1) == 0 ? 0 : 1);
        cout << ans << endl;
      }
    }
  }
}
