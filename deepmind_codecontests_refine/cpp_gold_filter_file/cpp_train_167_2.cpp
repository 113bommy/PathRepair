#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k;
int ans[2000010];
set<int> v;
set<pair<int, int> > e;
void dfs(int x, int k) {
  if (x > n) return;
  v.erase(x);
  ans[k]++;
  int y = 0;
  while (y < n) {
    set<int>::iterator it = v.upper_bound(y);
    y = *it;
    if (!e.count(make_pair(x, y))) dfs(y, k);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    e.insert(make_pair(x, y));
    e.insert(make_pair(y, x));
  }
  for (int i = 1; i <= n + 1; i++) v.insert(i);
  for (int i = 1; i <= n; i++)
    if (v.count(i)) k++, dfs(i, k);
  sort(ans + 1, ans + 1 + k);
  printf("%d\n", k);
  for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
}
