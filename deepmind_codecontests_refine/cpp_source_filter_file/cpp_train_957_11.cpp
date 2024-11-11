#include <bits/stdc++.h>
using namespace std;
long long t1, t2, x1, x2, t0;
bool check(long long y1, long long y2) {
  if ((t1 * y1 + t2 * y2) - t0 * (y1 + y2) >= 0)
    return true;
  else
    return false;
}
long long result(long long y1, long long y2) {
  return (t1 * y1 + t2 * y2) - t0 * (y1 + y2);
}
int main() {
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t1 == t0 && t2 == t0)
    cout << x1 << " " << x2 << endl;
  else if (t1 == t0)
    cout << x1 << " " << 0 << endl;
  else if (t2 == t0)
    cout << 0 << " " << x2 << endl;
  else if (x2 == 1) {
    vector<pair<long long, pair<long long, pair<long long, long long> > > > w;
    if (x2 >= t0)
      w.push_back(make_pair(x2 - t0, make_pair(-1, make_pair(0, 1))));
    if (x1 >= t0)
      w.push_back(make_pair(x1 - t0, make_pair(-x1, make_pair(x1, 0))));
    for (long long i = 0; i <= x1; i++) {
      long long d = result(i, 1);
      if (d >= 0) w.push_back(make_pair(d, make_pair(-i - 1, make_pair(i, 1))));
    }
    sort(w.begin(), w.end());
    cout << w[0].second.second.first << " " << w[0].second.second.second
         << endl;
  } else {
    vector<pair<long long, pair<long long, pair<long long, long long> > > > v;
    for (long long i = 1; i <= x1; i++) {
      long long low = 0, high = x2, mid;
      while (high - low > 1) {
        mid = (low + high) / 2;
        if (check(i, mid))
          high = mid;
        else
          low = mid;
      }
      long long k = result(i, mid), u = result(i, high);
      if (k >= 0)
        v.push_back(make_pair(k, make_pair(-i - mid, make_pair(i, mid))));
      else if (u >= 0)
        v.push_back(make_pair(u, make_pair(-i - high, make_pair(i, high))));
    }
    if (v.size() == 0) {
      cout << 0 << " " << x2 << endl;
      return 0;
    }
    sort(v.begin(), v.end());
    long long p = v[0].second.second.first, q = v[0].second.second.second, r;
    bool flag = true;
    for (long long i = p; i <= x1; i += p) {
      r = i;
      if (i > x1 || q * (i / p) > x2) {
        r = i;
        flag = false;
        break;
      }
    }
    if (flag)
      cout << r << " " << q * (r / p) << endl;
    else
      cout << r - p << " " << q * ((r - p) / p) << endl;
  }
  return 0;
}
