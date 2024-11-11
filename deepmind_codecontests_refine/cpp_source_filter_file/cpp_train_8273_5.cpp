#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long double eps = 1e-9;
int len, num;
int n, q;
long long a[1000000];
vector<pair<long long, int> > v[1000];
long long add[1000], p[1000];
void update(int l, int r, int x) {
  int sql = l / len, sqr = r / len, posl = l % len, posr = r % len;
  if (sql == sqr) {
    for (int i = 0; i < (int)v[sql].size(); i++)
      if (v[sql][i].second >= posl && v[sql][i].second <= posr)
        v[sql][i].first += x;
    sort(v[sql].begin(), v[sql].end());
  } else {
    for (int i = 0; i < (int)v[sql].size(); i++)
      if (v[sql][i].second >= posl) v[sql][i].first += x;
    sort(v[sql].begin(), v[sql].end());
    for (int i = sql + 1; i < sqr; i++) add[i] += x;
    for (int i = 0; i < (int)v[sqr].size(); i++)
      if (v[sqr][i].second <= posr) v[sqr][i].first += x;
    sort(v[sqr].begin(), v[sqr].end());
  }
}
int getf(long long x) {
  int l = 0, r = -1;
  vector<pair<long long, int> >::iterator it;
  for (int i = 0; i < (int)num + 1; i++) {
    it = lower_bound(v[i].begin(), v[i].end(), make_pair(x - add[i], 0));
    if (it != v[i].end() && it->first == x - add[i]) {
      l = it->second + i * len;
      break;
    }
  }
  for (int i = num; i >= 0; i--) {
    it = lower_bound(v[i].begin(), v[i].end(), make_pair(x - add[i], inf));
    if (it != v[i].begin()) it--;
    if (it->first == x - add[i]) {
      r = it->second + i * len;
      break;
    }
  }
  return r - l;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < (int)n; i++) scanf("%I64d", &a[i]);
  len = (int)sqrt(n);
  num = (n - 1) / len;
  for (int i = 0; i < (int)n; i++)
    v[i / len].push_back(make_pair(a[i], i % len));
  for (int i = 0; i < (int)num; i++) sort(v[i].begin(), v[i].end());
  int t, l, r, x;
  for (int i = 0; i < (int)q; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &l, &r, &x);
      l--;
      r--;
      update(l, r, x);
    } else {
      scanf("%d", &x);
      printf("%d\n", getf(x));
    }
  }
  return 0;
}
