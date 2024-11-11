#include <bits/stdc++.h>
const int N = 62;
std::vector<int> prime;
int min[N], mu[N];
long long calc(long long n) {
  long long ret = 0;
  for (int i = 2; i < N; ++i) {
    long long left = 0, right = 1ll << N;
    while (left < right) {
      long long mid = left + right + 1 >> 1;
      int bitcnt = 0;
      while (mid) {
        mid >>= 1;
        ++bitcnt;
      }
      mid = left + right + 1 >> 1;
      if (bitcnt * i >= N) {
        right = mid - 1;
        continue;
      }
      long long x = 0;
      for (int j = 0; j < i; ++j) {
        x |= mid;
        mid <<= bitcnt;
      }
      mid = left + right + 1 >> 1;
      if (x <= n) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    ret += left * (-mu[i]);
  }
  return ret;
}
int main() {
  for (int i = 2; i < N; ++i) {
    if (!min[i]) {
      min[i] = i;
      prime.push_back(i);
      mu[i] = -1;
    }
    for (int j = 0, k, sz = prime.size(); j < sz && i * prime[j] < N; ++j) {
      min[k = i * prime[j]] = prime[j];
      if (i % prime[j] == 0) {
        mu[k] = 0;
        break;
      }
      mu[k] = -mu[i];
    }
  }
  long long l, r;
  scanf("%I64d%I64d", &l, &r);
  printf("%I64d\n", calc(r) - calc(l - 1));
  return 0;
}
