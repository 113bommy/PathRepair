#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17;
long long solve(multiset<int>& st, int num, int dir) {
  long long ans = 1;
  auto it = dir ? --st.end() : st.begin();
  for (int i = 1; i <= num; i++, dir ? it-- : it++) ans *= *it;
  return ans;
}
int main() {
  int t, n, x;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long ans = -inf;
    multiset<int> st[2];
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (!x)
        ans = 0;
      else
        st[x > 0].insert(x);
    }
    for (int i = 0; i <= 5; i++) {
      long long cur = 1;
      if ((int)st[0].size() < i || (int)st[1].size() < 5 - i) continue;
      if (i & 1)
        cur = solve(st[0], i, 1) * solve(st[1], 5 - i, 0);
      else
        cur = solve(st[0], i, 0) * solve(st[1], 5 - i, 1);
      ans = max(ans, cur);
    }
    printf("%lld\n", ans);
  }
}
