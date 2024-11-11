#include <bits/stdc++.h>
using namespace std;
const long INF = 10000000;
long i, j, n, k, xl, yl, m;
vector<long> x, y, Count(300000, 0), ans(300000, 0);
vector<pair<long, long> > str(300000, pair<long, long>(INF, 0)),
    sto(300000, pair<long, long>(INF, 0)), d1(300000, pair<long, long>(INF, 0)),
    d2(300000, pair<long, long>(INF, 0));
void add(long x, long y) {
  str[y] = pair<long, long>(min(str[y].first, x), max(str[y].second, x));
  sto[x] = pair<long, long>(min(sto[x].first, y), max(sto[x].second, y));
  d1[x + y] =
      pair<long, long>(min(d1[x + y].first, x), max(d1[x + y].second, x));
  d2[x - y + n] = pair<long, long>(min(d2[x - y + n].first, x),
                                   max(d2[x - y + n].second, x));
  return;
}
void check(long x, long y) {
  if (str[y].first != x) Count[i]++;
  if (str[y].second != x) Count[i]++;
  if (sto[x].first != y) Count[i]++;
  if (sto[x].second != y) Count[i]++;
  if (d1[x + y].first != x) Count[i]++;
  if (d1[x + y].second != x) Count[i]++;
  if (d2[x - y + n].first != x) Count[i]++;
  if (d2[x - y + n].second != x) Count[i]++;
}
int main() {
  scanf("%ld %ld", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%ld %ld", &xl, &yl);
    x.push_back(xl);
    y.push_back(yl);
    add(xl, yl);
  }
  for (i = 0; i < (long)x.size(); i++) {
    check(x[i], y[i]);
  }
  for (i = 0; i < 9; i++) {
    for (j = 0; j < (long)x.size(); j++)
      if (Count[j] == i) ans[i]++;
    printf("%ld ", ans[i]);
  }
  return 0;
}
