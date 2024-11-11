#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <class S, class T>
inline S smax(S &l, T r) {
  return l = max(l, (S)r);
}
template <class S, class T>
inline S smin(S &l, T r) {
  return l = min(l, (S)r);
}
const long long MAXN = 2e5 + 10;
const long long L = 21;
long long n, a[MAXN], p[MAXN], basis[MAXN];
void transform(long long x) {
  for (long long i = L - 1; ~i; --i)
    if (basis[i] != -1 && (x & (1 << i))) x ^= basis[i];
  if (x == 0) return;
  for (long long i = L - 1; ~i; --i)
    if (x & (1 << i)) {
      basis[i] = x;
      return;
    }
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  memset(basis, -1, sizeof(basis));
  for (long long i = 0; i < n; ++i) {
    p[i + 1] = p[i] ^ a[i];
    transform(p[i + 1]);
  }
  if (p[n] == 0) {
    cout << -1 << '\n';
    return 0;
  }
  long long cnt = 0;
  for (long long i = 0; i < L; ++i)
    if (basis[i] != -1) cnt++;
  cout << cnt << '\n';
  return 0;
}
