#include <bits/stdc++.h>
const int64_t N = 21000000;
bool composite[N + 1];
int pcount[N + 1];
std::vector<int> primes;
void sieve() {
  composite[0] = true;
  composite[1] = true;
  pcount[0] = 0;
  pcount[1] = 0;
  for (int i = 2; i <= N; ++i) {
    pcount[i] = pcount[i - 1];
    if (!composite[i]) {
      pcount[i]++;
      primes.push_back(i);
      for (int j = i + i; j <= N; j += i) {
        composite[j] = true;
      }
    }
  }
}
std::map<std::pair<int64_t, int64_t>, int64_t> dpphi;
int64_t phi(int64_t x, int64_t a) {
  if (a == 1) return (x + 1) / 2;
  if (x == 0) return 0;
  auto pr = std::make_pair(x, a);
  auto it = dpphi.find(pr);
  if (it != dpphi.end()) return it->second;
  return dpphi[pr] = phi(x, a - 1) - phi(x / primes[a - 1], a - 1);
}
std::map<int64_t, int64_t> dp;
int64_t pi(int64_t n) {
  if (n <= N) return pcount[n];
  auto it = dp.find(n);
  if (it != dp.end()) return dp[n];
  int64_t a = pi(std::pow(n, 1.0 / 4.0));
  int64_t b = pi(std::pow(n, 1.0 / 2.0));
  int64_t c = pi(std::pow(n, 1.0 / 3.0));
  int64_t total = phi(n, a) + (b + a - 2) * (b - a + 1) / 2;
  for (int64_t i = a + 1; i <= b; ++i) {
    int64_t w = n / primes[i - 1];
    int64_t lm = pi(std::sqrt(w));
    total = total - pi(w);
    if (i <= c) {
      for (int64_t j = i; j <= lm; ++j) {
        total = total - pi(w / primes[j - 1]) + j - 1;
      }
    }
  }
  return dp[n] = total;
}
int main() {
  sieve();
  int64_t n;
  std::cin >> n;
  int64_t total = pi(std::pow(n, 1.0 / 3.0) + 0.1);
  auto pbound = std::sqrt(n);
  for (int i = 0; i < primes.size(); ++i) {
    int p = primes[i];
    if (p >= pbound) break;
    total += (pi(n / p) - pi(p));
  }
  std::cout << total << '\n';
  return 0;
}
