#include <bits/stdc++.h>
using namespace std;
long long int _sieve_size;
bitset<20000010> bs;
vector<int> primes;
void sieve(long long int upperbound) {
  _sieve_size = upperbound + 1;
  bs.reset();
  bs.flip();
  bs.set(0, false);
  bs.set(1, false);
  for (long long int i = 2; i <= _sieve_size; i++)
    if (bs.test((size_t)i)) {
      for (long long int j = i * i; j <= _sieve_size; j += i)
        bs.set((size_t)j, false);
      primes.push_back((int)i);
    }
}
bool isPrime(long long int N) {
  if (N < _sieve_size) return bs.test(N);
  for (int i = int(0); i <= int(primes.size() - 1); i++) {
    if (N % primes[i] == 0) return false;
    if (primes[i] > sqrt(N)) return true;
  }
  return true;
}
long long int a, b;
int ans = 0;
void recurse(int idx, long long int val, int sign) {
  if (idx == primes.size()) {
    int tmp = (b / val) - ((a - 1) / val);
    ans += sign * tmp;
    return;
  }
  recurse(idx + 1, val, sign);
  if (val * primes[idx] <= b) recurse(idx + 1, val * primes[idx], sign * -1);
}
int main() {
  sieve(2000000);
  long long int k;
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &k);
  if (isPrime(k) || k > b) {
    if (k * k > b && k >= a)
      printf("1\n");
    else if (k * k > b && k < a)
      printf("0\n");
    else {
      ans = 0;
      sort(primes.begin(), primes.end());
      while (!primes.empty() && primes.back() >= k) primes.pop_back();
      recurse(0, k, 1);
      printf("%d\n", ans);
    }
  } else
    printf("0\n");
  return 0;
}
