#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
int IT_MAX = 1 << 20;
long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
long long mypow(long long a, long long b) {
  long long rv = 1;
  while (b) {
    if (b % 2) rv = (rv * a) % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return rv;
}
bool pchk[2000050];
int v1[2000050];
long long v2[2000050];
long long del[2000050];
int main() {
  int N, K, i, j;
  scanf("%d %d", &N, &K);
  for (i = 1; i <= 2000000; i++) v1[i] = 1;
  for (i = 2; i <= 2000000; i++) {
    if (pchk[i]) continue;
    for (j = 2 * i; j <= 2000000; j += i) pchk[j] = true;
    for (j = i; j <= 2000000; j += i) v1[j] *= -1;
    if (i <= 10000)
      for (j = i * i; j <= 2000000; j += i * i) v1[j] = 0;
  }
  for (i = 1; i <= 2000000; i++) v2[i] = mypow(i, N);
  for (i = 1; i <= K; i++) {
    for (j = 1;; j++) {
      int st = i * j, en = i * (j + 1) - 1;
      if (st > K) break;
      en = min(en, K);
      del[st] = (del[st] + v1[i] * v2[j] % MOD + MOD) % MOD;
      del[en + 1] = (del[en + 1] - v1[i] * v2[j] % MOD + MOD) % MOD;
    }
  }
  long long ans = 0;
  for (i = 1; i <= K; i++) {
    del[i] = (del[i] + del[i - 1]) % MOD;
    ans = (ans + (del[i] ^ i)) % MOD;
  }
  return !printf("%lld\n", ans);
}
