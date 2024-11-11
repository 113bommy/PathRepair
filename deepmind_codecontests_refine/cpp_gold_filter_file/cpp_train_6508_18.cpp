#include <bits/stdc++.h>
using namespace std;
long long n, b, x, k, a[105], input[50005], mod = 1000000007, ass[105];
long long go(long long base, long long po) {
  if (po == 1) return base % x;
  if (po == 0) return 1;
  if (po % 2 == 0) {
    long long p = go(base, po / 2) % x;
    return (p * p) % x;
  } else {
    long long p = go(base, (po - 1) / 2);
    p %= x;
    p *= p;
    p %= x;
    return (p * base) % x;
  }
}
void solve(long long b) {
  if (b == 1) return;
  if (b % 2 == 0) {
    solve(b / 2);
    long long cur[105];
    memset(cur, 0, sizeof cur);
    long long y = go(10, b / 2);
    for (long long i = 0; i <= x; i++) {
      long long ans = (i * y) % x;
      for (long long j = 0; j <= x; j++) {
        cur[(ans + j) % x] += (a[i] * a[j]) % mod;
        cur[(ans + j) % x] %= mod;
      }
    }
    for (long long i = 0; i <= x; i++) a[i] = cur[i];
  } else {
    solve((b - 1) / 2);
    long long cur[105];
    memset(cur, 0, sizeof cur);
    long long y = go(10, (b - 1) / 2);
    for (long long i = 0; i <= x; i++) {
      long long ans = (i * y) % x;
      for (long long j = 0; j <= x; j++) {
        cur[(ans + j) % x] += (a[i] * a[j]) % mod;
        cur[(ans + j) % x] %= mod;
      }
    }
    for (long long i = 0; i <= x; i++) a[i] = cur[i];
    memset(cur, 0, sizeof cur);
    y = go(10, b - 1);
    for (long long i = 0; i <= x; i++) {
      long long ans = (i * y) % x;
      for (long long j = 0; j <= x; j++) {
        cur[(ans + j) % x] += (ass[i] * a[j]) % mod;
        cur[(ans + j) % x] %= mod;
      }
    }
    for (long long i = 0; i <= x; i++) a[i] = cur[i];
  }
}
int main() {
  cin >> n >> b >> k >> x;
  memset(a, 0, sizeof a);
  for (long long i = 1; i <= n; i++) {
    cin >> input[i];
    a[input[i] % x]++;
    ass[input[i] % x]++;
  }
  solve(b);
  cout << a[k];
  return 0;
}
