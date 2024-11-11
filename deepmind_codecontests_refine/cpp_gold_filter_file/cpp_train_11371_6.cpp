#include <bits/stdc++.h>
using namespace std;
const long long base = 233;
const long long ff = 1e6 + 5;
const long long mod = 998244353;
const long long inf = 1e9 + 1;
long long tr[ff], sr[ff];
void upd(long long now) { tr[now] = tr[(now << 1)] + tr[(now << 1 | 1)]; }
void build(long long now, long long l, long long r) {
  if (l == r) {
    tr[now] = sr[l];
    return;
  }
  build((now << 1), l, ((l + r) >> 1));
  build((now << 1 | 1), r, ((l + r) >> 1));
  upd(now);
}
void modify(long long now, long long l, long long r, long long lc, long long rc,
            long long va) {
  if (lc > r || rc < l) return;
  if (lc <= l && r <= rc) {
    tr[now] += va;
    return;
  }
  modify((now << 1), l, ((l + r) >> 1), lc, rc, va);
  modify((now << 1 | 1), ((l + r) >> 1) + 1, r, lc, rc, va);
  upd(now);
}
long long query(long long now, long long l, long long r, long long lc,
                long long rc) {
  if (lc > r || rc < l) return 0;
  if (lc <= l && r <= rc) return tr[now];
  return query((now << 1), l, ((l + r) >> 1), lc, rc) +
         query((now << 1 | 1), ((l + r) >> 1) + 1, r, lc, rc);
}
long long fir[ff], nex[ff], to[ff], tot;
void add(long long x, long long y) {
  nex[++tot] = fir[x];
  fir[x] = tot;
  to[tot] = y;
}
long long qsm(long long a, long long b, long long c = 1) {
  for (long long i = 1; b; b >>= 1, a = a * a % mod)
    if (b & 1) c = c * a % mod;
  return c;
}
long long getinv(long long x) { return qsm(x, mod - 2); }
long long n, m, k, b[ff], c[ff];
string s[5];
void init() {
  cin >> n >> m >> k;
  s[0] = "U";
  s[1] = "R";
  s[2] = "D";
  s[3] = "L";
  s[4] = "DUL";
  long long top = 0;
  for (long long i = 1; i <= n - 1; ++i) {
    if (m - 1 > 0) b[++top] = 1, c[top] = m - 1;
    if (m - 1 > 0) b[++top] = 4, c[top] = m - 1;
    b[++top] = 2;
    c[top] = 1;
  }
  if (m - 1 > 0) b[++top] = 1, c[top] = m - 1;
  if (m - 1 > 0) b[++top] = 3, c[top] = m - 1;
  if (n - 1 > 0) b[++top] = 0, c[top] = n - 1;
  long long sa = 0;
  for (long long i = 1; i <= top; ++i) {
    long long cru = 1;
    if (b[i] == 4) cru = 3;
    if (sa + c[i] * cru >= k) {
      long long ts = k - sa;
      long long nd = ts / 3;
      long long md = ts % 3;
      long long co = i;
      if (b[i] == 4 && nd && md) co++;
      if (!ts || (!nd && !md)) co--;
      cout << "YES\n" << co << "\n";
      for (long long j = 1; j <= i - 1; ++j)
        cout << c[j] << " " << s[b[j]] << endl;
      if (b[i] == 4) {
        if (nd) cout << nd << " " << s[4] << endl;
        if (md == 1) cout << "1 D\n";
        if (md == 2) cout << "1 DU\n";
        return;
      }
      if (ts) cout << ts << " " << s[b[i]] << endl;
      return;
    }
    sa += c[i] * cru;
  }
  puts("NO");
}
signed main() {
  long long T = 1;
  while (T--) init();
}
