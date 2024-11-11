#include <bits/stdc++.h>
using namespace std;
long long fact[1005];
long long expo(long long x, long long y) {
  if (y == 0) return 1;
  long long ans = expo(x, y / 2);
  ans = (ans * ans) % 1000000007;
  if (y % 2) ans = (ans * x) % 1000000007;
  return ans;
}
long long inv(long long x) { return expo(x, 1000000007 - 2); }
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  return ((fact[n] * inv(fact[n - r])) % 1000000007 * inv(fact[r])) %
         1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, i, j;
  fact[0] = 1;
  for (i = 1; i <= 1001; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
  cin >> n >> m >> k;
  n--, m--;
  cout << (nCr(n, 2 * k) * nCr(m, 2 * k)) % 1000000007;
  return 0;
}
