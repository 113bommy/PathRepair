#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const double eps = 1e-15;
const double pi = acos(-1);
const int INF = 0x3f3f3f;
long long read() {
  long long c = getchar(), Nig = 1, x = 0;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') Nig = -1, c = getchar();
  while (isdigit(c)) x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
  return Nig * x;
}
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans % a % m;
    a = a * a % m, b >>= 1;
  }
  return ans;
}
long long Qpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a;
    a *= a, b >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long mul(long long a, long long b, long long m) {
  long long res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
int lowbit(int x) { return x & (-x); }
double qf[maxn], jl[maxn];
int n;
double m;
bool ok(double x) {
  double z = x + m;
  for (int i = 1; i < n; i++) {
    z -= (z / qf[i]);
    z -= (z / jl[i + 1]);
    if (z <= m) return false;
  }
  z -= (z / qf[n]);
  z -= (z / jl[1]);
  return z >= m;
}
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  ;
  cin >> n;
  cin >> m;
  for (int i = 1; i <= n; i++) {
    cin >> qf[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> jl[i];
  }
  double l = 0.0, r = 10000000.0, ans = -1;
  while (r - l >= 1e-6) {
    double mid = (l + r) * 0.5;
    if (ok(mid)) {
      ans = mid;
      r = mid;
    } else
      l = mid;
  }
  if (ans != -1)
    printf("%.10f\n", ans);
  else
    cout << ans << endl;
}
