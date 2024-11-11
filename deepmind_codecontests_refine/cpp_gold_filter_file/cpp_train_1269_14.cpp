#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int mod = 1e9 + 7;
int f[maxn];
int main() {
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < maxn; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF)
    printf("%d\n", ((f[n] + f[m]) % mod * 2 % mod + mod - 2) % mod);
}
