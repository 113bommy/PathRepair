#include <bits/stdc++.h>
char buf[1000000], *p1 = buf, *p2 = buf;
inline char gc() {
  if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
  return p1 == p2 ? EOF : *(p1++);
}
template <class T>
inline void read(T &n) {
  n = 0;
  register int ch = gc(), f;
  while ((ch < '0' || ch > '9') && ch != '-') ch = gc();
  f = ch == '-' ? ch = gc(), -1 : 1;
  while (ch >= '0' && ch <= '9') n = n * 10 + (ch ^ 48), ch = gc();
  n *= f;
}
using namespace std;
struct node {
  long long x, y;
  bool operator<(const node &A) const {
    return (y >= 0) ^ (A.y >= 0)
               ? y > A.y
               : (x * A.y - y * A.x == 0 ? x < A.x : x * A.y - y * A.x > 0);
  }
};
multiset<node> s;
inline bool In(int x, int y) {
  auto it = s.insert((node){x, y});
  auto pre = it, nxt = it;
  if (pre == s.begin()) pre = s.end();
  --pre;
  ++nxt;
  if (nxt == s.end()) nxt = s.begin();
  long long x0 = nxt->x - pre->x, y0 = nxt->y - pre->y, x1 = it->x - pre->x,
            y1 = it->y - pre->y;
  s.erase(it);
  if (x0 * y1 - y0 * x1 >= 0) return 1;
  return 0;
}
int main() {
  int n;
  read(n);
  int x0, y0, x1, y1, x2, y2, tmp, ox0, oy0;
  read(tmp), read(x0), read(y0);
  read(tmp), read(x1), read(y1);
  read(tmp), read(x2), read(y2);
  ox0 = x0 + x1 + x2, oy0 = y0 + y1 + y2;
  s.insert((node){x0 * 3 - ox0, y0 * 3 - oy0});
  s.insert((node){x1 * 3 - ox0, y1 * 3 - oy0});
  s.insert((node){x2 * 3 - ox0, y2 * 3 - oy0});
  for (register int i = 4; i <= n; ++i) {
    int opt, x, y;
    read(opt), read(x), read(y);
    x = x * 3 - ox0, y = y * 3 - oy0;
    if (opt == 1) {
      if (In(x, y)) continue;
      auto it = s.insert((node){x, y});
      while (666) {
        auto pre = it, pree = it;
        if (it == s.begin()) pre = pree = s.end();
        --pre, --pree;
        if (pree == s.begin()) pree = s.end();
        --pree;
        long long x0 = pre->x - pree->x, y0 = pre->y - pree->y,
                  x1 = it->x - pree->x, y1 = it->y - pree->y;
        if (x0 * y1 - y0 * x1 <= 0)
          s.erase(pre);
        else
          break;
      }
      while (666) {
        auto nxt = it, nxtt = it;
        ++nxt, ++nxtt;
        if (nxt == s.end()) nxt = nxtt = s.begin();
        ++nxtt;
        if (nxtt == s.end()) nxtt = s.begin();
        long long x0 = nxt->x - it->x, y0 = nxt->y - it->y,
                  x1 = nxtt->x - it->x, y1 = nxtt->y - it->y;
        if (x0 * y1 - y0 * x1 <= 0)
          s.erase(nxt);
        else
          break;
      }
    } else if (In(x, y))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
