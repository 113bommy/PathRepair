#include <bits/stdc++.h>
using namespace std;
const long double PI = acosl(-1);
const int mxn = 200001;
long long n, k;
int a[mxn], b[mxn], bit[mxn];
vector<pair<long double, long double> > v;
void add(int x, int v) {
  for (x++; x <= 2 * n; x += x & -x) bit[x] += v;
}
int qry(int x) {
  int ret = 0;
  for (x++; x; x -= x & -x) ret += bit[x];
  return ret;
}
long long sol(long double x) {
  long long ret = 0;
  v.clear();
  for (int i = 0, j = n - 1; i < n; i++) {
    long double d = sqrtl(((a[i]) * (a[i])) + ((b[i]) * (b[i])));
    if (d <= x) {
      ret += j--;
    } else {
      long double first = atan2l(b[i], a[i]), y = acosl(x / d);
      pair<long double, long double> p = {fmodl(2 * PI + first - y, 2 * PI),
                                          fmodl(2 * PI + first + y, 2 * PI)};
      v.push_back(p);
      swap(p.first, p.second);
      v.push_back(p);
    }
  }
  sort(v.begin(), v.end());
  memset(bit, 0, sizeof(bit));
  for (int i = 0; i < v.size(); i++) {
    add(i, 1);
    if (v[i].first > v[i].second) {
      int y =
          lower_bound(v.begin(), v.end(),
                      pair<long double, long double>{v[i].second, v[i].first}) -
          v.begin();
      add(y, -1);
      ret += qry(y);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(6);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  long double l = 0, r = 1e5;
  while (r - l > 1e-6) {
    long double mid = (l + r) / 2;
    if (sol(mid) >= k)
      r = mid;
    else
      l = mid;
  }
  cout << r << '\n';
  return 0;
}
