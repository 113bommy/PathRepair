#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) sum = sum * 10 + (ch ^ 48), ch = getchar();
  return sum * ff;
}
const long long mod = 1e9 + 7;
const long long mo = 998244353;
const long long N = 1e5 + 5;
long long n, m, s, a[N], b[N * 10], bl[N], res[N], l, r, siz;
struct Node {
  long long l, r, id;
  inline bool friend operator<(const Node& s, const Node& t) {
    return (bl[s.l] ^ bl[t.l]) ? bl[s.l] < bl[t.l]
           : (!(bl[s.l] & 1))  ? s.r < t.r
                               : s.r > t.r;
  }
};
Node c[N];
signed main() {
  n = read(), m = read(), s = read();
  siz = sqrt(n);
  for (long long i = (1); i <= (n); i++) a[i] = read(), a[i] ^= a[i - 1];
  for (long long i = (1); i <= (n); i++) bl[i] = (i - 1) / siz + 1;
  for (long long i = (1); i <= (m); i++) c[i] = (Node){read() - 1, read(), i};
  sort(c + 1, c + m + 1);
  l = 1, r = 0;
  long long ans = 0;
  for (long long i = (1); i <= (m); i++) {
    while (l > c[i].l) ans += b[a[--l] ^ s], ++b[a[l]];
    while (l < c[i].l) --b[a[l]], ans -= b[s ^ a[l++]];
    while (r < c[i].r) ans += b[a[++r] ^ s], ++b[a[r]];
    while (r > c[i].r) --b[a[r]], ans -= b[s ^ a[r--]];
    res[c[i].id] = ans;
  }
  for (long long i = (1); i <= (m); i++) printf("%lld\n", res[i]);
  return 0;
}
