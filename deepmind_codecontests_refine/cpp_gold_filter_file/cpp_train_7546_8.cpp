#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
const int maxn = 1e5 + 5;
const int MOD = 1000000007;
long long A[maxn], invA[maxn];
long long inv[maxn];
long long C(int n, int m) { return A[n] * invA[m] % MOD * invA[n - m] % MOD; }
int main() {
  int n;
  scanf("%d", &n);
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
  }
  A[0] = invA[0] = 1;
  for (int i = 1; i <= n; i++) {
    A[i] = A[i - 1] * i % MOD;
    invA[i] = invA[i - 1] * inv[i] % MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long t = C(n - 1, i - 1) * C(n, i) % MOD;
    if (i != 1) t = t * 2 % MOD;
    ans = (ans + t) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
