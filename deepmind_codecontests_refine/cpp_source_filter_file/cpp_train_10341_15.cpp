#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const unsigned long long mod = 1e9 + 7;
unsigned long long g[MAXN];
unsigned long long power[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  power[0] = 1;
  for (register int i = 1; i <= n; i++)
    power[i] = (long long)power[i - 1] * 2 % mod;
  g[1] = g[2] = g[3] = 1;
  for (register int i = 4; i <= n - 1; i++) {
    g[i] = g[i - 1];
    if ((i & 1) == 0) {
      int h = i >> 1;
      g[i] = ((3 * (power[h - 1] - 1) % mod + power[h - 1]) % mod * g[i]) % mod;
    }
  }
  unsigned long long ans = 0;
  for (int i = 1; i <= n - 1; i++) (ans += g[i] * 2) %= mod;
  cout << (ans * ans * 2 % mod + 2) % mod << endl;
  return 0;
}
