#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, t[N];
int main() {
  scanf("%d", &n);
  set<int> st;
  int ans = 0;
  for (int i = 0; i < n; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= n; i++) {
    set<int>::iterator it = st.lower_bound(t[i]);
    int cur = *it;
    if (it == st.end() || cur != t[i]) {
      ans++;
    } else {
      st.erase(it);
    }
    st.insert(i);
  }
  cout << ans << endl;
  return 0;
}
