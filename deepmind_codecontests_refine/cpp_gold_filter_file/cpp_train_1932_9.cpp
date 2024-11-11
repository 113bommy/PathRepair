#include <bits/stdc++.h>
using namespace std;
set<int> s[300010];
int a[300010];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int i;
  int cur = 1;
  int last = 1;
  int ans = 0;
  for (i = 1; i <= q; i++) {
    int o, x;
    scanf("%d%d", &o, &x);
    if (o == 1) {
      a[cur++] = x;
      s[x].insert(cur - 1);
      ans++;
      printf("%d\n", ans);
    } else if (o == 2) {
      set<int>::iterator it;
      for (it = s[x].begin(); it != s[x].end(); it++) {
        if (*it >= last) ans--;
      }
      s[x].clear();
      printf("%d\n", ans);
    } else if (o == 3) {
      while (last <= x) {
        if (s[a[last]].count(last)) ans--;
        last++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
