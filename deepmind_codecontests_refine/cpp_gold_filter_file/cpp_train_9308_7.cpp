#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = (long long)INF * INF;
const int MAX = 2019;
int n, m;
pair<int, int> blue[MAX];
pair<int, int> red[MAX];
pair<pair<int, int>, int> hor[MAX];
pair<int, pair<int, int> > ver[MAX];
bool ok(int t) {
  int cntHor = 0;
  for (int i = 0, p; i < n; i = p + 1) {
    p = i;
    while (p + 1 < n && blue[p + 1].first == blue[i].first &&
           blue[p + 1].second - t <= blue[p].second + t)
      p++;
    hor[cntHor++] = make_pair(make_pair(blue[p].second + t, blue[i].second - t),
                              blue[i].first);
  }
  sort(hor, hor + cntHor);
  int cntVer = 0;
  for (int i = 0, p; i < m; i = p + 1) {
    p = i;
    while (p + 1 < m && red[p + 1].first == red[i].first &&
           red[p + 1].second - t <= red[p].second + t)
      p++;
    ver[cntVer++] = make_pair(red[i].first,
                              make_pair(red[i].second - t, red[p].second + t));
  }
  for (int i = (0); i < (cntVer); ++i) {
    set<int> S;
    int ptr = cntHor - 1;
    for (int j = (cntVer)-1; j >= (i + 1); --j) {
      while (ptr >= 0 && hor[ptr].first.first >= ver[j].first) {
        if (hor[ptr].first.second <= ver[i].first &&
            hor[ptr].second >= ver[i].second.first &&
            hor[ptr].second <= ver[i].second.second) {
          S.insert(hor[ptr].second);
        }
        ptr--;
      }
      auto it = S.lower_bound(ver[j].second.first);
      if (it != S.end()) {
        it++;
        if (it != S.end() && *it <= ver[j].second.second) return true;
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    blue[i] = make_pair(x + y, x - y);
  }
  for (int i = (0); i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    red[i] = make_pair(x - y, x + y);
  }
  sort(blue, blue + n);
  sort(red, red + m);
  int l = 0, r = 4 * 1000 * 1000;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  if (ok(r)) {
    cout << (r + 1) / 2;
  } else {
    cout << "Poor Sereja!";
  }
  return 0;
}
