#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const double eps = 1e-12;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
const long long ALL = 110, LEN = 1010, U = 4, N = 12;
const long long P = 1000000009;
long long Len, n;
namespace AC {
long long ch[ALL][U], fail[ALL], ref[ALL], lst[ALL], dep[ALL], las = 0, rt = 0,
                                                               ind = 0;
inline void Insert(long long x) {
  if (!ch[las][x]) {
    ch[las][x] = ++ind;
    dep[ind] = dep[las] + 1;
  }
  las = ch[las][x];
}
long long que[N * N], h = 1, t = 0;
inline void Build() {
  h = 1;
  t = 0;
  for (long long i = 0; i < U; i++)
    if (ch[rt][i]) {
      long long v = ch[rt][i];
      que[++t] = v;
      fail[v] = rt;
    }
  while (h <= t) {
    long long u = que[h++];
    for (long long i = 0; i < U; i++) {
      long long &v = ch[u][i], w = ch[fail[u]][i];
      if (v)
        fail[v] = w, que[++t] = v;
      else
        v = w;
      lst[v] = ref[fail[v]] ? fail[v] : lst[fail[v]];
    }
  }
}
}  // namespace AC
char s[12][20];
long long len[12];
struct NODE {
  long long u, st, d;
};
long long f[ALL][LEN][12];
bool inq[ALL][LEN][12];
NODE que[ALL * LEN * 10];
long long h = 1, t = 0;
long long ans = 0;
inline long long trans(char ch) {
  if (ch == 'A') return 0;
  if (ch == 'C') return 1;
  if (ch == 'G') return 2;
  if (ch == 'T') return 3;
  throw;
}
signed main() {
  read(Len);
  read(n);
  for (long long i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    len[i] = strlen(s[i] + 1);
    AC::las = AC::rt;
    for (long long j = 1; j <= len[i]; j++) AC::Insert(trans(s[i][j]));
    AC::ref[AC::las] = i;
  }
  AC::Build();
  f[AC::rt][0][0] = 1;
  que[++t] = (NODE){AC::rt, 0};
  inq[AC::rt][0][0] = 1;
  while (h <= t) {
    NODE tmp = que[h++];
    long long u = tmp.u, st = tmp.st, d = tmp.d;
    long long val = f[u][st][d];
    if (st == Len) {
      if (!d) (ans += f[u][st][d]) %= P;
      continue;
    }
    long long tst = st + 1;
    for (long long i = 0; i < U; i++) {
      long long v = AC::ch[u][i], td = d + 1;
      if (AC::dep[v] < td) continue;
      if (AC::ref[v])
        td = 0;
      else if (AC::dep[AC::lst[v]] >= td)
        td = 0;
      (f[v][tst][td] += val) %= P;
      if (!inq[v][tst][td]) que[++t] = (NODE){v, tst, td}, inq[v][tst][td] = 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
