#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  assert(scanf("%d", &n) == 1);
  set<int> ns;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t;
    assert(scanf("%d", &t) == 1);
    ans++;
    if (t && ns.count(t)) {
      ns.erase(t);
      ans--;
    }
    ns.insert(i);
  }
  printf("%d\n", ans);
  return 0;
}
