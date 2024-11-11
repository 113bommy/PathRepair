#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, i, j, ans, k, n, m;
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    set<int> a;
    a.clear();
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &k);
      if (k % 2 == 0) a.insert(k);
    }
    while (a.size() != 0) {
      m = *a.rbegin();
      ans++;
      a.erase(m);
      m /= 2;
      if (m % 2 == 0) a.insert(m);
    }
    printf("%d\n", ans);
  }
  return 0;
}
