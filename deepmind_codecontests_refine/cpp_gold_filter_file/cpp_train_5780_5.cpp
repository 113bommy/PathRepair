#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int> > v;
pair<int, int> ans[100005];
int main() {
  int n, m, i, x, ok, k, now, l, r, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &ok);
    v.emplace_back(x, ok ^ 1, i);
  }
  sort(v.begin(), v.end());
  now = 1;
  k = 0;
  l = 3;
  r = 3;
  for (i = 0; i < v.size(); i++) {
    tie(x, ok, j) = v[i];
    if (ok == 1) {
      k--;
      if (k < 0) {
        printf("-1");
        return 0;
      }
      r--;
      if (r == 1) {
        l++;
        r = l - 1;
      }
      ans[j] = {l, r};
    } else {
      now++;
      k += now - 2;
      ans[j] = {1, now};
    }
  }
  for (i = 0; i < m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
}
