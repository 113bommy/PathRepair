#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
const long long logN = 19;
const long long M = 1000000007;
const long long dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const long long dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
long long Y[N], num, den, inv[N];
long long n, k;
long long power(long long a, long long n, long long m = M) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n = n >> 1;
    ans = ans % M;
    a = a % M;
  }
  return ans;
}
void pre() {
  Y[0] = 0;
  num = 1;
  inv[0] = 1;
  for (long long i = 1; i < k + 2; i++) Y[i] = (Y[i - 1] + power(i, k)) % M;
  for (long long i = 0; i < k + 2; i++) num = (num * (n - i)) % M;
  for (long long i = 1; i < k + 2; i++) inv[i] = power(i, M - 2);
  den = 1;
  for (long long i = 1; i < k + 2; i++) den = (den * inv[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  pre();
  if (n < k + 2) {
    cout << Y[n] << '\n';
    return 0;
  }
  long long ans = 0;
  for (long long i = 0; i < k + 2; i++) {
    long long T1 = (num * power(n - i, M - 2)) % M;
    if ((k + 1 - i) % 2 == 0)
      ans = (ans + (((T1 * Y[i]) % M) * den) % M) % M;
    else
      ans = (ans - (((T1 * Y[i]) % M) * den) % M + M) % M;
    den = ((den * inv[i + 1]) % M * (k + 1 - i)) % M;
  }
  cout << ans << '\n';
  return 0;
}
