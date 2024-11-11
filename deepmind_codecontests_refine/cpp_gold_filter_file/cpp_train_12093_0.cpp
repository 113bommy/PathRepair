#include <bits/stdc++.h>
using namespace std;
int n, x, y;
map<pair<int, int>, set<long long>> slope;
vector<pair<int, int>> point;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  long long line = 0, result = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    point.push_back(make_pair(x, y));
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int x1 = point[i].first, y1 = point[i].second;
      int x2 = point[j].first, y2 = point[j].second;
      int dy = y2 - y1, dx = x2 - x1, d = gcd(dy, dx);
      dy /= d;
      dx /= d;
      if (dy < 0 || (dy == 0 && dx < 0)) {
        dy = -dy;
        dx = -dx;
      }
      pair<int, int> sslope(dy, dx);
      auto f = slope.find(sslope);
      if (f != slope.end()) {
        long long c = 1LL * dy * x1 - 1LL * dx * y1;
        auto s = f->second;
        if (s.find(c) == s.end()) {
          result += (line - s.size());
          (f->second).insert(c);
          line++;
        }
      } else {
        set<long long> s;
        s.insert(1LL * dy * x1 - 1LL * dx * y1);
        result += line;
        line++;
        slope.insert(make_pair(sslope, s));
      }
    }
  cout << result;
  return 0;
}
