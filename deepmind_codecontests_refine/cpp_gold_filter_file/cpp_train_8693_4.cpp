#include <bits/stdc++.h>
using namespace std;
int tree[(1 << 21)];
void update(int i, int x) {
  i += (1 << 20);
  while (i) {
    tree[i] += x;
    i /= 2;
  }
}
int getsum(int l, int r, int a, int b, int i) {
  if (l >= a && r <= b) return tree[i];
  if (l > b || r < a) return 0;
  return getsum(l, (l + r) / 2, a, b, i * 2) +
         getsum((l + r) / 2 + 1, r, a, b, i * 2 + 1);
}
int main() {
  int n;
  while (cin >> n) {
    vector<pair<int, pair<int, int> > > hor, ver;
    vector<pair<int, pair<int, int> > > hor1, ver1;
    memset(tree, 0, sizeof tree);
    map<int, int> x, y, x2, y2;
    set<int> x1, y1;
    for (int f = 0; f < n; f++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if (a == c)
        ver.push_back(make_pair(a, make_pair(b, d)));
      else
        hor.push_back(make_pair(b, make_pair(a, c)));
      x1.insert(a);
      x1.insert(c);
      y1.insert(b);
      y1.insert(d);
    }
    set<int>::iterator it;
    int j = 1;
    for (it = x1.begin(); it != x1.end(); it++) {
      x2[j] = *it;
      x[*it] = j++;
    }
    j = 1;
    for (it = y1.begin(); it != y1.end(); it++) {
      y2[j] = *it;
      y[*it] = j++;
    }
    for (int f = 0; f < ver.size(); f++) {
      ver[f].first = x[ver[f].first];
      ver[f].second.first = y[ver[f].second.first];
      ver[f].second.second = y[ver[f].second.second];
      if (ver[f].second.first > ver[f].second.second)
        swap(ver[f].second.first, ver[f].second.second);
    }
    for (int f = 0; f < hor.size(); f++) {
      hor[f].first = y[hor[f].first];
      hor[f].second.first = x[hor[f].second.first];
      hor[f].second.second = x[hor[f].second.second];
      if (hor[f].second.first > hor[f].second.second)
        swap(hor[f].second.first, hor[f].second.second);
    }
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());
    int lasty = 0, xs[2] = {0};
    if (hor.size() > 0)
      lasty = hor[0].first, xs[0] = hor[0].second.first,
      xs[1] = hor[0].second.second;
    for (int f = 1; f < hor.size(); f++) {
      if (hor[f].first != lasty || xs[1] < hor[f].second.first) {
        hor1.push_back(
            make_pair(lasty, make_pair(min(xs[0], xs[1]), max(xs[0], xs[1]))));
        lasty = hor[f].first;
        xs[0] = hor[f].second.first;
        xs[1] = hor[f].second.second;
      } else {
        xs[1] = max(xs[1], hor[f].second.second);
      }
    }
    if (hor.size())
      hor1.push_back(
          make_pair(lasty, make_pair(min(xs[0], xs[1]), max(xs[0], xs[1]))));
    int lastx = 0, ys[2] = {0};
    if (ver.size() > 0)
      lastx = ver[0].first, ys[0] = ver[0].second.first,
      ys[1] = ver[0].second.second;
    for (int f = 1; f < ver.size(); f++) {
      if (ver[f].first != lastx || ys[1] < ver[f].second.first) {
        ver1.push_back(
            make_pair(lastx, make_pair(min(ys[0], ys[1]), max(ys[0], ys[1]))));
        lastx = ver[f].first;
        ys[0] = ver[f].second.first;
        ys[1] = ver[f].second.second;
      } else {
        ys[1] = max(ys[1], ver[f].second.second);
      }
    }
    if (ver.size())
      ver1.push_back(
          make_pair(lastx, make_pair(min(ys[0], ys[1]), max(ys[0], ys[1]))));
    vector<pair<int, pair<int, int> > > points;
    long long ans = 0;
    for (int f = 0; f < hor1.size(); f++) {
      points.push_back(
          make_pair(hor1[f].second.first, make_pair(-hor1[f].first, 1)));
      points.push_back(
          make_pair(hor1[f].second.second + 1, make_pair(-hor1[f].first, -1)));
      ans += (x2[hor1[f].second.second] - x2[hor1[f].second.first] + 1);
    }
    for (int f = 0; f < ver1.size(); f++) {
      points.push_back(ver1[f]);
    }
    sort(points.begin(), points.end());
    for (int f = 0; f < points.size(); f++) {
      if (points[f].second.first < 0) {
        update(-points[f].second.first, points[f].second.second);
      } else {
        ans += (y2[points[f].second.second] - y2[points[f].second.first] + 1);
        ans -= getsum(0, (1 << 20) - 1, points[f].second.first,
                      points[f].second.second, 1);
      }
    }
    cout << ans << endl;
  }
}
