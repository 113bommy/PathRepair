#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, mod = 998244353;
int n, ru[N], jc[N], ans = 1;
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    ru[x]++, ru[y]++;
  }
  jc[1] = 1;
  for (int i = 2; i <= n; ++i) jc[i] = 1LL * jc[i - 1] * i % mod;
  for (int i = 1; i <= n; ++i) ans = 1LL * ans * (jc[ru[i]]) % mod;
  cout << 1LL * n * ans % mod << "\n";
  return 0;
}
