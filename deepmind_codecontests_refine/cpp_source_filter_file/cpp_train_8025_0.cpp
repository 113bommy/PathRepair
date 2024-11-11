#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = 998244353;
const int MXN = (int)2e5 + 7;
struct Pt {
  long long x, y;
  Pt(){};
  Pt(long long _x, long long _y) { x = _x, y = _y; }
  const bool operator<(const Pt &p2) const {
    if (x != p2.x) return x < p2.x;
    return y < p2.y;
  }
};
map<long long, int> mp;
map<pair<long long, long long>, int> num;
set<Pt> st[MXN];
int cntp = 0;
long long gcd(long long v1, long long v2) {
  while (v1) {
    long long tmp = v2 % v1;
    v2 = v1;
    v1 = tmp;
  }
  return v2;
}
inline void add(long long x, long long y, int t) {
  long long gd = gcd(x, y);
  x /= gd, y /= gd;
  num[make_pair(x, y)] += t;
  return;
}
int main(void) {
  int q;
  scanf("%d", &q);
  int cur = 0;
  while (q--) {
    int typ;
    scanf("%d", &typ);
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long d = x * x + y * y;
    Pt pt = Pt(x, y);
    if (typ == 1) {
      cur++;
      if (!mp[d]) {
        mp[d] = ++cntp;
        st[cntp].insert(pt);
        add(x, y, 1);
      } else {
        int p = mp[d];
        for (auto u : st[p]) {
          long long xx = u.x + x;
          long long yy = u.y + y;
          add(xx, yy, 2);
        }
        st[cntp].insert(pt);
        add(x, y, 1);
      }
    } else if (typ == 2) {
      cur--;
      int p = mp[d];
      st[p].erase(pt);
      add(x, y, -1);
      for (auto u : st[p]) {
        long long xx = u.x + x;
        long long yy = u.y + y;
        add(xx, yy, -2);
      }
    } else {
      long long gd = gcd(x, y);
      x /= gd, y /= gd;
      int ans = cur - num[make_pair(x, y)];
      printf("%d\n", ans);
    }
  }
  return 0;
}
