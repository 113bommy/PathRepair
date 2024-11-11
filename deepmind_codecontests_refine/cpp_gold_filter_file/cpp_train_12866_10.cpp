#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
set<int> have;
set<pair<int, int> > no_need;
int n, a[N], k, ans, nxt[N], occ[N], cur[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = n - 1; i >= 0; i--)
    nxt[i] = occ[a[i]] ? occ[a[i]] : n, occ[a[i]] = i;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!have.count(a[i])) {
      ans++;
      if (cnt < k)
        cnt++;
      else {
        pair<int, int> del = *no_need.begin();
        have.erase(del.second);
        no_need.erase(del);
      }
      have.insert(a[i]);
    }
    no_need.erase(make_pair(cur[a[i]], a[i]));
    no_need.insert(make_pair(-nxt[i], a[i]));
    cur[a[i]] = -nxt[i];
    ;
  }
  printf("%d\n", ans);
  return 0;
}
