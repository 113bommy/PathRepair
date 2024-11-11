#include <bits/stdc++.h>
using namespace std;
namespace fast_read {
char gc(void) {
  const int S = 1 << 17;
  static char buf[S], *s = buf, *t = buf;
  if (s == t) t = buf + fread(s = buf, 1, S, stdin);
  if (s == t) return EOF;
  return *s++;
}
long long RD(void) {
  long long a = 0, b = 1, c = gc();
  for (; !isdigit(c); c = gc()) b ^= (c == '-');
  for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
  return b ? a : -a;
}
};  // namespace fast_read
using fast_read::RD;
const long long LINF = 1e18 + 5, INF = 0x3f3f3f3f, hxe = 1319, mod = 998244353;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long Qpow(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) {
      s = (s * a) % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return s;
}
inline long long Qinv(long long a) { return Qpow(a, mod - 2); }
const int maxn = 2e5 + 5;
int n, a[maxn];
int tree[maxn];
void update(int x, int v) {
  while (x <= n) {
    tree[x] += v;
    x += (x & (-x));
  }
}
int query(int x) {
  int res = 0;
  while (x > 0) {
    res += tree[x];
    x -= (x & (-x));
  }
  return res;
}
void solve() {
  cin >> n;
  memset(tree, 0, sizeof(tree));
  vector<int> qc;
  for (int i = 1; i <= n; i++) cin >> a[i], qc.push_back(a[i]);
  sort(begin(qc), end(qc));
  qc.erase(unique(begin(qc), end(qc)), qc.end());
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(begin(qc), end(qc), a[i]) - qc.begin() + 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int L = query(a[i] - 1);
    int R = query(n) - query(a[i]);
    if (L <= R)
      ans += L;
    else
      ans += R;
    update(a[i], 1);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
