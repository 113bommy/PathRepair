#include <bits/stdc++.h>
using namespace std;
int f[10000000 + 1];
long long pf[100000];
bool is_prime[10000000];
vector<int> primes;
void gen_primes() {
  memset(is_prime, 1, sizeof is_prime);
  for (long long i = 2; i * i < 10000000; ++i)
    if (is_prime[i])
      for (long long j = i * i; j < 10000000; j += i) is_prime[j] = 0;
  for (int j = 2; j < 10000000; ++j)
    if (is_prime[j]) primes.push_back(j);
}
bool check(long long v, int mx) {
  for (int i = 0; i < primes.size() && primes[i] <= mx; ++i) {
    long long cnt = 0;
    for (long long j = primes[i]; j <= v; j *= primes[i]) cnt += v / j;
    if (cnt < pf[i]) return 0;
  }
  return 1;
}
int main() {
  gen_primes();
  int k;
  scanf("%d", &k);
  int mx = 0;
  long long s = 0;
  bool all1 = 1;
  for (int i = 0, t; i < k; ++i) {
    scanf("%d", &t);
    ++f[t];
    s += t;
    all1 &= t == 1;
    mx = max(mx, t);
  }
  if (all1) {
    printf("1\n");
    return 0;
  }
  for (int i = mx - 1; i > 1; --i) f[i] += f[i + 1];
  for (int i = 0; i < primes.size() && primes[i] <= mx; ++i) {
    for (int j = primes[i]; j <= mx; j += primes[i]) {
      int l = j;
      long long q = 0;
      while (l % primes[i] == 0) ++q, l /= primes[i];
      pf[i] += f[j] * q;
    }
  }
  long long lo = mx, hi = s;
  while (lo < hi) {
    long long m = (lo + hi) >> 1;
    if (check(m, mx))
      hi = m;
    else
      lo = m + 1;
  }
  cout << lo << endl;
  return 0;
}
