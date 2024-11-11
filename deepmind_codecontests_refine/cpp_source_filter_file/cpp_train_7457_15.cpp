#include <bits/stdc++.h>
namespace nt {
std::vector<long long> get_primes(long long x) {
  std::vector<long long> ret;
  for (long long p = 2; p * p <= x; p++) {
    if (x % p != 0) continue;
    ret.push_back(p);
    while (x % p == 0) x /= p;
  }
  if (x != 1) ret.push_back(x);
  return ret;
}
std::vector<int> factorize(long long x, const std::vector<long long>& primes) {
  std::vector<int> factors(primes.size(), 0);
  for (int i = 0; i < primes.size(); i++) {
    while (x % primes[i] == 0) {
      factors[i]++;
      x /= primes[i];
    }
  }
  return factors;
}
std::vector<long long> primes(long long upto) {
  std::vector<bool> is_prime(upto + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= upto; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j <= upto; j += i) is_prime[j] = false;
    }
  }
  std::vector<long long> ret;
  for (int i = 2; i <= upto; i++)
    if (is_prime[i]) ret.push_back(i);
  return ret;
}
long long gcd(long long a, long long b) {
  a = (a > 0 ? a : -a);
  b = (b > 0 ? b : -b);
  while (a > 0) {
    long long tmp = b % a;
    b = a;
    a = tmp;
  }
  return b;
}
long long mod_pow(long long x, long long n, long long p) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long long ret = mod_pow(x, n / 2, p);
  ret = (ret * ret) % p;
  if (n % 2 == 1) ret = (ret * x) % p;
  return ret;
}
long long inverse_mod_p(long long x, long long p) {
  return mod_pow(x, p - 2, p);
}
long long inverse(long long a, long long b) {
  a %= b;
  if (a == 1LL) return 1LL;
  long long y = inverse(b, a);
  return b - (y * b - 1) / a;
}
}  // namespace nt
using namespace std;
const long long POW_MAX = 1000;
const int N_MAX = 100100;
int N, K;
long long M[70];
long long w[N_MAX];
vector<long long> seg_powers[N_MAX];
long long phi(long long x) {
  long long answer = 1;
  vector<long long> primes = nt::get_primes(x);
  vector<int> factors = nt::factorize(x, primes);
  for (int i = 0; i < primes.size(); i++) {
    long long p = primes[i];
    answer *= p - 1;
    for (int j = 1; j < factors[i]; j++) answer *= p;
  }
  return answer;
}
void init() {
  for (int i = N - 1; i >= 0; i--) {
    seg_powers[i].push_back(w[i]);
    if (w[i] == 1) continue;
    for (int j = i + 1; j < N; j++) {
      if (w[j] == 1) break;
      long long val = w[j];
      for (int k = j - 1; k >= i; k--) {
        long long base = w[k];
        long long next_val = 1;
        for (int s = 0; s < val; s++) {
          next_val = min(POW_MAX, next_val * w[k]);
          if (next_val == POW_MAX) break;
        }
        val = next_val;
        if (next_val == POW_MAX) break;
      }
      seg_powers[i].push_back(val);
      if (val == POW_MAX) break;
    }
  }
}
long long seg_pow(int l, int r) {
  if (r - l < seg_powers[l].size() - 1) return seg_powers[l][r - l];
  return seg_powers[l].back();
}
long long query(int l, int r, int depth = 0) {
  long long x = w[l];
  long long m = M[depth];
  if (m <= 2 || l == r) return x % m;
  long long power = seg_pow(l + 1, r);
  if (power < POW_MAX) return nt::mod_pow(x, power, m);
  long long remainder = query(l + 1, r, depth + 1);
  return nt::mod_pow(x, (remainder + M[depth + 1] * POW_MAX), m);
}
int main() {
  cin >> N >> M[0];
  K = 1;
  while (M[K - 1] > 2) {
    M[K] = phi(M[K - 1]);
    K++;
  }
  for (int i = 0; i < N; i++) cin >> w[i];
  init();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << query(l, r) << "\n";
  }
}
