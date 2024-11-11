#include <bits/stdc++.h>
using namespace std;
int n, s, ans;
int a[200020];
set<int> ss;
int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (a[s - 1] != 0) {
    a[s - 1] = 0;
    ans++;
  }
  {
    int zero = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] == 0) {
        if (zero == 0)
          zero = 1;
        else
          a[i] = 1e8;
      }
    ss.insert(a, a + n);
  }
  int prev = 0;
  while (!ss.empty()) {
    auto it = ss.begin();
    if ((*it) - prev > 1) {
      auto itend = (--ss.end());
      prev++;
      ans++;
      ss.erase(itend);
    } else {
      prev = (*it);
      ss.erase(it);
    }
  }
  printf("%d\n", ans);
  return 0;
}
