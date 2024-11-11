#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 55;
const int INF = 0x3f3f3f3f;
const int NINF = 0x80808080;
const long long NLINF = 0x8080808080808080;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long mo = 1e9 + 7;
inline long long fpow(long long a, long long b) {
  long long s = 1;
  a %= mo;
  while (b) {
    if (b & 1) s = s * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return s;
}
namespace Fast_IO {
const int MAXL((1 << 18) + 1);
int iof, iotp;
char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],
    *iooS = ioof, *iooT = ioof + MAXL - 1, ioc, iost[55];
inline char Getchar() {
  if (ioiS == ioiT) {
    ioiS = ioif;
    ioiT = ioiS + fread(ioif, 1, MAXL, stdin);
    return (ioiS == ioiT ? EOF : *ioiS++);
  } else
    return (*ioiS++);
}
inline int read() {
  int x = 0;
  for (iof = 1, ioc = Getchar(); (ioc < '0' || ioc > '9') && ioc != EOF;)
    iof = ioc == '-' ? -1 : 1, ioc = Getchar();
  if (ioc == EOF) exit(0);
  for (x = 0; ioc <= '9' && ioc >= '0'; ioc = Getchar())
    x = (x << 3) + (x << 1) + (ioc ^ 48);
  return x * iof;
}
inline long long read_ll() {
  long long x = 0;
  for (iof = 1, ioc = Getchar(); (ioc < '0' || ioc > '9') && ioc != EOF;)
    iof = ioc == '-' ? -1 : 1, ioc = Getchar();
  if (ioc == EOF) exit(0);
  for (x = 0; ioc <= '9' && ioc >= '0'; ioc = Getchar())
    x = (x << 3) + (x << 1) + (ioc ^ 48);
  return x * iof;
}
}  // namespace Fast_IO
using namespace Fast_IO;
struct Query {
  int l, r, id;
} q[MAXN];
int n, m, k;
int block[MAXN], blocks;
long long tmpans;
long long cnt[MAXN];
long long a[MAXN], ans[MAXN];
inline bool cmp(Query a, Query b) {
  return (block[a.l] ^ block[b.l]) ? (block[a.l] < block[b.l])
                                   : ((block[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
inline void Add(int x) {
  tmpans += cnt[a[x] ^ k];
  cnt[a[x]]++;
}
inline void Dec(int x) {
  cnt[a[x]]--;
  tmpans -= cnt[a[x] ^ k];
}
int main() {
  n = read(), m = read(), k = read();
  blocks = sqrt(n);
  for (register int i = 1; i <= n; ++i) {
    long long x = read_ll();
    a[i] = a[i - 1] ^ x;
    block[i] = (i - 1) / blocks;
  }
  for (register int i = 1; i <= m; ++i)
    q[i].l = read(), q[i].r = read(), q[i].id = i;
  sort(q + 1, q + 1 + m, cmp);
  int l = 0, r = -1;
  for (register int i = 1; i <= m; ++i) {
    while (l < q[i].l - 1) Dec(l++);
    while (l > q[i].l - 1) Add(--l);
    while (r < q[i].r) Add(++r);
    while (r > q[i].r) Dec(r--);
    ans[q[i].id] = tmpans;
  }
  for (register int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}
