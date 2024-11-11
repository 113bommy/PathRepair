#include <bits/stdc++.h>
using namespace std;
const long long maxk = 36;
long long n, k, i, j, f, w, curk, s, m, curi, maxik;
pair<int, pair<long long, long long> > otv[100010][maxk], cur1, cur2;
long long inf = 1000000007;
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  scanf("%I64d %I64d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &f);
    otv[i][0].first = f;
  }
  for (i = 0; i < n; i++) {
    scanf("%I64d", &w);
    otv[i][0].second = make_pair((w), (w));
  }
  maxik = 0;
  curk = k;
  while (curk > 0) {
    maxik++;
    curk = curk >> 1;
  }
  maxik = maxik + 1;
  for (j = 1; j < maxik; j++)
    for (i = 0; i < n; i++) {
      cur1 = otv[i][j - 1];
      cur2 = otv[cur1.first][j - 1];
      otv[i][j].second.first = cur1.second.first + cur2.second.first;
      otv[i][j].second.second = min(cur1.second.second, cur2.second.second);
      otv[i][j].first = cur2.first;
    }
  for (i = 0; i < n; i++) {
    curi = i;
    curk = k;
    s = 0;
    m = inf;
    for (j = maxik - 1; j >= 0; j--) {
      if (curk <= 0) break;
      if (curk < (1ll << j)) continue;
      s += otv[curi][j].second.first;
      m = min(m, otv[curi][j].second.second);
      curi = otv[curi][j].first;
      curk = (curk - (1ll << j));
    }
    printf("%I64d %I64d\n", s, m);
  }
  return 0;
}
