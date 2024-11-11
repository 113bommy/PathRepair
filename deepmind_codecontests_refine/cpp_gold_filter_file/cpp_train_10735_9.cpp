#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 1) + (x << 3) + c - '0', c = getchar())
    ;
  x = f ? -x : x;
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
template <class T>
inline bool chkmax(T &a, T const &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool chkmin(T &a, T const &b) {
  return a > b ? a = b, 1 : 0;
}
const int N = 3e5 + 10, M = 4e6 + 10;
int Ql, Qr, Qv;
long long mx[M], tag[M];
pair<int, int> knight[N];
void down(int o) {
  long long &x = tag[o];
  if (x) {
    mx[o << 1] += x;
    mx[o << 1 | 1] += x;
    tag[o << 1] += x;
    tag[o << 1 | 1] += x;
    x = 0;
  }
}
void build(int o, int l, int r) {
  if (l == r) {
    mx[o] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
void modify(int o, int l, int r) {
  if (Ql <= l && Qr >= r) {
    mx[o] += Qv;
    tag[o] += Qv;
    return;
  }
  down(o);
  int mid = (l + r) >> 1;
  if (Ql <= mid) modify(o << 1, l, mid);
  if (Qr > mid) modify(o << 1 | 1, mid + 1, r);
  mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
long long query(int o, int l, int r) {
  if (Ql <= l && Qr >= r) return mx[o];
  down(o);
  int mid = (l + r) >> 1;
  long long res = -1e18;
  if (Ql <= mid) res = query(o << 1, l, mid);
  if (Qr > mid) chkmax(res, query(o << 1 | 1, mid + 1, r));
  return res;
}
int main() {
  build(1, 1, 1e6 + 1);
  int q;
  read(q);
  for (int i = 1; i <= q; ++i) {
    char op[5];
    scanf("%s", op);
    if (op[0] == '+') {
      read(Qr), read(Qv);
      Ql = 1;
      modify(1, 1, 1e6 + 1);
      knight[i] = make_pair(Qr, Qv);
    } else if (op[0] == '-') {
      int x;
      read(x);
      Qr = knight[x].first, Ql = 1, Qv = -knight[x].second;
      modify(1, 1, 1e6 + 1);
    } else {
      int t;
      read(t);
      Ql = 1, Qr = t;
      long long ans = query(1, 1, 1e6 + 1);
      Ql = Qr = t + 1;
      long long tmp = query(1, 1, 1e6 + 1);
      write(ans - tmp + 1);
      puts("");
    }
  }
}
