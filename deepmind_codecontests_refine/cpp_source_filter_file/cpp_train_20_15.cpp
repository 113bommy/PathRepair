#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int oo = 2e9;
const long long OO = 4e18;
const int md = 0x3b800001;
const int MD = 1e9 + 7;
inline long long time() {
  return chrono ::system_clock().now().time_since_epoch().count();
}
mt19937 rnd(time());
mt19937_64 RND(time());
template <typename t>
inline void umin(t &a, t b) {
  a = min(a, b);
}
template <typename t>
inline void umax(t &a, t b) {
  a = max(a, b);
}
const int N = 2e5 + 228;
int n, x[N], v[N], p[N], s[N];
int f0[N];
int gf0(int i) {
  int ans = 0;
  for (i = s[i] + 1; i; i -= i & -i) ans += f0[i];
  return ans;
}
void uf0(int i, int v) {
  for (i = s[i] + 1; i < N; i += i & -i) f0[i] += v;
}
long long f1[N];
int gf1(int i) {
  long long ans = 0;
  for (i = s[i] + 1; i; i -= i & -i) ans += f1[i];
  return ans;
}
void uf1(int i, long long v) {
  for (i = s[i] + 1; i < N; i += i & -i) f1[i] += v;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> v[i], p[i] = i;
  sort(p, p + n, [&](int a, int b) { return x[a] < x[b]; });
  for (int i = 0; i < n; ++i) s[p[i]] = i;
  sort(p, p + n,
       [&](int a, int b) { return v[a] == v[b] ? x[a] < x[b] : v[a] < v[b]; });
  memset(f0, 0, sizeof f0);
  memset(f1, 0, sizeof f1);
  long long ans = 0;
  for (int j = 0; j < n; ++j) {
    int i = p[j];
    ans += 1ll * gf0(i) * x[i] - gf1(i);
    uf0(i, 1);
    uf1(i, x[i]);
  }
  cout << ans << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
