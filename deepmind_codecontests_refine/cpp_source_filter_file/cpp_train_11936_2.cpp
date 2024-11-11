#include <bits/stdc++.h>
using namespace std;
long long modexp(long long op, long long exp, long long mod) {
  long long ans = 1;
  op %= mod;
  while (exp > 0) {
    if (exp & 1) ans = (ans * op) % mod;
    exp = exp >> 1;
    op = (op * op) % mod;
  }
  return ans;
}
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, mexp;
  cin >> n >> m;
  vector<long long> p(n + 2), a(n + 2), b(n + 2);
  p[n] = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  mexp = modexp(m, mod - 2, mod);
  for (i = n - 1; i >= 0; i--) {
    if (a[i] == 0 and b[i] == 0) {
      p[i] = ((m - 1) % mod * modexp(2 * m, mod - 2, mod) * mexp) % mod;
      p[i] += (p[i + 1] * mexp) % mod;
      p[i] %= mod;
    } else if (a[i] == 0) {
      p[i] = ((m - b[i]) % mod * mexp) % mod;
      p[i] += (p[i + 1] * mexp) % mod;
      p[i] %= mod;
    } else if (b[i] == 0) {
      p[i] = ((a[i] - 1) % mod * mexp) % mod;
      p[i] += (p[i + 1] * mexp) % mod;
      p[i] %= mod;
    } else if (a[i] > b[i])
      p[i] = 1;
    else if (a[i] < b[i])
      p[i] = 0;
    else
      p[i] = p[i + 1];
  }
  cout << p[0] << "\n";
  return 0;
}
