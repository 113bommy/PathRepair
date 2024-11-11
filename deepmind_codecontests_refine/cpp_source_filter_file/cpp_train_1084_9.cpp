#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
pair<int, int> t1, t2;
vector<pair<pair<int, int>, pair<int, int> > > q;
inline void die(int a) {
  printf("%d\n", a);
  exit(0);
}
inline bool ins(pair<pair<long long, long long>, pair<long long, long long> > s,
                pair<long long, long long> t) {
  long long x1 = s.first.first, y1 = s.first.second, x2 = s.second.first,
            y2 = s.second.second;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  return t.first >= x1 && t.first <= x2 && t.second >= y1 && t.second <= y2;
}
inline bool check(vector<pair<pair<int, int>, pair<int, int> > > q) {
  long long sx = 0, sy = 0, d = 0;
  for (int i = ((int)((q).size()) - 1), _b = (1); i >= _b; i--) {
    long long s = abs(q[i].second.first - q[i].first.first);
    s = s;
    sx += s * (q[i].first.first + q[i].second.first);
    sy += s * (q[i].first.second + q[i].second.second);
    d += s * 2;
    pair<pair<long long, long long>, pair<long long, long long> > ss = q[i - 1];
    ss.first.first *= d;
    ss.first.second *= d;
    ss.second.first *= d;
    ss.second.second *= d;
    if (!ins(ss, make_pair(sx, sy))) return 0;
  }
  return 1;
}
inline bool check(int s) {
  vector<pair<pair<int, int>, pair<int, int> > > t;
  for (int _n((s + 1) - 1), i(0); i <= _n; i++) t.push_back(q[i]);
  return check(t);
}
int main() {
  scanf("%d", &n);
  for (int _n((n)-1), i(0); i <= _n; i++) {
    scanf("%d%d%d%d", &t1.first, &t1.second, &t2.first, &t2.second);
    q.push_back(make_pair(t1, t2));
  }
  for (int _n(((int)((q).size())) - 1), i(0); i <= _n; i++) {
    if (!check(i)) die(i);
  }
  die(n);
}
