#include <bits/stdc++.h>
unsigned long long modMultiply(unsigned long long a, unsigned long long b,
                               unsigned long long mod) {
  long long ans = (a >> 32) * b % mod;
  ans = (ans << 16) % mod;
  ans += ((a >> 16) & 0xFFFF) * b % mod;
  ans = (ans << 16) % mod;
  ans += (a & 0xFFFF) * b % mod;
  return ans % mod;
}
unsigned long long modPow(unsigned long long a, unsigned long long p,
                          unsigned long long mod) {
  unsigned long long r = 1;
  while (p > 0) {
    if (p % 2 == 1) r = modMultiply(r, a, mod);
    a = modMultiply(a, a, mod);
    p /= 2;
  }
  return r;
}
unsigned long long x;
template <class Iterator>
unsigned long long countLoops(unsigned long long m, unsigned long long eulerPhi,
                              Iterator first, Iterator last) {
  auto d = eulerPhi, a = x % m;
  while (first != last) {
    while (modPow(a, d / *first, m) == 1) {
      d /= *first;
      if (d % *first != 0) break;
    }
    ++first;
  }
  return eulerPhi / d;
}
std::vector<std::vector<unsigned long long> > factorTable;
std::set<unsigned long long> factors;
std::vector<std::pair<unsigned long long, unsigned> > factorList;
unsigned long long dfs(int d, unsigned long long m,
                       unsigned long long eulerPhi) {
  if (d == factorList.size())
    return countLoops(m, eulerPhi, factors.cbegin(), factors.cend());
  auto ans = dfs(d + 1, m, eulerPhi);
  std::set<unsigned long long> set;
  auto prime = factorList[d].first;
  m *= prime;
  eulerPhi *= prime - 1;
  for (auto p : factorTable[d]) {
    if (factors.count(p) == 0) {
      factors.emplace(p);
      set.emplace(p);
    }
  }
  ans += dfs(d + 1, m, eulerPhi);
  if (factorList[d].second > 1) {
    if (factors.count(prime) == 0) {
      factors.emplace(prime);
      set.emplace(prime);
    }
  }
  for (int i = 2; i <= factorList[d].second; ++i) {
    m *= prime, eulerPhi *= prime;
    ans += dfs(d + 1, m, eulerPhi);
  }
  for (auto p : set) factors.erase(p);
  return ans;
}
std::vector<int> getPrimes() {
  bool* pp = new bool[10000008];
  std::vector<int> ans;
  memset(pp, 0, 10000008 * sizeof(bool));
  for (int i = 2; i < 10000008; ++i) {
    if (pp[i] == true) continue;
    for (int j = i + i; j < 10000008; j += i) pp[i] = true;
    ans.emplace_back(i);
  }
  return std::move(ans);
}
const std::vector<int> primes = getPrimes();
std::vector<unsigned long long> getFactors(unsigned long long x) {
  std::vector<unsigned long long> ans;
  for (auto p : primes) {
    if (p > x) break;
    if (x % p != 0) continue;
    ans.emplace_back(p);
    do {
      x /= p;
    } while (x % p == 0);
  }
  if (x != 1) ans.emplace_back(x);
  return std::move(ans);
}
unsigned long long solve(unsigned long long m) {
  unsigned long long v = m;
  for (auto p : primes) {
    if (p > v) break;
    if (v % p != 0) continue;
    unsigned k = 0;
    do {
      v /= p;
      ++k;
    } while (v % p == 0);
    factorList.emplace_back(p, k);
  }
  if (v != 1) factorList.emplace_back(x, 1);
  for (auto p : factorList) {
    factorTable.emplace_back(getFactors(p.first - 1));
  }
  return dfs(0, 1, 1);
}
int main(void) {
  unsigned long long m;
  std::cin >> m >> x;
  auto ans = solve(m);
  std::cout << ans << std::endl;
  return 0;
}
