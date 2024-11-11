#include <bits/stdc++.h>
using namespace std;
set<int> st[100005];
int c[100005];
int main() {
  int n, m, i, a, b, ans, mx, zz;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &c[i]);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    if (c[a] == c[b]) continue;
    st[c[a]].insert(b);
    st[c[b]].insert(a);
  }
  mx = -1;
  ans = 100005;
  for (i = 0; i < n; i++) {
    zz = st[c[i]].size();
    if (zz == mx) ans = min(c[i], ans);
    if (zz > mx) {
      ans = c[i];
      mx = zz;
    }
  }
  printf("%d\n", ans);
  return 0;
}
