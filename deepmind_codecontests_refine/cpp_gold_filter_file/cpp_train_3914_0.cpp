#include <bits/stdc++.h>
const long double eps = 1e-6;
bool le(long double a, long double b) { return a + eps < b; }
bool ge(long double a, long double b) { return a - eps > b; }
bool leq(long double a, long double b) { return a - eps <= b; }
bool geq(long double a, long double b) { return a + eps >= b; }
bool eq(long double a, long double b) { return a <= b + eps && b <= a + eps; }
long long m;
int Q;
struct vec {
  long double x, y;
  vec() { x = y = 0; }
  vec(long double a, long double b) { x = a, y = b; }
  long double operator^(vec b) const { return x * b.y - y * b.x; }
  long double operator*(vec b) const { return x * b.x + y * b.y; }
  long double norm2() const { return x * x + y * y; }
  long double norm() const { return sqrt(x * x + y * y); }
  vec operator-(vec b) const { return vec(x - b.x, y - b.y); }
  vec operator+(vec b) const { return vec(x + b.x, y + b.y); }
  vec operator*(long double k) const { return vec(x * k, y * k); }
  bool operator<(const vec& b) const { return x == b.x ? y > b.y : x < b.x; }
  friend std::istream& operator>>(std::istream& in, vec& x) {
    in >> x.x >> x.y;
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, vec x) {
    out << '(' << x.x << ',' << x.y << ')';
    return out;
  }
};
inline long double cross(vec a, vec b, vec c) { return (b - a) ^ (c - a); }
std::set<vec> S;
bool toleft(std::set<vec>::iterator it) {
  if (it == S.begin()) return false;
  std::set<vec>::iterator b = it;
  --b;
  if (b == S.begin()) return false;
  std::set<vec>::iterator a = b;
  --a;
  if (leq(cross(*a, *b, *it), 0)) {
    S.erase(b);
    return true;
  }
  return false;
}
bool toright(std::set<vec>::iterator it) {
  std::set<vec>::iterator b = it;
  ++b;
  if (b == S.end()) return false;
  std::set<vec>::iterator c = b;
  ++c;
  if (c == S.end()) return false;
  if (leq(cross(*it, *b, *c), 0)) {
    S.erase(b);
    return true;
  }
  return false;
}
void ins(vec x) {
  auto t = S.insert(x).first;
  while (toleft(t))
    ;
  --t;
  while (toright(t))
    ;
}
bool qry(vec x) {
  auto tmp = S.end();
  --tmp;
  if (ge(x.x, tmp->x)) return false;
  if (eq(x.x, tmp->x)) return geq(x.y, tmp->y);
  vec l, r;
  auto t = S.lower_bound(x);
  r = *t, l = *--t;
  return leq(cross(x, r, l), 0);
}
int main() {
  std::ios_base::sync_with_stdio(false), std::cin.tie(0);
  std::cin >> Q >> m;
  int lans = 0;
  S.insert(vec(0, 0));
  for (int T = 1; T <= Q; ++T) {
    int opt, x, y;
    std::cin >> opt >> x >> y;
    x = (x + lans) % 1000000 + 1;
    y = (y + lans) % 1000000 + 1;
    if (opt == 1)
      ins(vec(m * x / (long double)y, m / (long double)y));
    else {
      int v;
      if (v = qry(vec(y, x))) lans = T;
      std::cout << (v ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}
