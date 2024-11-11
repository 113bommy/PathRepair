#include <bits/stdc++.h>
template <typename T>
bool ckmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool ckmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
using namespace std;
const long long inf = (1ll << 60);
const double Pi = acos(-1);
const long long mod = 950009857;
const double eps = 1e-7;
inline long long fpow(long long a, long long b = mod - 2, long long p = mod) {
  a %= p;
  long long res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % p;
    a = 1ll * a * a % p;
    b >>= 1;
  }
  return res;
}
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
long long n, m;
long long a[4444];
long long ans[66666], pos[4444];
const long long B = 1 << 8;
long long tot_b;
pair<long long, long long> id[8888888];
long long mer(long long x, long long y) {
  if (!x || !y) return x | y;
  id[tot_b] = make_pair(x, y);
  return ++tot_b;
}
struct node {
  vector<long long> val;
  vector<vector<long long>> id;
  inline void init(long long x) {
    val.resize(x), id.resize(x);
    for (long long i = (0), iE = (x - 1); i <= iE; i++) id[i].resize(x - i);
  }
  node(long long opt = -1) {
    if (~opt) init(1), val[0] = pos[opt], id[0][0] = pos[opt] + 1;
  }
  inline long long query(long long l, long long r) const {
    if (r < val.front() || l > val.back()) return 0;
    long long L = lower_bound(val.begin(), val.end(), l) - val.begin(),
              R = upper_bound(val.begin(), val.end(), r) - val.begin() - 1;
    return L > R ? 0 : id[L][R - L];
  }
  inline node modify(const node &a, const node &b) {
    init(a.val.size() + b.val.size());
    merge(a.val.begin(), a.val.end(), b.val.begin(), b.val.end(), val.begin());
    for (long long i = (0), iE = ((long long)val.size() - 1); i <= iE; i++)
      for (long long j = (i), jE = ((long long)val.size() - 1); j <= jE; j++)
        id[i][j - i] = mer(a.query(val[i], val[j]), b.query(val[i], val[j]));
    return *this;
  }
} b[2222];
node solve(long long l, long long r) {
  if (l == r) return node(l);
  long long mid = (l + r) >> 1;
  static node tmp;
  return tmp.modify(solve(l, mid), solve(mid + 1, r));
}
signed main() {
  n = read() - 1, m = read(), tot_b = n + 1;
  for (long long i = (0), iE = (n); i <= iE; i++)
    a[i] = read() - 1, pos[a[i]] = i;
  for (long long i = (0), iE = (n / B); i <= iE; i++)
    b[i] = solve(i * B, min(n, (i + 1) * B - 1));
  long long l, r;
  for (long long t = (0), tE = (m - 1); t <= tE; t++) {
    l = read() - 1, r = read() - 1;
    for (long long j = (0), jE = (n / B); j <= jE; j++)
      ans[t] = mer(ans[t], b[j].query(l, r));
  }
  writeln(tot_b);
  for (long long i = (n + 1), iE = (tot_b - 1); i <= iE; i++)
    printf("%lld %lld\n", id[i].first, id[i].second);
  for (long long i = (0), iE = (m - 1); i <= iE; i++) writesp(ans[i]);
}
