#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  stack<int> st;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int a, b;
    while (1) {
      if (st.size())
        a = st.top(), st.pop();
      else
        break;
      if (st.size())
        b = st.top();
      else {
        st.push(a);
        break;
      }
      if (a < b && a < x) {
        ans += min(b, x);
      } else {
        st.push(a);
        break;
      }
    }
    st.push(x);
  }
  int mx = -1, scmx = -1;
  while (st.size()) {
    int x = st.top();
    st.pop();
    ans += x;
    scmx = max(scmx, x);
    if (scmx > mx) swap(scmx, mx);
  }
  cout << ans - mx - scmx << '\n';
}
