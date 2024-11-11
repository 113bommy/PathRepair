#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  long long s = 0;
  long long e = (v[n - 1].first - v[0].first) * (v[n - 1].first - v[0].first);
  vector<pair<long long, long long>> leftMinMax(n);
  vector<pair<long long, long long>> rightMinMax(n);
  leftMinMax[0] = {v[0].second, v[0].second};
  for (int i = 1; i < n; ++i) {
    leftMinMax[i] = {min(leftMinMax[i - 1].first, v[i].second),
                     max(leftMinMax[i - 1].second, v[i].second)};
  }
  rightMinMax[n - 1] = {v[n - 1].second, v[n - 1].second};
  for (int i = n - 2; i >= 0; --i) {
    rightMinMax[i] = {min(rightMinMax[i + 1].first, v[i].second),
                      max(rightMinMax[i + 1].second, v[i].second)};
  }
  long long ans = e;
  ans = min(ans, (rightMinMax[0].first - rightMinMax[0].second) *
                     (rightMinMax[0].first - rightMinMax[0].second));
  e = ans - 1;
  while (s <= e) {
    long long mid = (s + e) / 2;
    int r = 0;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      if (v[i].first <= 0) {
        if (r < i) r = i;
        while (r < n && abs(v[r].first) <= abs(v[i].first) &&
               (v[r].first - v[i].first) * (v[r].first - v[i].first) <= mid)
          r++;
        if (r == n) r--;
        while (r >= i &&
               ((v[r].first - v[i].first) * (v[r].first - v[i].first) > mid ||
                abs(v[r].first) > abs(v[i].first)))
          r--;
        if (r < i) r = i;
        if (r < i) r = i;
        while (r < n && abs(v[r].first) <= abs(v[i].first) &&
               (v[r].first - v[i].first) * (v[r].first - v[i].first) <= mid)
          r++;
        if (r == n) r--;
        while (r >= i &&
               ((v[r].first - v[i].first) * (v[r].first - v[i].first) > mid ||
                abs(v[r].first) > abs(v[i].first)))
          r--;
        if (r < i) r = i;
      } else if (v[i].first > 0) {
        if (r > i) r = i;
        while (r >= 0 && abs(v[r].first) <= abs(v[i].first) &&
               (v[r].first - v[i].first) * (v[r].first - v[i].first) <= mid)
          r--;
        if (r < 0) r++;
        while (r <= i &&
               ((v[r].first - v[i].first) * (v[r].first - v[i].first) > mid ||
                abs(v[r].first) > abs(v[i].first)))
          r++;
        if (r > i) r = i;
        if (r > i) r = i;
        while (r >= 0 && abs(v[r].first) <= abs(v[i].first) &&
               (v[r].first - v[i].first) * (v[r].first - v[i].first) <= mid)
          r--;
        if (r < 0) r++;
        while (r <= i &&
               ((v[r].first - v[i].first) * (v[r].first - v[i].first) > mid ||
                abs(v[r].first) > abs(v[i].first)))
          r++;
        if (r > i) r = i;
      }
      long long xMin = min(v[i].first, v[r].first),
                xMax = max(v[i].first, v[r].first);
      int le, ri;
      le = min(i, r);
      ri = max(i, r);
      if (le != 0 || ri != n) {
        long long yMin = 1e9, yMax = -1e9;
        if (le) {
          yMin = min(yMin, leftMinMax[le - 1].first);
          yMax = max(yMax, leftMinMax[le - 1].second);
        }
        if (ri < n - 1) {
          yMin = min(yMin, rightMinMax[ri + 1].first);
          yMax = max(yMax, rightMinMax[ri + 1].second);
        }
        if ((yMax - yMin) * (yMax - yMin) <= mid) {
          long long sqX = max(xMin * xMin, xMax * xMax);
          long long sqY = max(yMin * yMin, yMax * yMax);
          if (sqX + sqY <= mid) ok = true;
        }
      } else {
        ok = true;
      }
    }
    if (ok) {
      ans = min(ans, mid);
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
