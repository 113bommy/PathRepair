#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
int cnt;
int b[2000000], p[2000000];
map<long long, int> flag;
map<long long, long long> dp[20000];
long long N, fac[20000];
int M;
inline long long fastmul(long long a, long long b, long long p) {
  if (p <= 1000000000)
    return a * b % p;
  else {
    long long d = (long long)((long double)a * b / p + 0.5);
    long long ret = (a * b - d * p) % p;
    if (ret < 0) ret += p;
    return ret;
  }
}
long long Pow(long long base, long long n, long long mo) {
  if (n == 0) return 1;
  if (n == 1) return base;
  long long tmp = Pow(base, n >> 1, mo);
  tmp = fastmul(tmp, tmp, mo);
  if (n & 1) tmp = fastmul(tmp, base, mo);
  return tmp;
}
bool check_prime(long long p) {
  int times = 20;
  if (p < 2) return 0;
  if (p != 2 && p % 2 == 0) return 0;
  if (p == 2) return 1;
  long long s = p - 1LL;
  while (s % 2LL == 0) s >>= 1LL;
  while (times--) {
    long long a = rand() % (p - 1) + 1;
    long long tmp = s;
    long long mod = Pow(a, tmp, p);
    if (mod == 1 || mod == p - 1) continue;
    while (tmp != p - 1LL && mod != p - 1LL)
      mod = fastmul(mod, mod, p), tmp <<= 1LL;
    if (mod != p - 1) return 0;
  }
  return 1;
}
int main() {
  memset(b, 1, sizeof(b));
  for (int i = (2); i <= (1000000); ++i) {
    if (b[i]) p[++cnt] = i;
    for (int j = 1; j <= cnt && i * p[j] <= 1000000; ++j) {
      b[i * p[j]] = 0;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = (1); i <= (cnt); ++i) {
    for (long long j = p[i]; j <= 1000000000000LL; j *= p[i])
      flag[j + 1] = p[i];
  }
  scanf("%lld", &N);
  for (long long j = 1; j * j <= N; ++j)
    if (N % j == 0) {
      fac[++M] = j;
      if (j * j != N) fac[++M] = N / j;
    }
  sort(fac + 1, fac + M + 1);
  dp[1][0] = 1;
  for (int i = (2); i <= (M); ++i) {
    for (int j = (1); j <= (i - 1); ++j)
      if (fac[i] % fac[j] == 0)
        if (flag[fac[i] / fac[j]] || check_prime(fac[i] / fac[j] - 1)) {
          long long cur = flag[fac[i] / fac[j]];
          if (!cur) cur = fac[i] / fac[j] - 1;
          for (map<long long, long long>::iterator itr = dp[j].begin();
               itr != dp[j].end(); ++itr)
            if (itr->first < cur) dp[i][cur] += itr->second;
        }
  }
  long long ans = 0;
  for (map<long long, long long>::iterator itr = dp[M].begin();
       itr != dp[M].end(); ++itr)
    ans += itr->second;
  printf("%lld\n", ans);
  return 0;
}
