#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int mod = 1e9 + 7;
int mk[85], nxt[85], a[85];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!mk[a[i]]) {
      mk[a[i]] = i;
      nxt[i] = mod;
    } else {
      nxt[i] = mk[a[i]];
      mk[a[i]] = i;
    }
  }
  set<int> st;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (st.find(i) != st.end()) {
      st.erase(i);
      st.insert(nxt[i]);
      continue;
    }
    if (st.size() >= k) {
      st.erase(--st.end());
      st.insert(nxt[i]);
      ans++;
    } else {
      st.insert(nxt[i]);
      ans++;
    }
  }
  cout << ans << endl;
}
