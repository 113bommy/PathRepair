#include <bits/stdc++.h>
const int N = 2010;
const long long mod = 1e9 + 7;
using namespace std;
long long a[N], b[N];
long long c[N];
void multi(long long a[N], long long b[N], int n) {
  for (int i = 1; i <= n; i++) c[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int k = 1; k <= n; k++)
      c[i] += 1ll * a[i - k + 1] * b[k], c[i] > mod ? c[i] %= mod : 0;
  for (int i = 1; i <= n; i++) a[i] = c[i] % mod;
}
long long ret[N];
void power(long long a[N], int n, int k) {
  for (int i = 1; i <= n; i++) ret[i] = 0;
  ret[1] = 1;
  while (k) {
    if (k & 1) multi(ret, a, n);
    multi(a, a, n);
    k >>= 1;
  }
}
int A[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= n; i++) a[i] = 1;
  power(a, n, k);
  for (int i = 1; i <= n; i++) {
    long long r = 0;
    for (int j = 1; j <= i; j++) r += 1ll * ret[i - j + 1] * A[j], r %= mod;
    cout << r % mod << " ";
  }
  cout << endl;
  return 0;
}
