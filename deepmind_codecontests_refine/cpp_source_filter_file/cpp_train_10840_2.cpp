#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
int n, m, d, tot, gen[30], b[N];
long long len[70], l, r;
bitset<N> full;
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  if (f) x = -x;
}
struct node {
  long long ans, len;
  bitset<N> pre, suf;
  node operator+(const node &a) {
    node b;
    b.ans = ans + a.ans;
    b.len = len + a.len;
    b.pre = pre;
    b.suf = a.suf;
    if (len < n - 1) b.pre &= (a.pre >> len) | (full << n - 1 - len);
    if (a.len < n - 1) b.suf &= (suf << a.len) | (full >> n - 1 - a.len);
    if (len + a.len >= n) {
      bitset<N> res = suf & a.pre;
      if (len < n - 1) res &= (full >> n - 1 - len);
      if (a.len < n - 1) res &= (full << n - 1 - a.len);
      b.ans += res.count();
    }
    return b;
  }
  void operator+=(const node &a) { *this = !len ? a : *this + a; }
} f[70][70];
long long query(long long x) {
  node res;
  res.ans = res.len = 0;
  int tmp = 0;
  for (int i = tot; ~i; --i)
    for (int j = 1; j <= d; j++) {
      if (x >= len[i]) {
        x -= len[i];
        res += f[i][(tmp + gen[j]) % m];
      } else {
        tmp = (tmp + gen[j]) % m;
        break;
      }
    }
  return res.ans;
}
int main() {
  read(d);
  read(m);
  for (int i = 1; i <= d; i++) read(gen[i]);
  read(n);
  for (int i = 1; i <= n; i++) read(b[i]);
  for (int i = 1; i < n; i++) full.set(1);
  len[tot] = 1;
  for (int i = 0; i < m; i++) {
    f[0][i].len = 1;
    if (n == 1)
      f[0][i].ans = i <= b[1];
    else {
      for (int j = 1; j <= n - 1; j++) {
        f[0][i].pre[j] = i <= b[j + 1];
        f[0][i].suf[j] = i <= b[j];
      }
    }
  }
  read(l);
  read(r);
  for (; len[tot] <= r / d;) {
    ++tot;
    len[tot] = len[tot - 1] * d;
    for (int i = 0; i < m; i++)
      for (int j = 1; j <= d; j++) f[tot][i] += f[tot - 1][(i + gen[j]) % m];
  }
  printf("%lld\n", query(r) - query(l + n - 2));
  return 0;
}
