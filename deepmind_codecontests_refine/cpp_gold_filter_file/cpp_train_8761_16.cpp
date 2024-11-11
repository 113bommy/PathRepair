#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  vector<int> id[2];
  for (int i = 0; i < n; i++) {
    id[getchar() - '0'].push_back(i);
  }
  bool w1 = false, w2 = true;
  for (int i = 0; i <= n - k; i++) {
    for (int j = 0; j <= 1; j++) {
      int l0 = i, r0 = i + k - 1;
      if (id[j].size() > 0) {
        l0 = min(l0, id[j][0]);
        r0 = max(r0, id[j][id[j].size() - 1]);
      }
      int l1 = n, r1 = -1;
      if (id[j ^ 1].size() > 0) {
        if (id[j ^ 1][0] < i) {
          l1 = id[j ^ 1][0];
        } else {
          auto x = lower_bound(id[j ^ 1].begin(), id[j ^ 1].end(), i + k);
          if (x != id[j ^ 1].end()) {
            l1 = *x;
          }
        }
        if (id[j ^ 1][id[j ^ 1].size() - 1] >= i + k) {
          r1 = id[j ^ 1][id[j ^ 1].size() - 1];
        } else {
          auto x = lower_bound(id[j ^ 1].begin(), id[j ^ 1].end(), i);
          if (x != id[j ^ 1].begin()) {
            r1 = *prev(x);
          }
        }
      }
      if (l1 == n) {
        w1 = true;
      } else if (!(r0 - l0 < k || r1 - l1 < k)) {
        w2 = false;
      }
    }
  }
  printf("%s\n", w1 ? "tokitsukaze" : w2 ? "quailty" : "once again");
  return 0;
}
