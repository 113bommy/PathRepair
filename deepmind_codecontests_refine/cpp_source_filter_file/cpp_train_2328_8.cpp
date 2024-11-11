#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int main() {
  scanf("%d%d%d", &n, &m, &s);
  int t = 1;
  while (t == s) t++;
  set<pair<int, int> > Set;
  for (int i = (1); i < (n + 1); ++i)
    if (i != s) Set.insert({s, i});
  for (int i = (1); i < (n + 1); ++i)
    if (i != s && i != t) {
      for (int j = (1); j < (n + 1); ++j)
        if (j != s && j != t) {
          if (((int)(Set).size()) >= m) break;
          Set.insert({i, j});
        }
      if (((int)(Set).size()) >= m) break;
    }
  if (((int)(Set).size()) != m) {
    puts("-1");
    return 0;
  }
  for (auto e : Set) printf("%d %d\n", e.first, e.second);
  return 0;
}
