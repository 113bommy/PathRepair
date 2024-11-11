#include <bits/stdc++.h>
using namespace std;
const double inf = 1e5;
const double eps = 1e-5;
int main() {
  int n, width, height, begin0, begin1;
  cin >> n >> width >> height >> begin0 >> begin1;
  vector<pair<int, pair<double, double>>> a(n + 1);
  a[0] = make_pair(0, make_pair(1, begin1 - begin0));
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> a[i].first >> x >> y;
    a[i].second = make_pair(1 - (double)height / y, (double)x * height / y);
  }
  auto check = [&](double v) {
    double l = begin0, r = begin0;
    for (int i = 1; i <= n; ++i) {
      double delta = v * (a[i].first - a[i - 1].first);
      double k0 = a[i - 1].second.first, b0 = a[i - 1].second.second;
      double k1 = a[i].second.first, b1 = a[i].second.second;
      double k = k0 / k1, tl, tr;
      if (k1 > 0) {
        tl = (b0 - delta - b1) / k1;
        tr = (b0 + delta - b1) / k1;
      } else {
        tl = (b0 + delta - b1) / k1;
        tr = (b0 - delta - b1) / k1;
      }
      if (fabs(k0 - k1) < eps) {
        tl = max(tl, -delta);
        tr = min(tr, delta);
        if (tl > tr + eps) {
          return false;
        }
        l += tl;
        r += tr;
      } else {
        double ml = (tl + delta) / (1 - k), mr = (tr - delta) / (1 - k);
        double nl = inf, nr = -inf;
        if (k > 1) {
          {
            double left = max(l, mr), right = min(r, ml);
            if (right >= left - eps) {
              nl = min(nl, left - delta);
              nr = max(nr, right + delta);
            }
          }
          {
            double left = max(l, max(ml, mr)), right = r;
            if (right >= left - eps) {
              right = min(right, (delta - tl) / (k - 1));
              if (right >= left - eps) {
                nl = min(nl, k * left + tl);
                nr = max(nr, right + delta);
              }
            }
          }
          {
            double left = l, right = min(r, min(ml, mr));
            if (right >= left - eps) {
              left = max(left, -(delta + tr) / (k - 1));
              if (right >= left - eps) {
                nl = min(nl, left - delta);
                nr = max(nr, k * right + tr);
              }
            }
          }
          {
            double left = max(l, ml), right = min(r, mr);
            if (right >= left - eps) {
              nl = min(nl, k * left + tl);
              nr = max(nr, k * right + tr);
            }
          }
        } else {
          {
            double left = max(l, ml), right = min(r, mr);
            if (right >= left - eps) {
              if (k > 0) {
                nl = min(nl, k * left + tl);
                nr = max(nr, k * right + tr);
              } else {
                nl = min(nl, k * right + tl);
                nr = max(nr, k * left + tr);
              }
            }
          }
          {
            double left = l, right = min(r, min(ml, mr));
            if (right >= left - eps) {
              left = max(left, (tl - delta) / (1 - k));
              if (right >= left - eps) {
                if (k > 0) {
                  nl = min(nl, k * left + tl);
                } else {
                  nl = min(nl, k * right + tl);
                }
                nr = max(nr, right + delta);
              }
            }
          }
          {
            double left = max(l, max(ml, mr)), right = r;
            if (right >= left - eps) {
              right = min(right, (tr + delta) / (1 - k));
              if (right >= left - eps) {
                nl = min(nl, left - delta);
                if (k > 0) {
                  nr = max(nr, k * right + tr);
                } else {
                  nr = max(nr, k * left + tr);
                }
              }
            }
          }
          {
            double left = max(l, mr), right = min(r, ml);
            if (right >= left - eps) {
              nl = min(nl, left - delta);
              nr = max(nr, right + delta);
            }
          }
        }
        if (nl > nr + eps) {
          return false;
        }
        l = nl;
        r = nr;
      }
      l = max(l, (double)0);
      r = min(r, (double)width);
      if (k1 > 0) {
        l = max(l, -b1 / k1);
        r = min(r, (width - b1) / k1);
      } else {
        l = max(l, (width - b1) / k1);
        r = min(r, -b1 / k1);
      }
      if (l > r + eps) {
        return false;
      }
    }
    return true;
  };
  if (!check(width + 1)) {
    cout << -1 << endl;
  } else {
    double l = 0, r = width;
    for (int t = 0; t < 50; ++t) {
      double m = (l + r) / 2;
      if (check(m)) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << fixed << setprecision(6) << r << endl;
  }
  return 0;
}
