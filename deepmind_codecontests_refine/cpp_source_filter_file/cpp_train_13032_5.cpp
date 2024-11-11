#include <bits/stdc++.h>
using namespace std;
vector<long long> prime() {
  vector<long long> v;
  for (int i = 0; i < 1000001; i++) {
    if (i % 2)
      v.push_back(1);
    else
      v.push_back(0);
  }
  for (long long i = 3; i < 1000001; i++) {
    if (v[i] == 1) {
      for (long long j = i * i; j < 1000001; j += i) v[j] = 0;
    }
  }
  v[1] = 0;
  v[2] = 1;
  return v;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long c = b / 2;
  if (b % 2 == 0)
    return (power(((a % 1000000007) * (a % 1000000007)) % 1000000007, c)) %
           1000000007;
  else
    return ((a % 1000000007) *
            power(((a % 1000000007) * (a % 1000000007)) % 1000000007, c)) %
           1000000007;
}
int main() {
  long long x, n, ans = 1;
  cin >> x >> n;
  vector<long long> primes = prime(), v, v1;
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] == 1) v.push_back(i);
  }
  long long i = 0;
  while (v[i] <= sqrt(x)) {
    if (x % v[i] == 0) {
      v1.push_back(v[i]);
      while (x % v[i] == 0) {
        x /= v[i];
      }
    }
    i++;
  }
  if (x > 2) v1.push_back(x);
  for (int i = 0; i < v1.size(); i++) {
    long long temp = v1[i];
    long long n1 = n / temp;
    while (temp <= n1) {
      long long f = n / temp;
      ans *= (power(v1[i], f)) % 1000000007;
      ans = (ans + 1000000007) % 1000000007;
      temp *= v1[i];
    }
    long long f = n / temp;
    ans *= (power(v1[i], f)) % 1000000007;
    ans = (ans + 1000000007) % 1000000007;
  }
  cout << (ans + 1000000007) % 1000000007;
  return 0;
}
