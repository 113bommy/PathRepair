#include <bits/stdc++.h>
const int MAXN = 1e5;
const int MAXS = 1e6 + 2;
int n, m, tot;
int bit[MAXS + 5];
long long ans;
struct Modi {
  int pos, id, val;
  Modi(int _pos = 0, int _id = 0, int _val = 0)
      : pos(_pos), id(_id), val(_val) {}
  friend bool operator<(const Modi &lhs, const Modi &rhs) {
    return lhs.pos < rhs.pos;
  }
} a[MAXN << 1 | 1];
struct Query {
  int l, r, pos;
  Query(int _l = 0, int _r = 0, int _pos = 0) : l(_l), r(_r), pos(_pos) {}
  friend bool operator<(const Query &lhs, const Query &rhs) {
    return lhs.pos < rhs.pos;
  }
} b[MAXN | 1];
inline int read() {
  register int x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
void modify(int x, int y) {
  for (; x <= MAXS + 1; x += x & (-x)) bit[x] += y;
}
int query(int x) {
  int res = 0;
  for (; x > 0; x -= x & (-x)) res += bit[x];
  return res;
}
int main() {
  n = read();
  m = read();
  ans = 1;
  for (int i = 1; i <= n; ++i) {
    int y = read() + 1, l = read() + 1, r = read() + 1;
    a[++tot] = Modi(l, y, 1);
    a[++tot] = Modi(r + 1, y, -1);
    ans += (l == 1 && r == 1e6 + 1);
  }
  for (int i = 1; i <= m; ++i) {
    b[i].pos = read() + 1;
    b[i].l = read() + 1;
    b[i].r = read() + 1;
    ans += (b[i].l == 1 && b[i].r == 1e6 + 1);
  }
  std::sort(a + 1, a + 1 + tot);
  std::sort(b + 1, b + 1 + m);
  int p = 1;
  for (int i = 1; i <= n; ++i) {
    while (a[p].pos <= b[i].pos && p <= tot) {
      modify(a[p].id, a[p].val);
      ++p;
    }
    ans += query(b[i].r) - query(b[i].l - 1);
  }
  printf("%lld\n", ans);
  return 0;
}
