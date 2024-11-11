#include <bits/stdc++.h>
using namespace std;
bitset<10000005> isPrime;
vector<int> primes;
long long fiA[10000005];
long long ordA1[10000005], ordA2[10000005];
long long tot = 0, cont = 0;
long long m, x;
void criba() {
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (long long i = 2; i < 10000005; ++i)
    if (isPrime[i]) {
      for (long long j = i * i; j < 10000005; j += i) isPrime[j] = false;
      primes.push_back(i);
    }
}
long long mulmod(long long a, long long b, long long c) {
  long long res = 0;
  while (a != 0) {
    if (a & 1) res = (res + b) % c;
    a >>= 1LL;
    b = (b << 1) % c;
  }
  return res;
}
long long fastPow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b != 0) {
    if (b & 1LL) res = mulmod(res, a, mod), b--;
    a = mulmod(a, a, mod);
    b >>= 1;
  }
  return res;
}
long long fiF(long long N) {
  long long PF_idx = 0, PF = primes[PF_idx], ans = N;
  while (PF_idx < (int)primes.size() && PF * PF <= N) {
    if (N % PF == 0) ans -= ans / PF;
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  criba();
  cont = tot = 0;
  cin >> m >> x;
  set<long long> div, dd;
  long long num = fiF(m);
  for (long long i = 1; i * i <= num; ++i) {
    if (num % i != 0) continue;
    div.insert(i);
    div.insert(num / i);
  }
  set<long long>::iterator it;
  int pos = 0;
  long long re;
  for (it = div.begin(), pos = 0; it != div.end(); ++it, pos++) {
    re = fastPow(x, *it, m);
    ordA1[pos] = *it;
    ordA2[pos] = (re) ? re : m;
  }
  long long d;
  num = m;
  for (long long i = 1; i * i <= num; ++i) {
    if (num % i != 0) continue;
    dd.insert(i);
    dd.insert(num / i);
  }
  for (it = dd.begin(), pos = 0; it != dd.end(); ++it, ++pos) {
    d = *it;
    for (int j = 0; j < div.size(); ++j)
      if (ordA2[j] % d == 1) {
        tot += (fiF(d) / ordA1[j]);
        break;
      }
  }
  cout << tot << "\n";
}
