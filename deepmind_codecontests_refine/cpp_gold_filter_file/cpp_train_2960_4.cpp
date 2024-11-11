#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
long long mod(long long n) { return (n % MOD + MOD) % MOD; }
const long long N = 1e6 + 7;
long long n;
long long a[N];
void add(long long *f, long long i) {
  for (; i < N; i |= (i + 1)) ++f[i];
}
void del(long long *f, long long i) {
  for (; i < N; i |= (i + 1)) --f[i];
}
long long get(long long *f, long long i) {
  long long ans = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ans += f[i];
  return ans;
}
void add_rev(long long *f, long long i) {
  i = N - i - 1;
  for (; i < N; i |= (i + 1)) ++f[i];
}
long long get_rev(long long *f, long long i) {
  i = N - i - 1;
  long long ans = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ans += f[i];
  return ans;
}
long long fc[N];
long long f[N];
long long get() {
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    ans = mod(ans + get_rev(f, a[i] + 1));
    add_rev(f, a[i]);
  }
  return ans;
}
long long sum(long long n) { return mod(n * (n + 1) / 2); }
long long flr[N], fr[N];
long long cur = 0, l = 0;
void upd(long long x) {
  long long lb = get_rev(flr, x + 1);
  long long rm = get(fr, x - 1);
  cur = mod(cur - lb);
  l = mod(l + lb);
  cur = mod(cur + rm);
  add_rev(flr, x);
  del(fr, x);
}
long long fp(long long a, long long p) {
  long long ans = 1, cur = a;
  for (long long i = 0; (1ll << i) <= p; ++i) {
    if ((p >> i) & 1) ans = mod(ans * cur);
    cur = mod(cur * cur);
  }
  return ans;
}
long long DV = fp(2, MOD - 2);
long long div2(long long n) { return mod(n * DV); }
long long getall(long long n) {
  return mod(mod(n * (n - 1) / 2) * div2(fc[n]));
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fc[0] = 1;
  for (long long i = 1; i < N; ++i) fc[i] = mod(fc[i - 1] * i);
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; ++i) {
    add(fr, i);
  }
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    long long in_r = n - i;
    long long can = get(fr, a[i] - 1);
    long long cnt = mod(can * fc[in_r - 1]);
    ans = mod(ans + (cur + l) * cnt);
    ans = mod(ans + fc[in_r - 1] * sum(can - 1));
    ans = mod(ans + can * getall(in_r - 1));
    upd(a[i]);
  }
  ans = mod(ans + get());
  cout << ans << '\n';
}
