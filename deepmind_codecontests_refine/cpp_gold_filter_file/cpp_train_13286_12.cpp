#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1, MAX = 10;
const long long MOD = 1e9 + 7, mod = 1e6 + 3;
long long f[6] = {1, 1, 2, 6, 24, 120};
long long nCr(long long n, long long r) {
  long long ans = 1;
  long long diff = n - r;
  for (long long i = n; i > diff; i--) ans = ans * i;
  ans = ans / f[r];
  return ans;
}
long long dear(long long n) {
  long long ans = f[n], flag = -1;
  for (long long i = 1; i <= n; i++) {
    long long curr = flag * f[i];
    ans = ans + f[n] / curr;
    flag = flag * -1;
  }
  return ans;
}
void solve() {
  long long n, m, j, i, k, r, l, x, y;
  cin >> n >> k;
  long long ans = 0, fact = 1;
  for (long long i = 0; i <= k; i++) {
    ans += (nCr(n, i) * dear(i));
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
