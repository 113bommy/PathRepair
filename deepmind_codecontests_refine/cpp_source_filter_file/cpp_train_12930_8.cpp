#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7, M = 998244353;
long long fact[N], obr[N], pref0[N], poww[N];
long long a[N];
long long bin_pow(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a % M;
  if (n % 2 == 0) {
    long long mem = bin_pow(a, n / 2);
    return (mem * mem) % M;
  }
  return (a * bin_pow(a, n - 1)) % M;
}
long long get_obr(long long x) { return bin_pow(x, M - 2); }
void init(long long k) {
  fact[0] = obr[0] = pref0[0] = poww[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % M;
    obr[i] = get_obr(fact[i]);
    pref0[i] = (pref0[i - 1] * (k - 2)) % M;
    poww[i] = (poww[i - 1] * 2) % M;
  }
}
long long cnk(long long n, long long k) {
  return (((fact[n] * obr[k]) % M) * obr[n - k]) % M;
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  init(k);
  long long ca = 0, cb = 0;
  long long ans = 0, mul = 1;
  for (long long i = 0; i < n; i++) {
    long long nxt = (i + 1) % n;
    if (a[i] == a[nxt])
      cb++;
    else
      ca++;
  }
  for (long long i = 0; i < cb; i++) mul = (mul * k) % M;
  for (long long rest = 0; rest < ca; rest++) {
    long long cur = pref0[rest] * cnk(ca, rest);
    long long s = ca - rest;
    long long left = poww[s];
    if (s % 2 == 0) {
      left = (left - cnk(s, s / 2)) % M;
      if (left < 0) left += M;
    }
    left = (left * obr[2]) % M;
    cur = (cur * left) % M;
    ans = (ans + cur) % M;
  }
  ans = (ans * mul) % M;
  cout << ans << endl;
  return 0;
}
