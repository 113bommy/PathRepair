#include <bits/stdc++.h>
using namespace std;
int n, m, r, k;
map<pair<int, int>, bool> vis;
set<pair<long long, pair<int, int> >,
    greater<pair<long long, pair<int, int> > > >
    s;
long long get(int x, int y) {
  return 1LL * (min(x, n - r + 1) - max(0, x - r)) *
         (min(y, m - r + 1) - max(0, y - r));
}
bool check(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || vis[make_pair(x, y)]) return false;
  return vis[make_pair(x, y)] = true;
}
int main() {
  double ans = 0;
  scanf("%d%d%d%d", &n, &m, &r, &k);
  s.insert(make_pair(get((n + 1) / 2, (m + 1) / 2),
                     make_pair((n + 1) / 2, (m + 1) / 2)));
  vis[make_pair((n + 1) / 2, (m + 1) / 2)] = true;
  while (k--) {
    auto it = s.begin();
    long long totaloverlaps = it->first;
    int x = it->second.first, y = it->second.second;
    ans += totaloverlaps;
    s.erase(it);
    if (check(x + 1, y))
      s.insert(make_pair(get(x + 1, y), make_pair(x + 1, y)));
    if (check(x - 1, y))
      s.insert(make_pair(get(x - 1, y), make_pair(x - 1, y)));
    if (check(x, y - 1))
      s.insert(make_pair(get(x, y - 1), make_pair(x, y - 1)));
    if (check(x, y + 1))
      s.insert(make_pair(get(x, y + 1), make_pair(x, y + 1)));
    if (check(x - 1, y - 1))
      s.insert(make_pair(get(x - 1, y - 1), make_pair(x - 1, y - 1)));
    if (check(x + 1, y - 1))
      s.insert(make_pair(get(x + 1, y - 1), make_pair(x + 1, y - 1)));
    if (check(x - 1, y + 1))
      s.insert(make_pair(get(x - 1, y + 1), make_pair(x - 1, y + 1)));
    if (check(x + 1, y + 1))
      s.insert(make_pair(get(x + 1, y + 1), make_pair(x + 1, y + 1)));
  }
  ans /= 1LL * (n - r + 1) * (m - r + 1);
  printf("%0.10f\n", ans);
  return 0;
}
