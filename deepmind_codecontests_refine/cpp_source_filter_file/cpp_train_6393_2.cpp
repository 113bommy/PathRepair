#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const long long mod = 1000000007;
long long pow_mod(long long x, long long n) {
  if (n == 0) return 1LL;
  long long ans = pow_mod(x, n / 2);
  ans = ans * ans % mod;
  if (n % 2 == 1) ans = ans * x % mod;
  return ans;
}
long long x, a[maxn];
int n;
int main() {
  cin >> n >> x;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  long long ans = s - a[n - 1];
  int cnt = 0;
  for (long long k = a[n - 1]; k >= 0; k--) {
    while (n >= 0 && a[n - 1] == k) n--, cnt++;
    if (cnt % x) break;
    ans++;
    cnt /= x;
  }
  cout << pow_mod(x, ans) << endl;
  return 0;
}
