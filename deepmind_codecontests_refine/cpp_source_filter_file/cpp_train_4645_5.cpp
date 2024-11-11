#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 3e5 + 4;
int up[N][21], level[N];
int lca(int a, int b) {
  if (level[a] < level[b]) swap(a, b);
  for (int i = 20; i >= 0; i--)
    if (level[a] - (1 << i) >= level[b]) a = up[a][i];
  assert(level[a] == level[b]);
  for (int i = 0; i < 21; i++)
    if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
  if (a != b) a = up[a][0];
  return a;
}
int distance(int a, int b) {
  int lc = lca(a, b);
  return level[a] + level[b] - 2 * level[lc];
}
int main() {
  int n;
  scanf("%d", &n);
  up[1][0] = 1;
  level[1] = 0;
  for (int i = 1; i < 21; i++) up[1][i] = up[up[1][i - 1]][i - 1];
  set<int> s1, s2;
  s1.insert(1);
  int mx = 0;
  for (int i = 2; i < n + 2; i++) {
    int par;
    scanf("%d", &par);
    up[i][0] = par;
    level[i] = level[par] + 1;
    for (int j = 1; j < 21; j++) up[i][j] = up[up[i][j - 1]][j - 1];
    int d1 = 0, d2 = 0;
    if ((int)s1.size()) d1 = distance(i, *s1.begin());
    if ((int)s2.size()) d2 = distance(i, *s2.begin());
    if (max(d1, d2) > mx) {
      mx = max(d1, d2);
      if (d1 == mx) {
        for (int it : s2)
          if (distance(i, it) == mx) s1.insert(it);
        s2.clear();
        s2.insert(i);
      } else {
        for (int it : s1)
          if (distance(i, it) == mx) s2.insert(it);
        s1.clear();
        s1.insert(i);
      }
    } else if (max(d1, d2) == mx) {
      if (d1 == mx)
        s2.insert(i);
      else
        s1.insert(i);
    }
    int ans = (int)s1.size() + (int)s2.size();
    printf("%d\n", ans);
  }
  return 0;
}
