#include <bits/stdc++.h>
using namespace std;
int p[2005], q[2005];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i] %= m;
  }
  for (int i = 0; i < n; i++) scanf("%d", &q[i]);
  unordered_map<int, int> mp, mp1;
  for (int i = 0; i < n; i++) {
    mp[p[i]]++, mp1[q[i]]++;
  }
  unordered_map<int, int> MAP;
  for (auto it : mp) {
    for (auto jt : mp1) {
      if (it.second == jt.second) {
        if (jt.first >= it.first) {
          MAP[jt.first - it.first]++;
        } else {
          MAP[(abs(jt.first - 0) + abs(m - it.first))]++;
          ;
        }
      }
    }
  }
  int ans = 1100000000;
  for (auto it : MAP) {
    if (it.second == (int)(mp).size()) {
      ans = min(ans, it.first);
    }
  }
  printf("%d\n", ans);
}
int main() {
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
