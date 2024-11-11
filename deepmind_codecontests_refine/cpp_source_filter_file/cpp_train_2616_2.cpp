#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  int64_t n, mx = 0;
  cin >> n;
  vector<int64_t> v(n);
  for (int64_t i = 0; i < n; ++i) {
    cin >> v[i];
    mx = max(mx, v[i]);
  }
  stack<int64_t> st;
  for (int64_t i = 0; i < n; ++i) {
    if (!st.size() || v[i] == mx) {
      st.push(v[i]);
      continue;
    }
    if (st.top() > v[i]) {
      cout << "NO";
      exit(0);
    }
    if (st.top() == v[i])
      st.pop();
    else
      st.push(v[i]);
  }
  while (st.size()) {
    if (st.top() != mx) {
      cout << "NO";
      return 0;
    }
    st.pop();
  }
  cout << "YES";
}
