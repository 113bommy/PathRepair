#include <bits/stdc++.h>
using namespace std;
long long N, M, ans, temp, lo, hi, done, a, b, rem;
inline long long go(long long n) {
  n %= 1000000007;
  return (n * (n + 1) / 2) % 1000000007;
}
int main() {
  scanf("%lld %lld", &N, &M);
  ans = ((N % 1000000007) * (M % 1000000007)) % 1000000007;
  done = M + 1;
  for (long long mult = 1; mult * mult <= N; mult++) {
    temp = 0;
    lo = N / (mult + 1) + 1;
    hi = min(M, N / mult);
    if (lo > hi) break;
    temp = (go(hi) - go(lo - 1) + 1000000007) % 1000000007;
    temp = (temp * mult) % 1000000007;
    ans = (ans - temp + 1000000007) % 1000000007;
    done = lo;
  }
  for (long long div = 1; div * div <= N && div < done; div++) {
    ans = (ans - ((div * (N / div)) % 1000000007) + 1000000007) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
