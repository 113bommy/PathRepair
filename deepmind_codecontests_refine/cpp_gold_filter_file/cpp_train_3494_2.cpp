#include <bits/stdc++.h>
using namespace std;
long double ans;
long long one, two;
map<pair<long long, long long>, pair<long long, long long> > o, t;
map<pair<long long, long long>, pair<long long, long long> >::iterator ii;
void add(long long a, long long b, long long c, long long ind) {
  pair<long long, long long> p = make_pair(a, b);
  if (c > o[p].first && ind != t[p].second) {
    t[p] = o[p];
    o[p] = {c, ind};
  }
  if (c > t[p].first && ind != o[p].second) t[p] = {c, ind};
}
int main() {
  long long n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long t = min(a, min(b, c));
    long double cur = 1.0 * t / 2;
    if (cur > ans) {
      ans = cur;
      one = i;
    }
    add(a, b, c, i);
    add(a, c, b, i);
    add(b, a, c, i);
    add(b, c, a, i);
    add(c, a, b, i);
    add(c, b, a, i);
  }
  for (ii = t.begin(); ii != t.end(); ii++) {
    long long cur = ii->second.first + o[ii->first].first;
    long long Min = min(cur, min(ii->first.first, ii->first.second));
    long double curans = 1.0 * Min / 2;
    if (curans > ans) {
      ans = curans;
      one = ii->second.second;
      two = o[ii->first].second;
    }
  }
  if (one != 0 && two != 0)
    cout << "2\n" << one << " " << two;
  else
    cout << "1\n" << one;
  return 0;
}
