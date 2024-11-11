#include <bits/stdc++.h>
struct ios {
  template <typename ATP>
  inline ios &operator>>(ATP &x) {
    x = 0;
    int f = 1;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
      if (c == '-') f = -1;
    while (c >= '0' && c <= '9') x = x * 10 + (c ^ '0'), c = getchar();
    x *= f;
    return *this;
  }
} io;
using namespace std;
template <typename ATP>
inline ATP Max(ATP a, ATP b) {
  return a > b ? a : b;
}
template <typename ATP>
inline ATP Min(ATP a, ATP b) {
  return a < b ? a : b;
}
template <typename ATP>
inline ATP Abs(ATP a) {
  return a < 0 ? -a : a;
}
struct nod {
  long long l, r;
  bool operator<(const nod &com) const {
    return r == com.r ? r < com.r : l < com.l;
  }
} a[2000007];
int main() {
  long long n;
  io >> n;
  for (register long long i = (1); i <= (n); ++i) {
    long long x, w;
    io >> x >> w;
    a[i] = (nod){x - w, x + w};
  }
  sort(a + 1, a + n + 1);
  long long r = -INT_MAX;
  long long ans = 0;
  for (register long long i = (1); i <= (n); ++i) {
    if (a[i].l < r) continue;
    ++ans;
    r = a[i].r;
  }
  printf("%lld", ans);
  return 0;
}
