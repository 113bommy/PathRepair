#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, cnt, p[N], cc, found[N], u[N];
pair<pair<int, int>, int> a[N], z;
long long ans;
vector<int> e[N];
vector<pair<int, int> > Ans;
inline bool cmp(int i, int j) { return a[i].first.second > a[j].first.second; }
inline bool dfs(int v) {
  for (typeof(e[v].begin()) it = e[v].begin(); it != e[v].end(); ++it) {
    int to = *it;
    if (u[to] != cc) {
      u[to] = cc;
      if (!found[to] || dfs(found[to])) {
        found[to] = v;
        return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].first.second, &a[i].first.first);
    a[i].second = i;
    p[i] = i;
  }
  sort(a + 1, a + n + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    z = make_pair(make_pair(y, -1), -1);
    int ind = lower_bound(a + 1, a + n + 1, z) - a;
    if (a[ind].first.first == y && a[ind].first.second <= x)
      e[a[ind].second].push_back(i);
    z.first.first++;
    ind = lower_bound(a + 1, a + n + 1, z) - a;
    if (a[ind].first.first == y + 1 && a[ind].first.second <= x)
      e[a[ind].second].push_back(i);
  }
  sort(p + 1, p + n + 1, cmp);
  for (int k = 1; k <= n; ++k) {
    int i = p[k];
    ++cc;
    if (dfs(a[i].second)) {
      ans += a[i].first.second;
      ++cnt;
    }
  }
  printf("%I64d\n%d\n", ans, cnt);
  for (int i = 1; i <= m; ++i)
    if (found[i]) printf("%d %d\n", i, found[i]);
  return 0;
}
