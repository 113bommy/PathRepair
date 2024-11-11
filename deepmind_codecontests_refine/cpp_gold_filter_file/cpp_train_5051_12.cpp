#include <bits/stdc++.h>
const int oo = 1e9 + 7;
using namespace std;
long long power(long long x, int y) {
  if (y == 0) return 1;
  if (y % 2 == 0) return power(x * x % oo, y / 2);
  return x * power(x * x % oo, y / 2) % oo;
}
int k;
bool ok;
long long n, res, tmp = 1, f[1000010], gt[1000010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k + 2; ++i) f[i] = (f[i - 1] + power(i, k)) % oo;
  if (n <= k + 2) {
    cout << f[n];
    return 0;
  }
  gt[0] = 1;
  for (int i = 1; i <= 1000002; ++i) gt[i] = gt[i - 1] * i % oo;
  if (k % 2 == 0) ok = 1;
  k += 2;
  for (int i = 1; i <= k; ++i) tmp = tmp * (n - i) % oo;
  for (int i = 1; i <= k; ++i) {
    long long ts = tmp * power(n - i, oo - 2) % oo;
    long long ms = gt[i - 1] * gt[k - i] % oo;
    long long ps = ts * power(ms, oo - 2) % oo;
    ps = f[i] * ps % oo;
    if (!ok)
      res = (res + ps) % oo;
    else
      res = (res - ps + oo) % oo;
    ok = 1 - ok;
  }
  cout << res;
  return 0;
}
