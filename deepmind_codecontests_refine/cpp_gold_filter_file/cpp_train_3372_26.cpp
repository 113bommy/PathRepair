#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int maxn = 6e6 + 5;
int prime[maxn + 5];
bool check[maxn + 5];
int phi[maxn + 5];
int num_prime;
void init() {
  memset(check, false, sizeof(check));
  phi[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    if (!check[i]) {
      prime[num_prime++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < num_prime; j++) {
      if (i * prime[j] > maxn) break;
      check[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      }
    }
  }
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void get(long long n, vector<long long>& fac) {
  fac.clear();
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      fac.push_back(i);
      while (n % i == 0) n /= i;
    }
  if (n > 1) fac.push_back(n);
}
long long qpow(long long x, long long n, long long mod) {
  long long ret = 1;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
  }
  return ret;
}
vector<long long> fac;
vector<long long> ans;
bool ok(long long x) {
  if (x % 2 == 0) x /= 2;
  if (x % 2 == 0) return false;
  for (int i = 0; prime[i] * prime[i] <= x; i++)
    if (x % prime[i] == 0) {
      while (x % prime[i] == 0) x /= prime[i];
      return x == 1;
    }
  return true;
}
long long get_g(long long p, long long x) {
  for (long long i = x - 1; i >= 2ll; i--) {
    if (i % p == 0) continue;
    bool flag = false;
    for (long long x : fac)
      if (qpow(i, phi[p] / x, p) == 1) {
        flag = true;
        break;
      }
    if (!flag) return i;
  }
  return -1;
}
void GetAns(long long g, long long p, vector<long long>& ans) {
  ans.clear();
  ans.push_back(g);
  for (int i = 2; i < phi[p]; i++)
    if (gcd(i, phi[p]) == 1) ans.push_back(qpow(g, i, p));
}
bool isp(long long x) {
  for (long long i = 2ll; i <= sqrt(x); ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  init();
  long long n, x;
  scanf("%lld %lld", &n, &x);
  if (!isp(n + 1)) {
    puts("-1");
  } else {
    get(phi[n + 1], fac);
    long long ans = get_g(n + 1, x);
    printf("%lld\n", ans);
  }
  return 0;
}
