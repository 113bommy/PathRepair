#include <bits/stdc++.h>
using namespace std;
int n;
int a[111];
int memo[111][1 << 17];
pair<pair<int, int>, int> child[111][1 << 17];
int bt[66];
class MathFunction {
 private:
  long long sieve_size;
  bitset<1010> bs;
  vector<int> primes;

 public:
  int primeid[1010];
  bool isPrime(long long N) {
    if (N <= sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
      if (N % primes[i] == 0) return false;
    return true;
  }
  void sieve(long long upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i < sieve_size; i++) {
      if (bs[i]) {
        for (long long j = i * i; j < sieve_size; j += i) bs[j] = 0;
        primeid[(int)i] = primes.size();
        primes.push_back((int)i);
      }
    }
  }
  vector<int> primeFactors(long long N) {
    vector<int> factors;
    long long idx = 0, pf = primes[idx];
    while (N != 1 && (pf * pf <= N)) {
      while (N % pf == 0) {
        N /= pf;
        factors.push_back(pf);
      }
      pf = primes[++idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
  }
};
MathFunction mat;
int dp(int pos, int bitmask) {
  if (pos == n) return 0;
  if (memo[pos][bitmask] >= 0) return memo[pos][bitmask];
  int q = abs(1 - a[pos]) + dp(pos + 1, bitmask);
  child[pos][bitmask] =
      pair<pair<int, int>, int>(pair<int, int>(pos + 1, bitmask), 1);
  for (int i = 2; i < a[pos] + a[pos]; i++) {
    if ((bitmask & bt[i]) == 0) {
      int d = abs(i - a[pos]) + dp(pos + 1, bitmask | bt[i]);
      if (d < q) {
        q = d;
        child[pos][bitmask] = pair<pair<int, int>, int>(
            pair<int, int>(pos + 1, bitmask | bt[i]), i);
      }
    }
  }
  return memo[pos][bitmask] = q;
}
void printAns(int pos, int bitmask) {
  if (pos == n) return;
  pair<int, int> nx = child[pos][bitmask].first;
  int val = child[pos][bitmask].second;
  printf("%d ", val);
  printAns(nx.first, nx.second);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  mat.sieve(100);
  bt[1] = 0;
  for (int i = 2; i <= 61; i++) {
    vector<int> v = mat.primeFactors(i);
    int b = 0;
    for (int j = 0; j < v.size(); j++) {
      if (mat.primeid[v[j]] <= 13) b |= (1 << mat.primeid[v[j]]);
    }
    bt[i] = b;
  }
  memset(memo, -1, sizeof memo);
  dp(0, 0);
  printAns(0, 0);
  return 0;
}
