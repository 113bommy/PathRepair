#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int f[N], sum[N];
int n, mod;
int main() {
  scanf("%d%d", &n, &mod);
  f[n] = sum[n] = 1;
  for (int i = n - 1; i; --i) {
    f[i] = (f[i] + sum[i + 1]) % mod;
    for (int j = 2; i * j <= n; ++j) {
      int l = i * j, r = min(n, j * (i + 1) - 1);
      f[i] = (f[i] + sum[l] - sum[r + 1]) % mod;
    }
    sum[i] = (sum[i + 1] + f[i]) % mod;
  }
  cout << f[1] << endl;
  return 0;
}
