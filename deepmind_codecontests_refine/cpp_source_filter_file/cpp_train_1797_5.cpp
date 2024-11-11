#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxm = 5e5 + 10;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <typename A>
inline bool read(A &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= f;
  return 1;
}
inline bool read(char &x) {
  while ((x = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                           (iS == iT ? EOF : *iS++))
                        : *iS++)) == ' ' ||
         x == '\n' || x == '\r')
    ;
  return x != EOF;
}
inline bool read(char *x) {
  while ((*x = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                            (iS == iT ? EOF : *iS++))
                         : *iS++)) == '\n' ||
         *x == ' ' || *x == '\r')
    ;
  if (*x == EOF) return 0;
  while (!(*x == '\n' || *x == ' ' || *x == '\r' || *x == EOF))
    *(++x) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                          (iS == iT ? EOF : *iS++))
                       : *iS++);
  *x = 0;
  return 1;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
template <typename A>
inline bool write(A x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(char x) {
  putc(x);
  return 0;
}
inline bool write(const char *x) {
  while (*x) {
    putc(*x);
    ++x;
  }
  return 0;
}
inline bool write(char *x) {
  while (*x) {
    putc(*x);
    ++x;
  }
  return 0;
}
template <typename A, typename... B>
inline bool write(A x, B... y) {
  return write(x) || write(y...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
char s[maxm];
int rev[maxm];
struct node {
  int val[4][5];
  int len;
  node() {
    memset(val, 0, sizeof(val));
    len = 0;
  }
} tree[maxm << 2];
node operator+(node a, node b) {
  node temp;
  temp.len = a.len + b.len;
  for (int i = 1; i <= 4; i++) {
    temp.val[1][i] = a.val[1][i];
    temp.val[2][i] = b.val[2][i];
  }
  if (a.val[1][1] == a.len) temp.val[1][1] += b.val[1][4];
  if (a.val[1][2] == a.len) temp.val[1][2] += b.val[1][3];
  if (a.val[1][3] == a.len) {
    temp.val[1][3] += b.val[1][3];
    temp.val[1][1] = (a.val[1][3] + b.val[1][4]) * (b.val[1][4] > 0);
    temp.val[1][1] =
        max(temp.val[1][1], (a.val[1][3] + b.val[1][1]) * (b.val[1][1] > 0));
  }
  if (a.val[1][4] == a.len) {
    temp.val[1][4] += b.val[1][4];
    temp.val[1][2] = (a.val[1][4] + b.val[1][3]) * (b.val[1][3] > 0);
    temp.val[1][2] =
        max(temp.val[1][2], (a.val[1][4] + b.val[1][2]) * (b.val[1][2] > 0));
  }
  if (b.val[2][1] == b.len) temp.val[2][1] += a.val[2][3];
  if (b.val[2][2] == b.len) temp.val[2][2] += a.val[2][4];
  if (b.val[2][3] == b.len) {
    temp.val[2][3] += a.val[2][3];
    temp.val[2][2] = (b.len + a.val[2][4]) * (a.val[2][4] > 0);
    temp.val[2][2] =
        max(temp.val[2][2], (b.len + a.val[2][2]) * (a.val[2][2] > 0));
  }
  if (b.val[2][4] == b.len) {
    temp.val[2][4] += a.val[2][4];
    temp.val[2][1] = (b.len + a.val[2][3]) * (a.val[2][3] > 0);
    temp.val[2][1] =
        max(temp.val[2][1], (b.len + a.val[2][1]) * (a.val[2][1] > 0));
  }
  temp.val[3][3] = a.val[2][3] + b.val[1][3];
  temp.val[3][4] = a.val[2][4] + b.val[1][4];
  temp.val[3][1] = max((a.val[2][3] + b.val[1][1]) * (b.val[1][1] != 0),
                       (a.val[2][1] + b.val[1][4]) * (a.val[2][1] != 0));
  temp.val[3][2] = max((a.val[2][4] + b.val[1][2]) * (b.val[1][2] != 0),
                       (a.val[2][2] + b.val[1][3]) * (a.val[2][2] != 0));
  if (a.val[2][3] > 0 && b.val[1][4] > 0)
    temp.val[3][1] = max(temp.val[3][1], a.val[2][3] + b.val[1][4]);
  if (a.val[2][4] > 0 && b.val[1][3] > 0)
    temp.val[3][2] = max(temp.val[3][2], a.val[2][4] + b.val[1][3]);
  for (int i = 1; i <= 4; i++) {
    temp.val[3][i] = max(temp.val[3][i], max(temp.val[2][i], temp.val[1][i]));
    temp.val[3][i] = max(temp.val[3][i], max(a.val[3][i], b.val[3][i]));
  }
  return temp;
}
void pushup(int rt) { tree[rt] = tree[rt << 1] + tree[rt << 1 | 1]; }
void build(int l, int r, int rt) {
  tree[rt].len = r - l + 1;
  if (l == r) {
    if (s[l] == '<') {
      for (int i = 1; i <= 3; i++) {
        tree[rt].val[i][4] = 1;
      }
    } else {
      for (int i = 1; i <= 3; i++) {
        tree[rt].val[i][3] = 1;
      }
    }
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
void pushdown(int rt) {
  if (rev[rt]) {
    rev[rt << 1] ^= 1;
    rev[rt << 1 | 1] ^= 1;
    for (int i = 1; i <= 3; i++) {
      swap(tree[rt << 1].val[i][1], tree[rt << 1].val[i][2]);
      swap(tree[rt << 1].val[i][3], tree[rt << 1].val[i][4]);
      swap(tree[rt << 1 | 1].val[i][1], tree[rt << 1 | 1].val[i][2]);
      swap(tree[rt << 1 | 1].val[i][3], tree[rt << 1 | 1].val[i][4]);
    }
    rev[rt] = 0;
  }
}
void update(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    for (int i = 1; i <= 3; i++) {
      swap(tree[rt].val[i][1], tree[rt].val[i][2]);
      swap(tree[rt].val[i][3], tree[rt].val[i][4]);
    }
    rev[rt] ^= 1;
    return;
  }
  int mid = l + r >> 1;
  pushdown(rt);
  if (L <= mid) update(L, R, l, mid, rt << 1);
  if (R > mid) update(L, R, mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
node query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return tree[rt];
  }
  int mid = l + r >> 1;
  pushdown(rt);
  if (L > mid) return query(L, R, mid + 1, r, rt << 1 | 1);
  if (R <= mid) return query(L, R, l, mid, rt << 1);
  node tp1 = query(L, R, l, mid, rt << 1);
  node tp2 = query(L, R, mid + 1, r, rt << 1 | 1);
  return tp1 + tp2;
}
int main() {
  int n, Q;
  read(n, Q);
  read(s + 1);
  build(1, n, 1);
  while (Q--) {
    int l, r;
    read(l, r);
    update(l, r, 1, n, 1);
    node temp = query(l, r, 1, n, 1);
    int res = max(temp.val[3][1], max(temp.val[3][3], temp.val[3][4]));
    printf("%d\n", res);
  }
  return 0;
}
