#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, y, ans{}, idx{};
  set<long long, greater<long long>> st;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ans += min(x, y);
    st.insert(min(x * 2, y) - min(x, y));
  }
  auto it = st.begin();
  while (m-- && it != st.end()) {
    ans += *it;
    it++;
  }
  cout << ans << endl;
  return 0;
}
