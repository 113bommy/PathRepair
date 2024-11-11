#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 100;
pair<long long int, long long int> p[N];
long long int n;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  multiset<long long int> st;
  long long int mx = 0, ans;
  for (long long int i = 0; i < n; i++) {
    st.insert(p[i].second);
    while (*st.begin() <= p[i].first) st.erase(st.begin());
    if (st.size() > mx) {
      mx = st.size();
      ans = p[i].first;
    }
  }
  cout << ans << " " << mx;
  return 0;
}
