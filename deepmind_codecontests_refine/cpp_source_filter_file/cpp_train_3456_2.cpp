#include <bits/stdc++.h>
using namespace std;
struct A {
  long long m, p;
} a[200005];
int t, n;
multiset<int> st;
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    st.clear();
    for (int i = 1; i <= n; i++) cin >> a[i].m >> a[i].p;
    sort(a + 1, a + 1 + n,
         [](A b, A c) { return b.m < c.m || b.m == c.m && b.p < c.p; });
    int now = 0;
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
      int ned = a[i].m - (i - 1);
      st.insert(a[i].p);
      while (!st.empty() && now < ned) {
        ans += *st.begin();
        st.erase(*st.begin());
        now++;
      }
    }
    cout << ans << endl;
  }
}
