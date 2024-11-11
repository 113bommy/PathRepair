#include <bits/stdc++.h>
using namespace std;
multiset<int> st;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  long long ans = 0, mn = -10000000;
  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    a -= i;
    if (a >= mn)
      st.insert(a);
    else {
      ans += mn - a;
      st.erase(st.find(mn));
      st.insert(a);
      st.insert(a);
    }
    mn = *st.rbegin();
  }
  cout << ans << endl;
}
