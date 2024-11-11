#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, INF = 1e9;
int n, k, head, tail, ans;
set<int> Set;
int main() {
  scanf("%d%d", &n, &k);
  int pre = 0, sz = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    int t = (x < 0);
    if (t != pre) {
      if (pre == 0)
        if (head == 0)
          head = sz;
        else
          Set.insert(sz);
      else
        k -= sz, ans += 2;
      pre = t;
      sz = 1;
    } else {
      sz++;
    }
  }
  if (pre == 0)
    tail = sz;
  else
    k -= sz, ans += 2;
  if (k < 0)
    return !printf("-1");
  else {
    while (k && !Set.empty()) {
      auto it = Set.begin();
      if ((*it) <= k) {
        k -= (*it);
        ans -= 2;
        Set.erase(it);
      } else {
        break;
      }
    }
    if (k >= tail) ans--;
    printf("%d\n", ans);
  }
  return 0;
}
