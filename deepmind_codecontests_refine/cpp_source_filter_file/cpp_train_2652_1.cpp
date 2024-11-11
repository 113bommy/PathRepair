#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, t, r;
  int a[310];
  cin >> m >> t >> r;
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  int ans = 0;
  set<int> cand;
  for (int i = 0; i < m; i++) {
    while (!cand.empty() && *(cand.begin()) < a[i]) cand.erase(cand.begin());
    int x = max(0, (int)(r - cand.size()));
    int val = t, j = 0;
    while (val >= 0 && j < x) {
      if (cand.find(a[i] + val) == cand.end()) {
        cand.insert(a[i] + val);
        j++;
      }
      val--;
    }
    if (j < x) {
      ans = -1;
      break;
    }
    ans += x;
  }
  cout << ans;
  return 0;
}
