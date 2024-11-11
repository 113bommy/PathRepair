#include <bits/stdc++.h>
using namespace std;
inline long long max(long long a, long long b) { return ((a > b) ? a : b); }
inline long long min(long long a, long long b) { return ((a > b) ? b : a); }
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long a = power(x, y / 2);
  if (y % 2 == 0)
    return a * a;
  else
    return x * a * a;
}
long long powermod(long long x, long long ex, long long md) {
  long long ans = 1ll;
  while (ex > 0) {
    if (ex & 1ll) ans = (ans * x) % md;
    ex >>= 1ll;
    x = (x * x) % md;
  }
  return ans;
}
const long long inf = 1e18 + 9;
const long long mod = 1e9 + 7;
const long double PI = acos(-1);
const long double eps = 1e-9;
const long long N = 1e6 + 1;
long long n;
void solve() {
  cin >> n;
  if (n & 1)
    cout << "black\n";
  else
    cout << "white\n1 2\n";
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  cout << fixed << setprecision(20);
  long long NTC = 1;
  long long PTC = 0;
  while (PTC++ < NTC) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
