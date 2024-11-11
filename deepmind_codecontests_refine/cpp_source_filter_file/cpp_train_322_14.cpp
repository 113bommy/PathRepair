#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
long long comb[5201][5201], p, s, r;
long long fastPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long calc(long long p, long long up, long long sum) {
  if (p == 0) return 1;
  long long ans = 0;
  for (int i = 0; i <= p; i++) {
    if (i * up > sum) break;
    if (i & 1)
      ans = (ans - comb[p][i] * comb[sum - i * up + p - 1][p - 1] % mod + mod) %
            mod;
    else
      ans = (ans + comb[p][i] * comb[sum - i * up + p - 1][p - 1] % mod) % mod;
  }
  return ans;
}
int main() {
  for (int i = 0; i <= 5200; i++)
    for (int j = comb[i][0] = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
  int up = 4, tar = 6, tmp = 0;
  for (int i = 0; i < up; i++) {
    for (int j = 0; j < up; j++) {
      for (int k = 0; k < up; k++)
        if (i + j + k == tar) tmp++;
    }
  }
  scanf("%lld%lld%lld", &p, &s, &r);
  if (p == 1) {
    puts("1");
  } else if (s == 0) {
    printf("%d\n", fastPow(p, mod - 2));
  } else {
    long long Q = 0, P = 0;
    for (int i = r; i <= s; i++) {
      Q = (Q + comb[s - i + p - 2][p - 2]) % mod;
      for (int j = 0; j < p && j * i + i <= s; j++) {
        long long cnt1 = comb[p - 1][j];
        long long cnt2 = calc(p - j - 1, i, s - (j * i + i));
        P = (P + cnt1 * cnt2 % mod * fastPow(j + 1, mod - 2) % mod) % mod;
      }
    }
    printf("%lld\n", P * fastPow(Q, mod - 2) % mod);
  }
  return 0;
}
