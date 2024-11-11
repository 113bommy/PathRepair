#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a > b) {
    a = a + b;
    b = a - b;
    a = a - b;
  }
  if (b % a == 0) return a;
  return gcd(b % a, a);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int prime[1000100], pcnt;
int defac[1000100][2], dcnt;
int era[1000100];
int input[1000100];
void defac_precompute(int maxnum) {
  int i, j;
  for (i = 2; i <= maxnum; i++) era[i] = i;
  pcnt = 0;
  for (i = 2; i <= maxnum; i++) {
    if (era[i] == 0) continue;
    prime[pcnt++] = i;
    j = i;
    while (j <= maxnum) {
      era[j] = 0;
      j += i;
    }
  }
}
void prdfac(int x) {
  int i, bx = x;
  dcnt = 0;
  for (i = 0; i < pcnt; i++) {
    if (bx % prime[i] == 0) {
      defac[dcnt][0] = prime[i];
      defac[dcnt][1] = 0;
      while (bx % prime[i] == 0) {
        bx /= prime[i];
        defac[dcnt][1]++;
      }
      dcnt++;
    }
    if (bx == 1) break;
  }
  if (bx > 1) {
    defac[dcnt][0] = bx;
    defac[dcnt][1] = 1;
    dcnt++;
  }
}
tuple<long long int, long long int, long long int> extended_euclidean(
    long long int a, long long int b) {
  if (b == 0) return make_tuple(a, 1, 0);
  int g, x, y;
  tie(g, x, y) = extended_euclidean(b, a % b);
  return make_tuple(g, y, x - (a / b) * y);
}
long long int f[200200 + 1];
long long int inv[200200 + 1];
int mpow(int n, int p) {
  if (p == 1) return n;
  int ret = mpow(n, p / 2);
  ret = (long long)ret * ret % 998244353;
  if (p % 2) ret = (long long)n * ret % 998244353;
  return ret;
}
void precom() {
  inv[0] = inv[1] = f[0] = f[1] = 1;
  for (int i = 2; i <= 200200; i++) {
    f[i] = (long long)f[i - 1] * i % 998244353;
  }
  for (int i = 2; i <= 200200; i++) {
    inv[i] = (long long)inv[i - 1] * mpow(i, 998244353 - 2) % 998244353;
  }
}
long long int C(int n, int r) {
  long long int ret = f[n] * inv[r] % 998244353 * inv[n - r] % 998244353;
  while (ret < 0) ret += 998244353;
  ret = ret % 998244353;
  return ret;
}
void solve(int tc) {
  long long int n, m, k, i, j, mx = 0, bmx = 0, pw, ans;
  scanf("%lld %lld", &n, &m);
  if (n == 2) {
    printf("%d\n", 0);
    return;
  }
  if (n == 3) {
    ans = m * (m - 1) / 2;
    ans = ans % 998244353;
    printf("%lld\n", ans);
    return;
  }
  precom();
  ans = 1;
  for (i = 0; i < n - 3; i++) ans = (ans * 2) % 998244353;
  ans = (ans * (n - 2)) % 998244353;
  ans = (ans * (C(m, n - 1))) % 998244353;
  printf("%lld\n", ans);
}
int main() {
  int T = 1, tc;
  for (tc = 1; tc <= T; tc++) solve(tc);
}
