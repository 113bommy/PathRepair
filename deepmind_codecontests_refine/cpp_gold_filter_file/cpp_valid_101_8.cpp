#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
} p[2][300005];
struct Sta {
  int num, val, upd;
} s[2][200005];
int T, n, m, k, num[2];
map<int, bool> r;
map<int, bool> c;
int rr[200005], cc[200005];
inline int cmp1(const Point& a, const Point& b) { return a.x < b.x; }
inline int cmp2(const Point& a, const Point& b) { return a.y < b.y; }
int lower(int w, int t) {
  int ans;
  int l = 1, r;
  if (t == 0)
    r = m;
  else
    r = n;
  while (l <= r) {
    int mid = l + r >> 1;
    if (t == 0) {
      if (cc[mid] <= w)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (t == 1) {
      if (rr[mid] <= w)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
  }
  return ans;
}
int main() {
  cin >> T;
  while (T--) {
    r.clear();
    c.clear();
    num[0] = num[1] = 0;
    cin >> n >> m >> k;
    int lim = max(n, m);
    for (int i = 0; i <= lim; ++i) {
      s[0][i].num = 0;
      s[0][i].upd = 0;
      s[0][i].val = -1;
      s[1][i].num = 0;
      s[1][i].upd = 0;
      s[1][i].val = -1;
    }
    for (int i = 1; i <= n; ++i) {
      cin >> rr[i];
      r[rr[i]] = true;
    }
    for (int i = 1; i <= m; ++i) {
      cin >> cc[i];
      c[cc[i]] = true;
    }
    sort(rr + 1, rr + n + 1);
    sort(cc + 1, cc + m + 1);
    for (int i = 1; i <= k; ++i) {
      int x, y;
      cin >> x >> y;
      if (r[x] && c[y]) continue;
      if (r[x])
        p[0][++num[0]].x = x, p[0][num[0]].y = y;
      else
        p[1][++num[1]].x = x, p[1][num[1]].y = y;
    }
    sort(p[0] + 1, p[0] + num[0] + 1, cmp1);
    sort(p[1] + 1, p[1] + num[1] + 1, cmp2);
    long long ans = 0;
    for (int i = 1; i <= num[0]; ++i) {
      int pos = lower(p[0][i].y, 0);
      if (p[0][i].x > s[0][pos].val)
        s[0][pos].num += s[0][pos].upd, s[0][pos].val = p[0][i].x,
                                        s[0][pos].upd = 1;
      else
        ++s[0][pos].upd;
      ans += s[0][pos].num;
    }
    for (int i = 1; i <= num[1]; ++i) {
      int pos = lower(p[1][i].x, 1);
      if (p[1][i].y > s[1][pos].val)
        s[1][pos].num += s[1][pos].upd, s[1][pos].val = p[1][i].y,
                                        s[1][pos].upd = 1;
      else
        ++s[1][pos].upd;
      ans += s[1][pos].num;
    }
    cout << ans << endl;
  }
  return 0;
}
