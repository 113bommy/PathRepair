#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = 1000000007) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = 1000000007) {
  return (a % p + b % p) % p;
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
long long a[300005];
long long ev[300005];
long long odd[300005];
long long sum[300005];
int main() {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long p;
    cin >> p;
    a[i] = __builtin_popcountll(p);
  }
  for (long long i = n - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + a[i];
    odd[i] += odd[i + 1];
    ev[i] += ev[i + 1];
    if (sum[i] & 1) {
      odd[i - 1]++;
    } else {
      ev[i - 1]++;
    }
  }
  long long ans = 0;
  for (long long i = n - 2; i >= 0; i--) {
    if (sum[i] & 1) {
      ans += odd[i];
    } else {
      ans += ev[i];
      ans++;
    }
    long long sm = 0;
    long long maxx = 0;
    for (long long j = i; j < min((long long)100 + i, n); j++) {
      sm += a[j];
      maxx = max(maxx, a[j]);
      if (sm % 2 == 0 && 2 * maxx > sm) {
        ans--;
      }
    }
  }
  cout << ans << "\n";
}
