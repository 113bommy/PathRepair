#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000 + 7;
long long addm(long long& a, long long b) {
  return (a += b) < mod ? a : a -= mod;
}
template <class T, class U>
bool smin(T& a, U b) {
  return a > b ? (a = b, 1) : 0;
}
template <class T, class U>
bool smax(T& a, U b) {
  return a < b ? (a = b, 1) : 0;
}
long long n, k, s, t;
long long C[200000], V[200000];
long long gas[200000];
long long time(long long d, long long f) {
  if (f < d) return -1;
  return max((long long)3 * d - f, d);
}
bool doable(long long cap) {
  long long tm = 0;
  long long pos = 0;
  for (long long i = 0; i < k; i++) {
    long long ct = time(gas[i] - pos, cap);
    if (ct == -1) return 0;
    tm += ct;
    pos = gas[i];
  }
  long long ct = time(s - pos, cap);
  if (ct == -1) return 0;
  tm += ct;
  pos = s;
  return tm <= t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s >> t;
  for (long long i = 0; i < n; i++) cin >> C[i] >> V[i];
  for (long long i = 0; i < k; i++) cin >> gas[i];
  sort(gas, gas + k);
  long long l = 0, u = 1000000000;
  while (l != u) {
    long long mid = (l + u) / 2;
    if (doable(mid))
      u = mid;
    else
      l = mid + 1;
  }
  long long bp = INT_MAX;
  for (long long i = 0; i < n; i++)
    if (V[i] >= l) smin(bp, C[i]);
  if (bp == INT_MAX)
    cout << -1 << endl;
  else
    cout << bp << endl;
}
