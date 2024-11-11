#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5, mod = 998244353;
vector<int> num;
long long A[N];
int a[N];
long long sumup = 0, sumdown = 0;
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (a * c) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return c;
}
long long inv(long long x) { return qpow(x, mod - 2); }
int main() {
  int n;
  cin >> n;
  n <<= 1;
  A[0] = 1;
  for (int i = 1; i <= n; i++) A[i] = (A[i - 1] * i) % mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; i++) ans -= a[i];
  for (int i = n / 2 + 1; i <= n; i++) ans += a[i];
  ans = (ans % mod * A[n] % mod * inv(A[n / 2]) % mod * inv(A[n / 2])) % mod;
  cout << ans << endl;
}
