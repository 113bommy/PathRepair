#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
vector<int> st;
int solve() {
  st.clear();
  int m = 0;
  for (int i = 0; i < n; i++) {
    while (st.size() > 1 && st.back() < a[i]) st.pop_back();
    st.push_back(a[i]);
    if (st.size() > 1) m = max(m, st[st.size() - 1] ^ st[st.size() - 2]);
  }
  return m;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int res = solve();
  reverse(a, a + n);
  cout << max(res, solve());
  return 0;
}
