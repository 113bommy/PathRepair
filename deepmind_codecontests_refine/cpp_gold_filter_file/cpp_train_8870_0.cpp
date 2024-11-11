#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
typedef struct treap* tr;
map<int, int> mp;
set<int> st;
int main() {
  cin.tie();
  cout.precision(0);
  ios_base::sync_with_stdio(false);
  int n, a, b, k, ans = 0;
  cin >> n >> a >> b >> k;
  for (int i = 0; i < n; ++i) {
    int q;
    cin >> q;
    q = (q - 1) % (a + b) + 1;
    int w = q / a + (q % a != 0) - 1;
    mp[w] += 1;
    st.insert(w);
  }
  for (auto q : st) {
    if (q == 0) {
      ans += mp[q];
    } else {
      ans += min(mp[q], k / q);
      if (k / q > mp[q]) {
        k -= q * mp[q];
      } else {
        k = 0;
      }
    }
    if (k == 0) {
      break;
    }
  }
  cout << ans;
  return 0;
}
