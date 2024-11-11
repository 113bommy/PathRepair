#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = atan(1.0) * 4;
struct Node {
  int l, r, d;
  bool operator<(const Node &n) const { return l < n.l; }
} mid;
vector<Node> a, b;
vector<pair<int, int> > last, the;
int sgn(double x) {
  if (x < -eps)
    return -1;
  else if (x > eps)
    return 1;
  else
    return 0;
}
char s[10];
int main() {
  int hl, hr, n, ans, i;
  scanf("%d%d%d", &hl, &hr, &n);
  ans = 0;
  a.clear();
  b.clear();
  for (i = 1; i <= n; ++i) {
    scanf("%d%s%d%d", &mid.d, s, &mid.l, &mid.r);
    if (s[0] == 'T')
      a.push_back(mid);
    else
      b.push_back(mid);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  double x = pi / 3000000, y = x / 2, pt, nowx, nowy, seta, lasty;
  bool flag;
  int up, down, thes;
  last.clear();
  for (i = 1; i <= 3000000; ++i) {
    seta = x * i - y - pi / 2;
    pt = 1 / tan(seta);
    nowx = 0;
    nowy = hl;
    flag = true;
    up = 0;
    down = 0;
    the.clear();
    thes = 0;
    while (true) {
      if (sgn(pt) > 0) {
        nowx += (100 - nowy) * pt;
        if (nowx > 100000) {
          nowy = 100 - (nowx - 100000) / pt;
          break;
        }
        nowy = 100;
        pt = -pt;
        while (up < a.size() && sgn(a[up].r - nowx) < 0) ++up;
        if (up == a.size() || sgn(a[up].l - nowx) > 0) {
          flag = false;
          break;
        }
        the.push_back(make_pair(up, 0));
        thes += a[up].d;
        ++up;
      } else {
        nowx += nowy * (-pt);
        if (nowx > 100000) {
          nowy = (nowx - 100000) / (-pt);
          break;
        }
        nowy = 0;
        pt = -pt;
        while (down < b.size() && sgn(b[down].r - nowx) < 0) ++down;
        if (down == b.size() || sgn(b[down].l - nowx) > 0) {
          flag = false;
          break;
        }
        the.push_back(make_pair(down, 1));
        thes += b[down].d;
        ++down;
      }
    }
    if (!flag) {
      last.clear();
    } else {
      if (last == the && sgn(lasty - hr) * sgn(nowy - hr) <= 0)
        ans = max(ans, thes);
      lasty = nowy;
      last = the;
    }
  }
  printf("%d\n", ans);
  return 0;
}
