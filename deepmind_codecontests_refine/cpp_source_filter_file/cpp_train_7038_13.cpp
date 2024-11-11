#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
map<string, int> mp;
map<pair<int, int>, int> path;
int v[333];
int main() {
  int n, a, b, k, f, tot = 0, last = 0, cost = 0;
  scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
  char c1[22], c2[22];
  for (int i = 1; i <= n; i++) {
    scanf("%s%s", c1, c2);
    if (!mp[c1]) mp[c1] = ++tot;
    if (!mp[c2]) mp[c2] = ++tot;
    int x = mp[c1], y = mp[c2];
    if (x == last) {
      cost += b;
      path[pair<int, int>(min(x, y), max(x, y))] += b;
    } else {
      cost += a;
      path[pair<int, int>(min(x, y), max(x, y))] += a;
    }
    last = y;
  }
  tot = 0;
  for (map<pair<int, int>, int>::iterator it = path.begin(); it != path.end();
       it++)
    v[tot++] = it->second;
  sort(v, v + tot);
  for (int i = 1; i <= k && tot - i >= 0 && v[tot - i] > f; i++)
    cost = cost - v[tot - 1] + f;
  printf("%d\n", cost);
  return 0;
}
