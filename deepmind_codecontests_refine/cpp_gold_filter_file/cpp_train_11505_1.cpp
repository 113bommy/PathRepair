#include <bits/stdc++.h>
namespace IO {
struct read {
  char buf[(1 << 23)], *p1, *p2, c;
  read() : p1(buf), p2(buf) {}
  char gc(void) {
    if (p1 == p2) p2 = buf + fread(p1 = buf, 1, (1 << 23), stdin);
    if (p1 == p2)
      return EOF;
    else
      return *p1++;
  }
  read &operator>>(unsigned &x) {
    c = gc(), x = 0;
    for (; c < '0' || c > '9'; c = gc())
      ;
    for (; c >= '0' && c <= '9'; c = gc()) x = x * 10 + c - '0';
    return *this;
  }
};
struct write {
  char buf[(1 << 23)], *p1, *p2, s[50], *tp;
  write() : p1(buf), p2(buf + (1 << 23)), tp(s) {}
  ~write() { flush(); }
  void flush(void) {
    fwrite(buf, 1, p1 - buf, stdout);
    p1 = buf;
  }
  void pc(char c) {
    if (p1 == p2) flush();
    *p1++ = c;
  }
  write &operator<<(unsigned x) {
    do {
      *tp++ = x % 10 + '0', x /= 10;
    } while (x);
    while (tp != s) pc(*--tp);
    return *this;
  }
  write &operator<<(char x) {
    pc(x);
    return *this;
  }
};
read in;
write out;
}  // namespace IO
using IO::in;
using IO::out;
class linear_basis {
  friend linear_basis merge(linear_basis, linear_basis);

 protected:
  unsigned c[32];

 public:
  bool insert(unsigned);
  void clear();
  unsigned query(unsigned);
  int count() {
    int tot = 0;
    for (int i = 0; i < 32; i++)
      if (c[i]) ++tot;
    return tot;
  }
};
bool linear_basis::insert(unsigned x) {
  for (unsigned i = 31; ~i; --i)
    if (x & (1u << i)) {
      if (!c[i])
        return c[i] = x, true;
      else
        x ^= c[i];
    }
  return false;
}
void linear_basis::clear() {
  for (unsigned i = 31; ~i; --i) c[i] = 0;
}
unsigned linear_basis::query(unsigned k) {
  for (unsigned i = 31; ~i; --i)
    if ((k ^ c[i]) > k) k = (k ^ c[i]);
  return k;
}
linear_basis merge(linear_basis x, linear_basis y) {
  for (unsigned i = 31; ~i; --i) x.insert(y.c[i]);
  return x;
}
class segment_tree {
 protected:
  linear_basis tr[800010];

 public:
  void build(unsigned const &, unsigned const &, unsigned const &);
  void update(unsigned const &, unsigned const &, unsigned const &,
              unsigned const &, unsigned const &);
  linear_basis query(unsigned const &, unsigned const &, unsigned const &,
                     unsigned const &, unsigned const &);
};
unsigned n, m, a[200010];
void segment_tree::build(unsigned const &x = 1, unsigned const &l = 1,
                         unsigned const &r = n) {
  if (l == r) {
    tr[x].insert(a[l]);
    return;
  }
  unsigned mid = (l + r) >> 1, ls = x << 1, rs = x << 1 | 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  tr[x] = merge(tr[ls], tr[rs]);
}
void segment_tree::update(unsigned const &p, unsigned const &v,
                          unsigned const &x = 1, unsigned const &l = 1,
                          unsigned const &r = n) {
  if (l == r) {
    tr[x].clear();
    tr[x].insert(a[l] ^= v);
    return;
  }
  unsigned mid = (l + r) >> 1, ls = x << 1, rs = x << 1 | 1;
  if (p <= mid)
    update(p, v, ls, l, mid);
  else
    update(p, v, rs, mid + 1, r);
  tr[x] = merge(tr[ls], tr[rs]);
}
linear_basis segment_tree::query(unsigned const &pl, unsigned const &pr,
                                 unsigned const &x = 1, unsigned const &l = 1,
                                 unsigned const &r = n) {
  if (l == pl && r == pr) return tr[x];
  unsigned mid = (l + r) >> 1, ls = x << 1, rs = x << 1 | 1;
  if (pr <= mid)
    return query(pl, pr, ls, l, mid);
  else if (pl > mid)
    return query(pl, pr, rs, mid + 1, r);
  else
    return merge(query(pl, mid, ls, l, mid),
                 query(mid + 1, pr, rs, mid + 1, r));
}
class binary_index_tree {
 protected:
  unsigned c[200010];

 public:
  unsigned query(unsigned);
  void update(unsigned, unsigned const &);
};
unsigned binary_index_tree::query(unsigned i) {
  unsigned ans(0);
  for (; i; i -= (i & -i)) ans ^= c[i];
  return ans;
}
void binary_index_tree::update(unsigned i, unsigned const &v) {
  for (; i <= n; i += (i & -i)) c[i] ^= v;
}
segment_tree t;
binary_index_tree p;
int main() {
  in >> n >> m;
  for (unsigned i = 1; i <= n; i++) in >> a[i];
  for (unsigned i = n; i; i--) a[i] ^= a[i - 1];
  for (unsigned i = 1; i <= n; i++) p.update(i, a[i]);
  t.build();
  while (m--) {
    unsigned op, l, r, v;
    in >> op >> l >> r;
    if (op == 1) {
      in >> v;
      p.update(l, v), t.update(l, v);
      if (r < n) p.update(r + 1, v), t.update(r + 1, v);
    } else {
      unsigned k = p.query(l);
      if (l == r)
        out << (k == 0 ? 1U : 2U) << '\n';
      else {
        linear_basis d = t.query(l + 1, r);
        d.insert(k);
        out << (1U << d.count()) << '\n';
      }
    }
  }
  return 0;
}
