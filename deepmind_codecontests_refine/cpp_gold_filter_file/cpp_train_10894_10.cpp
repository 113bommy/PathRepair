#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inv2 = mod / 2 + 1;
int n, k, S[5010];
int pow(long long a, int b, int m) {
  long long t = 1;
  for (; b; b >>= 1, a = a * a % m)
    if (b & 1) t = t * a % m;
  return t;
}
void CalS() {
  S[1] = 1;
  for (int i = 2; i <= k; i++)
    for (int j = i; j; j--) S[j] = (1LL * S[j] * j + S[j - 1]) % mod;
}
int main() {
  scanf("%d%d", &n, &k);
  CalS();
  int P = 1, M = pow(2, n, mod), ans = 0;
  for (int i = 1; i <= k; i++) {
    P = 1LL * P * (n - i + 1) % mod;
    M = 1LL * M * inv2 % mod;
    ans = (1LL * ans + 1LL * S[i] * P % mod * (long long)M % mod) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
