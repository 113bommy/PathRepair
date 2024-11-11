#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[10], n, b[N], ans = 1e9 + 5;
set<pair<int, int> > S;
int main() {
  for (int i = 1; i <= 6; i++) scanf("%d", a + i);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  sort(a + 1, a + 7);
  for (int i = 1; i <= n; i++) S.insert(make_pair(b[i] - a[1], 1));
  while (true) {
    set<pair<int, int> >::iterator it = S.begin();
    set<pair<int, int> >::reverse_iterator rit = S.rbegin();
    ans = min(ans, (*rit).first - (*it).first);
    if ((*rit).second == 6) break;
    pair<int, int> p = (*rit),
                   w = make_pair(p.first + a[p.second] - a[p.second + 1],
                                 p.second + 1);
    S.erase(*rit);
    S.insert(w);
  }
  printf("%d\n", ans);
  return 0;
}
