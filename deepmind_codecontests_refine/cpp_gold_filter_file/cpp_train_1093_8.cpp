#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  int duo = n - k, uno = n - 2 * duo;
  int lower = 0, upper = 2 * 1e6;
  while (upper - lower > 1) {
    int mid = (lower + upper) / 2;
    bool check = true;
    multiset<int> st;
    for (auto elem : s) st.insert(elem);
    for (int i = 0; i < duo; ++i) {
      int first = *st.begin();
      if (first > mid) {
        check = false;
        break;
      }
      st.erase(st.begin());
      auto it = st.upper_bound(mid - first);
      if (it == st.begin()) {
        check = false;
        break;
      } else
        st.erase(--it);
    }
    if (check && uno > 0)
      if (*(--st.end()) > mid) check = false;
    if (check)
      upper = mid;
    else
      lower = mid;
  }
  cout << upper << endl;
  return 0;
}
