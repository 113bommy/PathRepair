#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 51;
struct Segment {
  int x, y, id;
  inline bool operator<(const Segment &rhs) const { return x < rhs.x; }
  inline bool operator>(const Segment &rhs) const { return y > rhs.y; }
};
struct BIT {
  long long int x[MAXN];
  inline void add(int pos, int val);
  inline long long int query(int pos);
};
Segment seg[MAXN];
BIT bit;
int n, x, y;
long long int res, res2;
int l[MAXN], r[MAXN];
inline int read() {
  register int num = 0, neg = 1;
  register char ch = getchar();
  while (!isdigit(ch) && ch != '-') {
    ch = getchar();
  }
  if (ch == '-') {
    neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + (ch - '0');
    ch = getchar();
  }
  return num * neg;
}
inline void BIT::add(int pos, int val) {
  for (; pos <= 2 * n; pos += pos & -pos) {
    x[pos] += val;
  }
}
inline long long int BIT::query(int pos) {
  long long int res = 0;
  for (; pos; pos -= pos & -pos) {
    res += x[pos];
  }
  return res;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) {
    x = read(), y = read(), x > y ? swap(x, y) : (void)1,
    seg[i] = (Segment){x, y, i};
  }
  sort(seg + 1, seg + n + 1);
  for (register int i = 1; i <= n; i++) {
    l[seg[i].id] =
        bit.query(seg[i].x - 1) + bit.query(2 * n) - bit.query(seg[i].y);
    bit.add(seg[i].y, 1);
  }
  memset(bit.x, 0, sizeof(bit.x)),
      res = (long long int)n * (n - 1) * (n - 2) / 6;
  for (register int i = n; i; i--) {
    r[seg[i].id] = bit.query(seg[i].y - 1), bit.add(seg[i].y, 1);
  }
  memset(bit.x, 0, sizeof(bit.x)),
      sort(seg + 1, seg + n + 1, greater<Segment>());
  for (register int i = 1; i <= n; i++) {
    l[seg[i].id] += bit.query(2 * n) - bit.query(seg[i].y),
        bit.add(seg[i].x, 1);
  }
  for (register int i = 1; i <= n; i++) {
    res -= (long long int)l[i] * r[i],
        res2 += (long long int)(l[i] + r[i]) * (n - l[i] - r[i] - 1) / 2;
  }
  printf("%lld\n", res - res2 / 2);
}
