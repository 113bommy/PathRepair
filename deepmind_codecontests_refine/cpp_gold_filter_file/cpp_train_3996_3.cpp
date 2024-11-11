#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int MAXIOSIZE = 1 << 24 | 1;
unsigned char buf[MAXIOSIZE], *p1, *p2;
template <typename T>
void read(T& x) {
  x = 0;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 24, stdin), p1 == p2)
           ? EOF
           : *p1++);
  bool flg = false;
  for (; ch < '0' || '9' < ch;
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 24, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-') flg |= true;
  for (; '0' <= ch && ch <= '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 24, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    x = x * 10 + ch - '0';
  flg ? x = -x : 0;
}
template <typename T>
void out(const T& x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void write(const T& x, const char& ed = ' ') {
  if (x < 0)
    putchar('-'), out(-x);
  else
    out(x);
  putchar(ed);
}
}  // namespace IO
const int MAXN = 1e5 + 10;
int n, arr[MAXN];
struct Segment_tree {
  struct Node {
    long long dat, tag;
  } t[MAXN << 2];
  void pushup(int k) { t[k].dat = max(t[k << 1].dat, t[k << 1 | 1].dat); }
  void pushdown(int k) {
    if (!t[k].tag) return;
    t[k << 1].dat = t[k << 1].tag = t[k].tag;
    t[k << 1 | 1].dat = t[k << 1 | 1].tag = t[k].tag;
    return t[k].tag = 0, void();
  }
  void build(int k, int l, int r) {
    if (l == r) return t[k].dat = arr[l], void();
    build(k << 1, l, ((l + r) >> 1)), build(k << 1 | 1, ((l + r) >> 1) + 1, r);
    pushup(k);
  }
  long long query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return t[k].dat;
    pushdown(k);
    long long ret = 0;
    if (ql <= ((l + r) >> 1))
      ret = max(ret, query(k << 1, l, ((l + r) >> 1), ql, qr));
    if (qr > ((l + r) >> 1))
      ret = max(ret, query(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr));
    return ret;
  }
  void modify(int k, int l, int r, int ql, int qr, long long v) {
    if (ql <= l && r <= qr) return t[k].dat = t[k].tag = v, void();
    pushdown(k);
    if (ql <= ((l + r) >> 1)) modify(k << 1, l, ((l + r) >> 1), ql, qr, v);
    if (qr > ((l + r) >> 1))
      modify(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr, v);
    pushup(k);
  }
} sgt;
int main() {
  IO::read(n);
  for (int i = (1), iend = (n); i <= iend; ++i) IO::read(arr[i]);
  sgt.build(1, 1, n);
  int q;
  IO::read(q);
  for (int i = (1), iend = (q); i <= iend; ++i) {
    int w, h;
    long long ans;
    IO::read(w), IO::read(h);
    IO::write(ans = sgt.query(1, 1, n, 1, w), '\n');
    sgt.modify(1, 1, n, 1, w, ans + h);
  }
  return 0;
}
