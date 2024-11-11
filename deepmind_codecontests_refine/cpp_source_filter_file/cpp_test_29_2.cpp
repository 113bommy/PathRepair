#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long fastpower(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return fastpower((x * x) % M, n / 2, M);
  else
    return (x * fastpower((x * x) % M, (n - 1) / 2, M)) % M;
}
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
long long modInverse(long long A, long long M) {
  return fastpower(A, M - 2, M);
}
void sieve(long long N) {
  bool isPrime[N + 1];
  for (long long i = 0; i <= N; ++i) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (long long i = 2; i * i <= N; ++i) {
    if (isPrime[i] == true) {
      for (long long j = i * i; j <= N; j += i) isPrime[j] = false;
    }
  }
}
vector<long long> factorize(long long n) {
  vector<long long> res;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    res.push_back(n);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long one = 0, zero = 0;
    for (long long i = 0; i < n; i++) {
      if (arr[i] == 1) one++;
      if (arr[i] == 0) zero++;
    }
    long long ans = ((long long)(1 << zero));
    ans *= (long long)one;
    cout << ans << endl;
  }
  return 0;
}
