#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500002;
const long long mod = 1000000000;
const long double eps = 1e-9;
const long long inf = ((1ll << 31ll) - 1ll);
const long long INF = 2000000000000000000ll;
const long double pi = acos(-1);
long long qpow(long long b, long long e) {
  if (!e) return 1;
  if (e & 1) return qpow(b, e - 1) * b;
  long long pwur = qpow(b, e >> 1);
  return pwur * pwur;
}
long long modinv(long long x) { return qpow(x, mod - 2); }
long long n, a[maxn], lst, psum[maxn], ssum[maxn], cnt;
bool pre_try_(long long id) {
  for (long long i = 1; i <= 100; i++) {
    long long x = id + rand() % (n - id + 1);
    if (psum[x] <= psum[x - id]) return false;
  }
  return true;
}
bool try_(long long id) {
  long long sw = 0;
  for (long long i = id; i <= n; i++) {
    if (psum[i] <= psum[i - id]) return false;
    cnt++;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(0);
  srand(time(NULL));
  cin >> n;
  for (long long i = 1; i <= (n + 1) / 2; i++) {
    cin >> a[i];
  }
  cin >> lst;
  for (long long i = (n + 1) / 2 + 1; i <= n; i++) {
    a[i] = lst;
  }
  for (long long i = 1; i <= n; i++) psum[i] = psum[i - 1] + a[i];
  for (long long i = n; i >= 1; i--) ssum[i] = ssum[i + 1] + a[i];
  if (lst >= 0) {
    if (try_(n))
      cout << n << '\n';
    else
      cout << -1 << '\n';
    return 0;
  }
  if (psum[n] > 0) {
    if (try_(n))
      cout << n << '\n';
    else
      cout << -1 << '\n';
    return 0;
  }
  cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if ((psum[i] > 0 && ssum[n - i + 1] > 0) && (i >= (n + 1) / 2)) {
      if (pre_try_(i)) {
        if (try_(i)) {
          cout << i << '\n';
          return 0;
        }
      }
      if (cnt >= 1000000000) break;
    }
  }
  cout << -1 << '\n';
  return 0;
}
