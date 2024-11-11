#include <bits/stdc++.h>
using namespace std;
int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 200010;
const int inf = ~0u >> 2;
const long long INF = ~0ull >> 2;
long long read() {
  long long x;
  if (scanf("%lld", &x) == -1) exit(0);
  return x;
}
const double pi = acos(-1.0);
double readf() {
  double x;
  if (scanf("%lf", &x) == -1) exit(0);
  return x;
}
const int mod = (999983);
long long mul(long long a, long long b, long long m = mod) { return a * b % m; }
long long qpow(long long a, long long b, long long m = mod) {
  long long ans = 1;
  for (; b; a = mul(a, a, m), b >>= 1)
    if (b & 1) ans = mul(ans, a, m);
  return ans;
}
long long a[N];
void Solve() {
  long long n = read();
  for (long long i = (0), _ = (n); i < _; i++) {
    a[i] = read() == i + 1;
  }
  a[n] = 0;
  long long cnt = 0;
  for (long long i = (0), _ = (n); i < _; i++)
    if (a[i] && !a[i + 1]) cnt++;
  if (*min_element(a, a + n) == 1)
    cout << 0 << "\n";
  else if (cnt == 1)
    cout << 1 << "\n";
  else
    cout << 2 << "\n";
}
signed main() {
  long long T = 1;
  T = read();
  while (T--) Solve();
  return 0;
}
