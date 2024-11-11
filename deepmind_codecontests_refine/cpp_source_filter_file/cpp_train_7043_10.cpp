#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = 1000000007) {
  return ((a % p) * (b % p)) % p;
}
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = 1000000007) {
  return fpow(a, p - 2, p);
}
long long pre[300003];
long long a[100003];
int main() {
  long long n, l;
  cin >> n >> l;
  for (long long i = 1; i <= n - 1; i++) {
    cin >> a[i];
    if (i <= l) pre[i] = a[i];
  }
  long long i = 1, j = 2;
  a[n] = 1000000000;
  while (i <= n && j <= n) {
    if (i + l < j) {
      i++;
      continue;
    }
    if (i == j) {
      j++;
      continue;
    }
    if (pre[i] <= a[j]) {
      pre[j] += pre[i];
      a[j] -= pre[i];
      pre[i] = 0;
      i++;
    } else {
      pre[i] -= a[j];
      pre[j] += a[j];
      a[j] = 0;
      j++;
    }
  }
  cout << pre[n] << '\n';
}
