#include <bits/stdc++.h>
using namespace std;
const int N = 300010, mod = 998244353;
long long a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 2 * n + 1);
  long long s = 0;
  for (int i = 1; i <= n; i++) s = (long long)(s + a[i + n] - a[i]) % mod;
  long long fn = 1, f2n = 1;
  for (int i = 1; i <= n; i++) fn = (long long)fn * i % mod;
  f2n = fn;
  for (int i = n + 1; i <= 2 * n; i++) f2n = (long long)f2n * i % mod;
  long long revn = 1;
  int t = mod - 2;
  while (t) {
    if (t & 1) revn = (long long)revn * fn % mod;
    t >>= 1;
    fn = (long long)fn * fn % mod;
  }
  long long res = (long long)revn * f2n % mod * revn % mod * s % mod;
  cout << res << endl;
  return 0;
}
