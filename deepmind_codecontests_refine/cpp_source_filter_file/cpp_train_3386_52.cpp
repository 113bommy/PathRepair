#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <class T>
void mxi(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void mni(T& a, const T& b) {
  a = min(a, b);
}
long double EPS = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
const long long NAX = 1e6 + 5;
struct Line {
  long long m, b;
  Line() {
    m = 0;
    b = -5e18;
  }
  long long operator()(long long x) { return m * x + b; }
} t[4 * 2000100];
void insert(long long id, long long l, long long r, Line seg) {
  if (l == r) {
    if (seg(l) > t[id](l)) t[id] = seg;
    return;
  }
  if (t[id].m > seg.m) swap(t[id], seg);
  if (t[id](((l + r) >> 1)) < seg(((l + r) >> 1))) {
    swap(t[id], seg);
    insert(id << 1, l, ((l + r) >> 1), seg);
  } else
    insert(id << 1 | 1, ((l + r) >> 1) + 1, r, seg);
}
long long query(long long id, long long l, long long r, long long x) {
  if (l == r) return t[id](x);
  if (x < ((l + r) >> 1))
    return max(t[id](x), query(id << 1, l, ((l + r) >> 1), x));
  else
    return max(t[id](x), query(id << 1 | 1, ((l + r) >> 1) + 1, r, x));
}
long long suf[200200], pfs[200200], a[200200];
void solve() {
  long long n;
  cin >> n;
  long long ans = 0, tot;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ans += (1LL * i * a[i]);
    pfs[i] = a[i] + pfs[i - 1];
    suf[i] = a[i];
  }
  tot = ans;
  for (long long i = n; i > 0; i--) suf[i] += suf[i + 1];
  Line temp;
  for (long long i = 1; i <= n; i++) {
    if (i != 1) {
      long long delta = query(1, -NAX, NAX, a[i]) - a[i] * i - suf[i];
      ans = max(ans, tot + delta);
    }
    temp.m = i;
    temp.b = suf[i];
    insert(1, -NAX, NAX, temp);
    continue;
  }
  for (long long i = 0; i < NAX * 2 + 300; i++) t[i].m = 0, t[i].b = -5e18;
  for (long long i = n; i >= 1; i--) {
    if (i != n) {
      long long delta = query(1, -NAX, NAX, a[i]) - a[i] * i + pfs[i];
      ans = max(ans, tot + delta);
    }
    temp.m = i;
    temp.b = -pfs[i];
    insert(1, -NAX, NAX, temp);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, tab;
  t = 1;
  tab = t;
  while (t--) {
    solve();
  }
  cerr << ((double)clock() / CLOCKS_PER_SEC);
}
