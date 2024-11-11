#include <bits/stdc++.h>
using namespace std;
const int M = 2000;
int n, m;
pair<pair<int, int>, int> v[M];
map<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> > > Q;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
pair<pair<int, int>, int> get(int x1, int y1, int x2, int y2) {
  int x = x2 - x1, y = y2 - y1;
  if (x == 0)
    y = 1;
  else if (y == 0)
    x = 1;
  else {
    int d = gcd(x, y);
    x /= d, y /= d;
  }
  if (x < 0) x = -x, y = -y;
  return make_pair(make_pair(x, y), y1 * x - x1 * y);
}
int sign(double x) {
  if (fabs(x) < 1E-6) return 0;
  return (x > 0) ? 1 : -1;
}
double dist(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}
int main() {
  Q.clear();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2;
    if (make_pair(x1, y1) > make_pair(x2, y2)) {
      swap(x1, x2);
      swap(y1, y2);
    }
    pair<pair<int, int>, int> tmp = get(x1, y1, x2, y2);
    Q[tmp].push_back(make_pair(make_pair(x1, y1), 1));
    Q[tmp].push_back(make_pair(make_pair(x2, y2), -1));
  }
  for (int i = 0; i < (m); i++) {
    scanf("%d%d%d", &v[i].first.first, &v[i].first.second, &v[i].second);
    for (int j = 0; j < (i); j++) {
      if (v[i].second != v[j].second) continue;
      int x1 = v[i].first.first, y1 = v[i].first.second, r = v[i].second;
      int x2 = v[j].first.first, y2 = v[j].first.second;
      if (sign(2 * r - dist(x1, y1, x2, y2)) >= 0) continue;
      int x0 = x1 + x2, y0 = y1 + y2;
      int x = x2 * 2 - x0, y = y2 * 2 - y0;
      pair<pair<int, int>, int> tmp = get(x0, y0, x0 - y, y0 + x);
      if (Q.find(tmp) == Q.end()) continue;
      Q[tmp].push_back(make_pair(make_pair(x0, y0), 0));
    }
  }
  int ret = 0;
  for (__typeof(Q.begin()) it = Q.begin(); it != Q.end(); it++) {
    sort(it->second.begin(), it->second.end(), cmp);
    int now = 0;
    for (__typeof(it->second.begin()) t = it->second.begin();
         t != it->second.end(); t++) {
      if (t->second == 0) ret += now;
      now += t->second;
    }
  }
  printf("%d\n", ret);
  return 0;
}
