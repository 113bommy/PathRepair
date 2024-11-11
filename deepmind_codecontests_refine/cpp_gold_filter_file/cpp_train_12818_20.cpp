#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int msb(long long int n) {
  long long int ans;
  for (long long int i = 31; i >= 0; i--)
    if ((1LL << i) & (n)) {
      ans = i;
      break;
    }
  return ans;
}
long long power(long long x, int y, int p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modFact(long long int n, long long int p) {
  if (n >= p) return 0;
  long long int result = 1;
  for (long long int i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
long long modInverse(long long n, int p) { return power(n, p - 2, p); }
long long nCrModPFermat(long long n, int r, int p) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
vector<long long int> primes;
void sieve(long long int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) primes.push_back(p);
}
vector<long long int> adj[100001], rev[100001];
bool vis[100001], recur[100001];
void init(long long int n) {
  for (long long int i = 0; i <= n; i++) {
    adj[i].clear();
    rev[i].clear();
    vis[i] = false;
    recur[i] = false;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, x, k;
  cin >> n >> x >> k;
  long long int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  if (x > k)
    cout << n << endl;
  else {
    int ct = 0;
    for (int i = 0; i < n; i++) {
      if (ar[i] <= x) ct++;
    }
    double ans = double(ct) / 2.0;
    cout << ceil(ans) << endl;
  }
  return 0;
}
