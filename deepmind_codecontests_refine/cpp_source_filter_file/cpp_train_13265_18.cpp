#include <bits/stdc++.h>
using namespace std;
vector<int> p;
map<int, int> u;
bool is[10000010];
long long mod = 1e9 + 7;
void sieve() {
  memset(is, 0, sizeof is);
  for (int i = 2; i < 10000010; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (int j = 2 * i; j <= 10000010; j += i) is[j] = 1;
    }
  }
}
bool isprime(int n) {
  if (n < 10000010) return !is[n];
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void factorize(int k) {
  int ind = 0;
  while (ind < p.size() && !isprime(k)) {
    while (ind < p.size() && k % p[ind]) ind++;
    if (ind >= p.size()) break;
    k /= p[ind];
    u[ind]++;
  }
  u[k]++;
}
long long pw(long long b, long long p) {
  if (!p) return 1;
  if (p == 1) return b % mod;
  if (p % 2) return (b * pw((b * b) % mod, (p - 1) / 2) % mod) % mod;
  return pw((b * b) % mod, p / 2) % mod;
}
long long C(long long n, long long r) {
  if (!r) return 1;
  long long ret = 1;
  for (long long i = 1; i <= r; i++) {
    ret = (ret * n--) % mod;
    ret = (ret * pw(i, mod - 2)) % mod;
  }
  return ret;
}
int main() {
  sieve();
  int n;
  scanf("%d", &n);
  ;
  u.clear();
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    ;
    factorize(tmp);
  }
  long long res = 1;
  for (map<int, int>::iterator it = u.begin(); it != u.end(); it++) {
    if (it->first == 1) continue;
    res = (res * C(it->second + n - 1, n - 1)) % mod;
  }
  printf("%I64d\n", res);
  ;
  return 0;
}
