#include <bits/stdc++.h>
using namespace std;
pair<int, int> transform(const pair<int, int>& org, int dir) {
  switch (dir) {
    case (0):
      return org;
    case (1):
      return make_pair(org.second, -org.first);
    case (2):
      return make_pair(-org.first, -org.second);
    case (3):
      return make_pair(-org.second, org.first);
  }
  assert(false);
}
int dir1[] = {0, 0, 2, 2};
int dir2[] = {1, 3, 1, 3};
void ok() {
  cout << "YES" << endl;
  exit(0);
}
long long GreatestCommonDivisor(long long abc, long long def) {
  if (abc < 0LL || def < 0LL) return GreatestCommonDivisor(abs(abc), abs(def));
  if (abc < def) return GreatestCommonDivisor(def, abc);
  if (!def) return abc;
  return GreatestCommonDivisor(def, abc % def);
}
int solve(long long x1, long long x2, long long x3) {
  return x3 % GreatestCommonDivisor(x1, x2) == 0LL;
}
int main() {
  pair<int, int> a;
  cin >> a.first >> a.second;
  pair<int, int> t;
  cin >> t.first >> t.second;
  pair<int, int> b;
  cin >> b.first >> b.second;
  for (int(i) = 0; (i) < (4); ++(i)) {
    pair<int, int> trans = transform(a, i);
    pair<int, int> target =
        make_pair(t.first - trans.first, t.second - trans.second);
    if (target.first == 0 && target.second == 0) {
      cout << "YES" << endl;
      return 0;
    }
    if (b.first == 0 && b.second == 0) {
      continue;
    }
    for (int(j) = 0; (j) < (4); ++(j)) {
      int d1 = dir1[j];
      int d2 = dir2[j];
      pair<int, int> trans1, trans2;
      trans1 = transform(b, d1);
      trans2 = transform(b, d2);
      long long x1 = trans1.first;
      long long y1 = trans1.second;
      long long x2 = trans2.first;
      long long y2 = trans2.first;
      long long x3 = target.first;
      long long y3 = target.second;
      if (x1 == 0LL && x2 == 0LL && x3 != 0LL) continue;
      if (y1 == 0LL && y2 == 0LL && y3 != 0LL) continue;
      if (x1 == 0LL && x2 == 0LL && x3 == 0LL) {
        if (solve(y1, y2, y3)) ok();
      } else if (y1 == 0LL && y2 == 0LL && y3 == 0LL) {
        if (solve(x1, x2, x3)) ok();
      } else {
        long long gcdx =
            GreatestCommonDivisor(x1, GreatestCommonDivisor(x2, x3));
        long long gcdy =
            GreatestCommonDivisor(y1, GreatestCommonDivisor(y2, y3));
        x1 /= gcdx;
        x2 /= gcdx;
        x3 /= gcdx;
        y1 /= gcdy;
        y2 /= gcdy;
        y3 /= gcdy;
        long long det = x1 * y2 - x2 * y1;
        if (det == 0LL) {
          if (solve(x1, x2, x3) && solve(y1, y2, y3)) ok();
          continue;
        }
        long long xnum = x2 * y3 - x3 * y2;
        long long xden = x2 * y1 - x1 * y2;
        if (xnum % xden != 0LL) continue;
        long long ynum = x1 * y3 - x3 * y1;
        if (ynum % xden != 0LL) continue;
        ok();
      }
    }
  }
  cout << "NO\n";
  return 0;
}
