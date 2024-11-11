#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, inf = 998244353;
long long n, k, i, j;
long long A[N], f[N] = {1}, p[N];
inline long long inv(long long n, long long k = inf - 2, long long p = inf) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
vector<long long> BIT(N);
void upd(long long first, long long val) {
  for (; first <= n; first += (first & -first)) BIT[first] += val;
}
long long q(long long first) {
  long long res = 0;
  for (; first > 0; first -= (first & -first)) res += BIT[first];
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, a, b, ans = 0, cnt = 0, cur;
  cin >> n;
  for (i = 1; i < N; i++) f[i] = f[i - 1] * i % inf;
  for (i = 1; i < n + 1; i++) {
    cin >> A[i];
    if (A[i] != -1) {
      ans += cnt - q(A[i] - 1);
      upd(A[i], 1);
      cnt++;
      p[A[i]] = 1;
    }
  }
  if (cnt == n) return cout << ans % inf, 0;
  ans = ans * f[n - cnt] % inf;
  ans += (n - cnt) * (n - cnt - 1) / 2 % inf * inv(2) % inf * f[n - cnt] % inf;
  BIT.assign(N, 0);
  for (i = 1; i < n + 1; i++)
    if (!p[i]) upd(i, 1);
  long long z = n - cnt;
  for (i = 1; i < n + 1; i++)
    if (A[i] != -1) {
      cur = q(A[i] - 1);
      ans += cur * z % inf * f[n - cnt - 1] % inf;
      cur = n - cnt - cur;
      ans += cur * (n - cnt - z) % inf * f[n - cnt - 1] % inf;
    } else
      z--;
  cout << ans % inf * inv(f[n - cnt]) % inf;
}
