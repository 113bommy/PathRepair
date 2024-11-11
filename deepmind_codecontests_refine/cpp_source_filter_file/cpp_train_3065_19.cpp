#include <bits/stdc++.h>
using namespace std;
int n, m, e, s, a[100000], b[100000], can[350], ans;
set<int> my_sets[100001];
set<int>::iterator it;
int main() {
  scanf("%d %d %d %d", &n, &m, &s, &e);
  for (int i = 1; i < 350; i++) can[i] = 1e6;
  can[0] = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    int value;
    scanf("%d", &value);
    my_sets[value].insert(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 350; j++) {
      it = my_sets[a[i]].upper_bound(can[j]);
      if (it != my_sets[a[i]].cend() && *it < can[j + 1]) {
        can[j + 1] = *it;
        if (s - e * (j + 1) - (*it + 1) - (i + 1) >= 0) ans = max(j + 1, ans);
      }
    }
  }
  cout << ans;
  return 0;
}
