#include <bits/stdc++.h>
using namespace std;
int k, m, x, a[4];
set<int> ans;
set<int>::iterator it;
inline void add(int v) {
  if (((int)(ans).size()) < m) ans.insert(v);
}
void dfs(int t, int ret) {
  if (((int)(ans).size()) >= m) return;
  if (t >= 4) {
    int diff = abs(ret - k);
    if (diff < 10000) add(x * 10000 + diff), add(diff * 10000 + x);
    return;
  }
  dfs(t + 1, ret + a[t]);
  dfs(t + 1, ret - a[t]);
  dfs(t + 1, ret * a[t]);
}
void solve() {
  for (int i = (0); i < (10000); ++i) {
    x = i;
    for (int j = (0); j < (4); ++j) a[j] = x % 10, x /= 10;
    x = i, reverse(a, a + 4);
    dfs(1, a[0]);
  }
  for (it = ans.begin(); it != ans.end(); ++it) printf("%.8d\n", *it);
}
int main() {
  scanf("%d%d", &k, &m);
  solve();
  return 0;
}
