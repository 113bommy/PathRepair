#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1050000;
int n;
long long ans, f[N], x[N];
void fwt() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (1 << n); j++)
      if (!(j & (1 << i))) {
        int l = f[j], r = f[j | (1 << i)];
        f[j] = l + r, f[j | (1 << i)] = l - r;
      }
}
int main() {
  scanf("%d", &n);
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  for (int i = 0; i < (1 << n); i++) f[i] = c - '0', c = getchar();
  fwt();
  for (int i = 0; i < (1 << n); i++) f[i] = f[i] * f[i];
  fwt();
  for (int i = 0; i < (1 << n); i++) f[i] = f[i] >> n;
  x[0] = 1;
  for (int i = 1; i < (1 << n); i++) x[i] = x[i >> 1] << (i & 1);
  for (int i = 0; i < (1 << n); i++)
    ans =
        ((long long)ans + (long long)f[i] * x[i ^ ((1 << n) - 1)] % mod) % mod;
  printf("%d\n", (long long)ans * 3 % mod);
  return 0;
}
