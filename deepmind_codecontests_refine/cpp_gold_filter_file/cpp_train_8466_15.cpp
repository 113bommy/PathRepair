#include <bits/stdc++.h>
using namespace std;
long long int n, c;
vector<long long int> a, b;
long long int pos(long long int l) {
  long long int d1 = 0;
  for (long long int i = 0; i < n; i++) {
    long long int x = (a[i] * l) / b[i];
    x++;
    d1 += x;
  }
  return d1;
}
pair<long long int, long long int> fun(long long int l, long long int r) {
  while (r - l > 2) {
    long long int md1 = l + (r - l) / 3;
    long long int md2 = r - (r - l) / 3;
    long long int d1 = 0, d2 = 0;
    d1 = pos(md1);
    d2 = pos(md2);
    if (d2 < c)
      l = md2;
    else if (d1 > c)
      r = md1;
    else if (d1 == c && d2 == c) {
      pair<long long int, long long int> p1 = fun(l, md1);
      pair<long long int, long long int> p2 = fun(md2, r);
      pair<long long int, long long int> p = make_pair(p1.first, p2.second);
      return p;
    } else if (d2 == c) {
      pair<long long int, long long int> p1 = fun(md1, md2);
      pair<long long int, long long int> p2 = fun(md2, r);
      pair<long long int, long long int> p = make_pair(p1.first, p2.second);
      return p;
    } else if (d1 == c) {
      pair<long long int, long long int> p1 = fun(l, md1);
      pair<long long int, long long int> p2 = fun(md1, md2);
      pair<long long int, long long int> p = make_pair(p1.first, p2.second);
      return p;
    } else {
      l = md1;
      r = md2;
    }
  }
  if (r - l > 2)
    return {l, r};
  else {
    long long int in = 0;
    for (long long int i = l; i <= r; i++) {
      if (pos(i) == c) {
        l = i;
        in++;
        break;
      }
    }
    for (long long int i = r; i >= l; i--) {
      if (pos(i) == c) {
        r = i;
        break;
      }
    }
    if (in > 0)
      return {l, r};
    else
      return {-1, -1};
  }
}
int32_t main() {
  cin >> n >> c;
  a.resize(n);
  b.resize(n);
  long long int l = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] == 0) continue;
    long long int x = b[i] / a[i];
    if (b[i] % a[i] != 0) x++;
    l = max(x, l);
  }
  l = 1;
  long long int r = 1e9 + 1;
  pair<long long int, long long int> ans = fun(l, r);
  l = ans.first;
  r = ans.second;
  if (l == -1)
    cout << 0;
  else
    cout << r - l + 1;
  return 0;
}
