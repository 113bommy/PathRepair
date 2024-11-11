#include <bits/stdc++.h>
using namespace std;
long long n, x, y, s[100100];
long long l, r, ans;
bool check(long long mid) {
  set<long long> st;
  st.insert(x);
  st.insert(y);
  for (long long i = 1; i <= n; i++) {
    while (!st.empty() && abs(*st.begin() - s[i]) > mid) st.erase(st.begin());
    while (!st.empty() && abs(*(--st.end()) - s[i]) > mid)
      st.erase((--st.end()));
    if (st.empty()) return false;
    st.insert(s[i]);
  }
  return true;
}
signed main() {
  scanf("%lld%lld%lld", &n, &x, &y);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &s[i]);
  }
  l = abs(x - y);
  r = 1000000005;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
