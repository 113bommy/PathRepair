#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0;
  register char c = getchar(), f = 1;
  while (c < 48 || c > 57) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= 48 && c <= 57)
    res = (res << 3) + (res << 1) + (c & 15), c = getchar();
  return f ? res : -res;
}
inline void write(int x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
const int N = 1e5 + 10;
struct seg {
  int l, r;
  inline seg(int a = 0, int b = 0) : l(a), r(b) {}
  inline int len() const { return r - l; }
  inline bool operator<(const seg& p) const {
    return len() > p.len() || (len() == p.len() && l > p.r);
  }
};
multiset<int> s1;
multiset<seg> s2;
inline void insert(int x) {
  s1.insert(x);
  auto p = s1.find(x), l = p, r = p;
  bool flag = 1;
  if (p != s1.begin())
    s2.insert(seg(*--l, x));
  else
    flag = 0;
  ++r;
  if (r != s1.end())
    s2.insert(seg(x, *r));
  else
    flag = 0;
  if (flag) s2.erase(seg(*l, *r));
}
inline void erase(int x) {
  auto p = s1.find(x), l = p, r = p;
  bool flag = 1;
  if (p != s1.begin())
    s2.erase(seg(*--l, x));
  else
    flag = 0;
  ++r;
  if (r != s1.end())
    s2.erase(seg(x, *r));
  else
    flag = 0;
  if (flag) s2.insert(seg(*l, *r));
  s1.erase(p);
}
inline int qry() {
  auto l = s1.begin(), r = s1.end();
  if (l == r) return 0;
  --r;
  if (l == r) return 0;
  return *r - *l - s2.begin()->len();
}
int n, m, op, x;
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) insert(read());
  write(qry()), putchar('\n');
  while (m--) {
    op = read(), x = read();
    if (op)
      insert(x);
    else
      erase(x);
    write(qry()), putchar('\n');
  }
}
