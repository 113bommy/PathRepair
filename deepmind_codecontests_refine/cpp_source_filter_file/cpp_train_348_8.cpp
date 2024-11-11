#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > x2, y2, t;
vector<pair<int, pair<int, int> > > x, y;
int cal(int len, int want) {
  sort(t.begin(), t.end());
  t.push_back(make_pair(len, len));
  vector<pair<int, int> > s;
  int now = 0, i;
  for (i = 0; i < t.size(); i++) {
    if (now < t[i].first) s.push_back(make_pair(now, t[i].first));
    now = max(now, t[i].second);
  }
  for (i = 0; i < s.size(); i++) {
    if (want <= s[i].second - s[i].first) return s[i].first + want;
    want -= s[i].second - s[i].first;
  }
  return -1;
}
int main() {
  int i, j, n, m, k, xa, xb, ya, yb, gran = 0;
  cin >> n >> m >> k;
  for (i = 0; i < k; i++) {
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    if (xa == xb) {
      if (ya > yb) swap(ya, yb);
      x.push_back(make_pair(xa, make_pair(ya, yb)));
    }
    if (ya == yb) {
      if (xa > xb) swap(xa, xb);
      y.push_back(make_pair(ya, make_pair(xa, xb)));
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  x.push_back(make_pair(1234567890, make_pair(0, 0)));
  y.push_back(make_pair(1234567890, make_pair(0, 0)));
  int sum = 0, now = 0;
  for (i = 0; i < x.size(); i++) {
    if (i > 0 && x[i].first > x[i - 1].first) {
      x2.push_back(make_pair(x[i - 1].first, m - sum));
      sum = now = 0;
    }
    sum += max(0, x[i].second.second - max(now, x[i].second.first));
    now = max(now, x[i].second.second);
  }
  sum = now = 0;
  for (i = 0; i < y.size(); i++) {
    if (i > 0 && y[i].first > y[i - 1].first) {
      y2.push_back(make_pair(y[i - 1].first, n - sum));
      sum = now = 0;
    }
    sum += max(0, y[i].second.second - max(now, y[i].second.first));
    now = max(now, y[i].second.second);
  }
  int xs = x2.size(), ys = y2.size(), xe = -1, ye = -1;
  for (i = 0; i < xs; i++) gran ^= x2[i].second;
  if ((n - 1 - xs) % 2 > 0) gran ^= m;
  for (i = 0; i < ys; i++) gran ^= y2[i].second;
  if ((m - 1 - ys) % 2 > 0) gran ^= n;
  if (gran < 1) {
    cout << "SECOND" << endl;
    return 0;
  }
  cout << "FIRST" << endl;
  if (xs < 1) xe = 1;
  if (xs > 0 && n - 1 - xs > 0) {
    if (x2[0].first > 1) xe = 1;
    if (x2[xs - 1].first < n - 1) xe = n - 1;
    for (i = 0; i < xs - 1; i++) {
      if (x2[i].first + 1 < x2[i + 1].first) xe = x2[i].first + 1;
    }
  }
  if (ys < 1) ye = 1;
  if (ys > 0 && n - 1 - ys > 0) {
    if (y2[0].first > 1) ye = 1;
    if (y2[ys - 1].first < n - 1) ye = n - 1;
    for (i = 0; i < ys - 1; i++) {
      if (y2[i].first + 1 < y2[i + 1].first) ye = y2[i].first + 1;
    }
  }
  if (n - 1 - xs > 0 && (m ^ gran) < m) {
    cout << xe << " 0 " << xe << ' ' << (m - (m ^ gran)) << endl;
    return 0;
  }
  if (m - 1 - ys > 0 && (n ^ gran) < n) {
    cout << "0 " << ye << ' ' << (n - (n ^ gran)) << ' ' << ye << endl;
    return 0;
  }
  for (i = 0; i < xs; i++) {
    if (x2[i].second ^ gran < x2[i].second) {
      for (j = 0; j < x.size(); j++) {
        if (x[j].first == x2[i].first) t.push_back(x[j].second);
      }
      cout << x2[i].first << " 0 " << x2[i].first << ' '
           << cal(m, x2[i].second - (x2[i].second ^ gran)) << endl;
      return 0;
    }
  }
  for (i = 0; i < ys; i++) {
    if (y2[i].second ^ gran < y2[i].second) {
      for (j = 0; j < y.size(); j++) {
        if (y[j].first == y2[i].first) t.push_back(y[j].second);
      }
      cout << "0 " << y2[i].first << ' '
           << cal(n, y2[i].second - (y2[i].second ^ gran)) << ' ' << y2[i].first
           << endl;
      return 0;
    }
  }
  return 0;
}
