#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool prm[10000007];
long long N = 10000000;
void sieve() {
  prm[1] = 1;
  for (long long i = 2; i <= sqrt(N); i++) {
    if (prm[i] == 0) {
      for (long long j = i + i; j <= N; j = j + i) prm[j] = 1;
    }
  }
}
long long bm(long long b, long long p) {
  long long namira;
  if (p == 0) return 1;
  if (p % 2 == 0) {
    namira = bm(b, p / 2);
    return ((namira % 1000000007) * (namira % 1000000007)) % 1000000007;
  } else {
    return ((b % 1000000007) * (bm(b, p - 1) % 1000000007)) % 1000000007;
  }
}
int main() {
  long long i, n, m, c, p, x, a[510], A[510], b[1010], k, j;
  scanf("%I64d%I64d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  scanf("%I64d", &b[0]);
  k = 1;
  for (i = 1; i < m; i++) {
    scanf("%I64d", &x);
    if (x != a[k - 1]) {
      a[i] = x;
      k++;
    }
  }
  c = 0;
  for (i = 1; i < k; i++) {
    for (j = 1; j <= n; j++) A[j] = 1;
    for (j = i - 1; j >= 0; j--) {
      if (b[i] == b[j]) {
        break;
      } else {
        if (A[b[j]] != 0) {
          A[b[j]] = 0;
          c += a[b[j]];
        }
      }
    }
  }
  printf("%I64d\n", c);
  return 0;
}
