#include <bits/stdc++.h>
using std::set;
const long double eps = 1e-13;
template <typename num>
inline void read(num &ans) {
  ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') ans = ans * 10 + c - 48, c = getchar();
  return;
}
struct vec {
  long double x, y;
  inline vec operator+(const vec &b) const { return (vec){x + b.x, y + b.y}; }
  inline vec operator-(const vec &b) const { return (vec){x - b.x, y - b.y}; }
  inline vec operator*(const long double &k) const {
    return (vec){x * k, y * k};
  }
  inline bool operator<(const vec &b) const {
    return x == b.x ? y < b.y : x < b.x;
  }
  inline long double operator^(const vec &b) const { return x * b.y - y * b.x; }
};
set<vec> cnvx;
inline bool check(set<vec>::iterator it) {
  set<vec>::iterator pre = it, nxt = it;
  --pre;
  if (pre->y >= it->y) return 1;
  ++nxt;
  if (nxt != cnvx.end() && ((*it - *pre) ^ (*nxt - *it)) >= 0.0) return 1;
  return 0;
}
inline void insert(vec v) {
  set<vec>::iterator it = cnvx.insert(v).first, jt;
  if (check(it)) return cnvx.erase(it), void();
  for (jt = it, ++jt; jt != cnvx.end() && check(jt);) cnvx.erase(jt++);
  for (jt = it, --jt; jt != cnvx.begin() && check(jt);) cnvx.erase(jt--);
  return;
}
inline vec crosspoint(vec a, vec b, vec c, vec d) {
  long double s1 = (b - a) ^ (c - a), s2 = (b - a) ^ (d - a);
  return c + (c - d) * (s1 / (s2 - s1));
}
inline long double damage(long double time) {
  set<vec>::iterator it = cnvx.lower_bound((vec){time, 0.0}), jt;
  if (it == cnvx.end()) return (--it)->y;
  jt = it, --jt;
  return crosspoint(*jt, *it, (vec){time, 0.0}, (vec){time, 1.0}).y;
}
int n;
long double m;
int main() {
  cnvx.insert((vec){0.0, 0.0});
  read(n), read(m);
  int opt, last = 0, x, y;
  for (register int i = 1; i <= n; ++i) {
    read(opt), read(x), read(y);
    x = (x + last) % 1000000 + 1, y = (y + last) % 1000000 + 1;
    switch (opt) {
      case 1:
        insert((vec){m / y, m / y * x});
        break;
      case 2:
        if (damage(x) > y)
          last = 1, puts("YES");
        else
          puts("NO");
        break;
    }
  }
  return 0;
}
