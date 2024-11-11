#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
const long long int INF = 1e15;
long long int sub(long long int a, long long int b, long long int p = MOD) {
  return ((a % p) - (b % p) + p) % p;
}
long long int mult(long long int a, long long int b, long long int p = MOD) {
  return ((a % p) * (b % p)) % p;
}
long long int add(long long int a, long long int b, long long int p = MOD) {
  return (a % p + b % p) % p;
}
long long int fpow(long long int n, long long int k, long long int p = MOD) {
  long long int r = 1;
  while (k > 0) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
    k = k >> 1;
  }
  return r;
}
long long int inv(long long int a, long long int p = MOD) {
  return fpow(a, p - 2, p);
}
long long int fdiv(long long int a, long long int b, long long int p = MOD) {
  long long int yinv = inv(b);
  long long int ans = (a * yinv) % p;
  return ans;
}
unsigned long long int I1018 = 1000000000000000000;
const unsigned long long int I10e5 = 100000;
const long long int I10e6 = 1e6;
long long int ZERO = 0;
unsigned long long int I10e9 = 1000000000;
long long int ONE = 1;
void printVecpll(std::vector<pair<long long int, long long int> > v) {
  for (auto p : v) {
    cout << (char)p.first << " " << p.second << endl;
  }
}
void printVec(std::vector<long long int> v) {
  for (long long int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
std::vector<long long int> read_vec(long long int n) {
  long long int i;
  std::vector<long long int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}
std::vector<bool> is_prime;
std::vector<long long int> primes;
void sieve(long long int n) {
  is_prime.resize(n + 2, true);
  primes.clear();
  long long int p;
  for (p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      long long int i;
      for (i = p * p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
  is_prime[0] = is_prime[1] = false;
  long long int i;
  for (i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.emplace_back(i);
    }
  }
}
set<long long int> prime_factor(long long int n) {
  long long int i;
  set<long long int> s;
  for (auto p : primes) {
    if (p > sqrt(n)) break;
    while (n % p == 0 && n > 1) {
      s.insert(p);
      n /= p;
    }
  }
  if (n > 1) {
    s.insert(n);
  }
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n;
  cin >> n;
  long long int i, j;
  std::vector<long long int> v(2 * n + 1);
  for (i = 1; i < 2 * n + 1; i++) {
    cin >> v[i];
  }
  sort(v.begin() + 1, v.end());
  long long int ap = INF;
  for (i = 2; i <= n; i++) {
    ap = min(ap, v[i + n - 1] - v[i]);
  }
  ap *= (v[2 * n] - v[1]);
  long long int bp = (v[n] - v[1]) * (v[2 * n] - v[n + 1]);
  long long int ans = min(ap, bp);
  cout << ans << endl;
  return 0;
}
