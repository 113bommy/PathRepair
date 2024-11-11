#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 7;
long long n, mod;
long long f[N], sum[N], tim[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> mod;
  f[1] = 1;
  sum[1] = 1;
  for (register int i = 2; i <= n; ++i) {
    tim[i] += (tim[i - 1] + 1) % mod;
    f[i] = (f[i] + sum[i - 1] + tim[i]) % mod;
    for (register int j = i + i; j <= n; j += i) {
      tim[j] = (tim[j] + f[i]) % mod;
      tim[j] = (tim[j] - f[i - 1] + mod) % mod;
    }
    sum[i] = (sum[i - 1] + f[i]) % mod;
  }
  cout << f[n] % mod;
  return 0;
}
