#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
unsigned long long n, k, l, m;
vector<unsigned long long> pibo;
map<long long, long long> pib;
unsigned long long getPow(unsigned long long n) {
  if (n == 1) return 2 % m;
  if (n % 2) return (getPow(n - 1) * 2) % m;
  unsigned long long pow = getPow(n / 2);
  return (pow * pow) % m;
}
void calPibo(unsigned long long n) {
  unsigned long long prepre = 1, pre = 1;
  pibo.push_back(1);
  pibo.push_back(1);
  while (pibo.size() < n) {
    unsigned long long curr = (prepre + pre) % m;
    pibo.push_back(curr);
    prepre = pre;
    pre = curr;
  }
}
unsigned long long getPibo(unsigned long long n) {
  if (n - 1 < pibo.size()) return pibo[n - 1];
  if (pib.count(n)) return pib[n];
  unsigned long long h1 = n / 2, h2 = h1 + 1;
  unsigned long long pib1 = getPibo(h1), pib2 = getPibo(h2);
  if (n % 2) return pib[n] = ((((pib1 * pib1) % m) + pib2 * pib2) % m);
  return pib[n] = ((((pib1 * pib2 * 2) % m) - (pib1 * pib1) % m + m) % m);
}
int main() {
  cin >> n >> k >> l >> m;
  calPibo(100);
  unsigned long long s1 = (unsigned long long)(getPibo(n + 2)) % m;
  unsigned long long s0 = (getPow(n) - s1 + m) % m;
  unsigned long long ret = 1;
  for (unsigned long long i = 0; i < l; i++) {
    if (k & (1ULL << i)) {
      ret *= s0;
    } else
      ret *= s1;
    ret %= m;
  }
  if (l < 64 && k > (1ULL << l) - 1) ret *= 0;
  cout << ret << endl;
}
