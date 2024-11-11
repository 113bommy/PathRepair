#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
long long f[maxn];
char c[maxn];
int n;
int d[maxn];
int g[2];
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int i(1), endi(n); i <= endi; i++)
    if (c[i] == '0') d[i] = d[i - 1] + 1;
  for (int i(n), endi(1); i >= endi; i--) {
    f[i] = (f[g[d[i] + 1]] + f[g[0]] + (d[i] <= d[n])) % mod;
    g[d[i]] = i;
  }
  if (g[0])
    cout << f[g[0]] * g[0] % mod;
  else
    cout << n;
  return 0;
}
