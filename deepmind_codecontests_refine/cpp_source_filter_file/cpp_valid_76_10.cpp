#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200005;
const long long inf = 1 << 30;
long long n, mod;
struct Node {
  long long c[maxn];
  void update(long long x, long long val) {
    for (long long i = x; i <= n; i += i & -i) {
      c[i] += val;
      c[i] -= (c[i] >= mod ? mod : 0);
      c[i] += mod;
      c[i] -= (c[i] >= mod ? mod : 0);
    }
  }
  long long ask(long long x) {
    long long ans = 0;
    for (long long i = x; i; i -= i & -i) {
      ans += c[i];
      ans -= (ans >= mod ? mod : 0);
    }
    return ans;
  }
} T;
long long f[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> mod;
  T.update(n, 1);
  for (long long i = n; i >= 2; i--) {
    long long x = T.ask(i) + f[i];
    x %= mod;
    T.update(1, x);
    T.update(i, -x);
    for (long long l = 2; l <= i; l++) {
      long long r = i / (i / l);
      f[i / l] = (f[i / l] + 1ll * (r - l + 1) * x % mod) % mod;
      l = r;
    }
  }
  cout << T.ask(1) + f[1];
}
