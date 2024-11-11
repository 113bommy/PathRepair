#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)998244353;
const int div2 = (int)499122177;
const int MAXN = (int)1e6 + 7;
const int infint = (int)1e9;
long long a[MAXN], n, m, A, ans = 1;
long long pwr(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long c = pwr(a, b / 2);
  c = (c * c) % MOD;
  if (b % 2) c = (c * a) % MOD;
  return c;
}
long long get(long long c) {
  long long q = pwr(A, c), p = q;
  q = q * ((q - 1 + MOD) % MOD) % MOD * div2 % MOD;
  q = (q + p) % MOD;
  return q;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> A;
  for (int i = 0; i < m; i++) cin >> a[i];
  ans *= get(a[0]), ans %= MOD;
  for (int i = 1; i < m; i++) ans = ans * get(a[i] - a[i - 1]);
  long long c = n / 2 - a[m - 1];
  c *= 2;
  if (n % 2) c++;
  ans = (ans * pwr(A, c)) % MOD;
  cout << ans;
}
