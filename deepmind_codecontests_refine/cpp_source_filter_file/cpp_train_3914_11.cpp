#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ '0');
    ch = getchar();
  }
  return f ? x : -x;
}
const int N = 1e5 + 10, M = 1e6;
long long m;
struct point {
  int x, y;
};
inline point operator+(const point &a, const point &b) {
  return (point){a.x + b.x, a.y + b.y};
}
inline point operator-(const point &a, const point &b) {
  return (point){a.x - b.x, a.y - b.y};
}
inline long long cross(const point &a, const point &b) {
  return 1ll * a.x * b.y - 1ll * b.x * a.y;
}
inline bool operator<(const point &a, const point &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
set<point> s;
inline set<point>::iterator pre(set<point>::iterator it) { return --it; }
inline set<point>::iterator nxt(set<point>::iterator it) { return ++it; }
inline void ins(point a) {
  set<point>::iterator r = s.lower_bound(a), l = pre(r);
  if (r != s.end() && cross((*l) - a, (*r) - a) >= 0) return;
  while (l != s.begin() && cross((*pre(l)) - (*l), a - (*l)) >= 0)
    --l, s.erase(nxt(l));
  if (r != s.end())
    while (nxt(r) != s.end() && cross(a - (*r), (*nxt(r)) - (*r)) >= 0)
      ++r, s.erase(pre(r));
  s.insert(a);
}
inline bool work(int t, int h) {
  set<point>::iterator x = s.lower_bound((point){(int)ceil((double)h / t), 0});
  if (x == s.end()) return 0;
  point l = (*pre(x)), r = (*x);
  long long tim =
      1ll * (r.x - l.x) * t * l.y + 1ll * (r.y - l.y) * (h - 1ll * t * l.x);
  return tim <= m * (r.x - l.x);
}
int main() {
  int j = 0, q = read();
  m = read();
  s.insert((point){0, 0});
  for (int i = (1), _ed = (q); i <= _ed; ++i) {
    int op = read() - 1, a = (read() + j) % M + 1, b = (read() + j) % M + 1;
    if (!op)
      ins((point){a, b});
    else {
      int f = work(a, b);
      if (!f)
        puts("No");
      else
        puts("Yes"), j = i;
    }
  }
  return 0;
}
