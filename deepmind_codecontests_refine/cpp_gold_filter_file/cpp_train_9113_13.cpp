#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000003;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000003;
    y = y >> 1;
    x = (x * x) % 1000003;
  }
  return res;
}
vector<vector<long long> > newdp(long long A, long long B) {
  vector<vector<long long> > dp;
  dp.resize(A + 1);
  for (int i = 0; i < A + 1; i++) {
    dp[i].resize(B + 1);
    for (int j = 0; j < B + 1; j++) dp[i][j] = -1;
  }
  return dp;
}
vector<long long> all_prime;
void prime() {
  bool hash[1000000];
  memset(hash, false, sizeof hash);
  for (int p = 2; p * p < 1000000; p++)
    if (hash[p] == true)
      for (int i = p * 2; i < 1000000; i += p) hash[i] = false;
  for (int i = 2; i < 1000000; i++)
    if (hash[i]) all_prime.push_back(i);
}
int main(int argc, char const *argv[]) {
  long long n, k;
  cin >> n >> k;
  if (n <= 63 && k > (1ll << n)) {
    cout << "1 1";
    return 0;
  }
  long long legendre_divisible = (k - 1) - __builtin_popcountll(k - 1);
  long long original_k = k;
  n = n % (1000003 - 1);
  k = k % (1000003 - 1);
  long long exp = ((n * (k - 1)) + (1000003 - 1)) % (1000003 - 1);
  long long den = power(2, exp);
  den = (den * power(power(2, 1000003 - 2), legendre_divisible)) % 1000003;
  long long num = 0;
  if ((original_k - 1) < 1000003) {
    long long prod = 1;
    long long t = power(2, n);
    for (int i = 1; i <= original_k - 1; i++)
      prod = ((prod * (t - i)) + 1000003) % 1000003;
    num = (prod * power(power(2, 1000003 - 2), legendre_divisible)) % 1000003;
  }
  num = (den - num + 1000003) % 1000003;
  cout << num << " " << den;
  return 0;
}
