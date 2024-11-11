#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxn = (int)2e5 + 10;
const int inf = (int)1e9 + 5;
const int mod = (int)1e6 + 3;
const long long llinf = (long long)1e18 + 5;
const long double pi = acos(-1.0);
struct pnt {
  long long x, y;
  pnt() {}
  pnt(int x, int y) : x(x), y(y) {}
  bool operator<(const pnt &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
  bool operator==(const pnt &rhs) const { return x == rhs.x && y == rhs.y; }
};
long long get(pnt a, pnt b, pnt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}
vector<pnt> pts;
int n;
pnt up[maxn];
int uplen;
pnt down[maxn];
int downlen;
vector<pnt> findch() {
  sort((pts).begin(), (pts).end());
  pts.erase(unique((pts).begin(), (pts).end()), pts.end());
  up[uplen++] = pts[0];
  down[downlen++] = pts[0];
  n = (int)pts.size();
  for (int i = (1); i < (n); i++) {
    if (i == n - 1 || get(pts[0], pts[i], pts[n - 1]) < 0) {
      while (uplen >= 2 && get(up[uplen - 2], up[uplen - 1], pts[i]) >= 0)
        uplen--;
      up[uplen++] = pts[i];
    }
    if (i == n - 1 || get(pts[0], pts[i], pts[n - 1]) > 0) {
      while (downlen >= 2 &&
             get(down[downlen - 2], down[downlen - 1], pts[i]) <= 0)
        downlen--;
      down[downlen++] = pts[i];
    }
  }
  vector<pnt> ret;
  for (int i = (0); i < (uplen); i++) ret.push_back(up[i]);
  for (int i = (downlen - 1) - 1; i >= (1); i--) ret.push_back(down[i]);
  return ret;
}
long long S;
long long triarea(pnt a, pnt b, pnt c) {
  return abs((a.x - b.x) * (a.y + b.y) + (b.x - c.x) * (b.y + c.y) +
             (c.x - a.x) * (c.y + a.y));
}
int nxt(int i) { return i + 1 < n ? i + 1 : 0; }
void upd(pnt &a, pnt &b, pnt &c, pnt a2, pnt b2, pnt c2) {
  if (triarea(a, b, c) < triarea(a2, b2, c2)) {
    a = a2, b = b2, c = c2;
  }
}
void printp(pnt a, pnt b, pnt c) {
  cout << a.x + b.x - c.x << ' ' << a.y + b.y - c.y << '\n';
}
int main() {
  cin >> n >> S;
  for (int i = (0); i < (n); i++) {
    int x, y;
    cin >> x >> y;
    pts.push_back(pnt(x, y));
  }
  auto hull = findch();
  pnt a = hull[0], b = hull[1], c = hull[2];
  n = hull.size();
  for (int i = (0); i < (n); i++) {
    int cur = nxt(nxt(i));
    int j = i;
    for (int _ = (0); _ < (n); _++) {
      j = nxt(j);
      upd(a, b, c, hull[i], hull[j], hull[cur]);
      while (triarea(hull[i], hull[j], hull[cur]) <
             triarea(hull[i], hull[j], hull[nxt(cur)])) {
        cur = nxt(cur);
        upd(a, b, c, hull[i], hull[j], hull[cur]);
      }
    }
  }
  printp(a, b, c);
  printp(b, c, a);
  printp(c, a, b);
  return 0;
}
