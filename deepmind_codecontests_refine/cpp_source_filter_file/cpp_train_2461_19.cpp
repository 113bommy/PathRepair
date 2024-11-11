#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 1010;
char x[N];
long long comb[N][N], pw[92][N], ps[N], ret;
int d[N];
int f[N], l;
long long solve(int m, int *d) {
  long long ret = 0;
  for (int i = 0; i < 10; i++) {
    int dl = 0;
    for (int j = i + 1; j < 10; j++) dl += d[j];
    for (int k = 0; k < m + 1; k++) {
      ret = (ret + comb[m][k] * ps[k + d[i]] % mod * i % mod * pw[10][dl] %
                       mod * pw[90 - i * 9][m - k]) %
            mod;
    }
  }
  return ret;
}
int main() {
  scanf("%s", x);
  for (int j = 0; j < 91; j++) {
    pw[j][0] = 1;
    for (int i = 1; i < 1000; i++) pw[j][i] = pw[j][i - 1] * j % mod;
  }
  for (int i = 1; i < 1000; i++) ps[i] = (ps[i - 1] + pw[10][i - 1]) % mod;
  for (int i = 0; i < 1001; i++) {
    comb[i][0] = 1;
    for (int j = 1; j < i + 1; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
  }
  l = strlen(x);
  for (int i = 0; i < l; i++) f[i] = x[i] - '0';
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < f[i]; j++) {
      d[j]++;
      ret += solve(l - i - 1, d);
      d[j]--;
    }
    d[f[i]]++;
  }
  sort(f, f + l);
  long long w = 0;
  for (int i = 0; i < l; i++) w = w * 10 + f[i];
  printf("%lld\n", (ret + w) % mod);
}
