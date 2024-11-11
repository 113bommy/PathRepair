#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
const long long mod = 998244353;
long long A[maxn], B[maxn], C[maxn];
bool cmp(long long a, long long b) { return a > b; }
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &A[i]);
  }
  for (int i = 1; i <= n; i++) scanf("%lld", &B[i]);
  for (long long i = 1; i <= n; i++) {
    C[i] = A[i] * i * (n - i + 1ll);
  }
  sort(C + 1, C + n + 1);
  sort(B + 1, B + n + 1, cmp);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (C[i] * B[i]);
    ans %= mod;
  }
  printf("%lld", ans);
  return 0;
}
