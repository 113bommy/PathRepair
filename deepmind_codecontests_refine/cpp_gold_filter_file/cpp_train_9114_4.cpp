#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[200005];
pair<int, int> s[200005];
int ans[200005], ans2[200005];
set<pair<int, int> > S;
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i].first);
    p[i].second = i;
    S.insert(p[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &s[i].first);
    s[i].second = i;
  }
  sort(s + 1, s + m + 1);
  for (i = 1; i <= m; i++) {
    int cnt = 0;
    while (s[i].first > 1) {
      auto it = S.lower_bound(make_pair(s[i].first, 0));
      if (it != S.end() && it->first == s[i].first) {
        ans2[s[i].second] = cnt;
        ans[it->second] = s[i].second;
        S.erase(it);
        break;
      }
      cnt++;
      if (s[i].first & 1)
        s[i].first = (s[i].first >> 1) + 1;
      else
        s[i].first >>= 1;
    }
    if (s[i].first == 1) {
      auto it = S.lower_bound(make_pair(s[i].first, 0));
      if (it != S.end() && it->first == s[i].first) {
        ans2[s[i].second] = cnt;
        ans[it->second] = s[i].second;
        S.erase(it);
      }
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++)
    if (ans[i]) tot++;
  int out = 0;
  for (int i = 1; i <= m; i++) out += ans2[i];
  printf("%d %d\n", tot, out);
  for (int i = 1; i <= m; i++) printf("%d ", ans2[i]);
  printf("\n");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
