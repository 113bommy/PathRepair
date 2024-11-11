#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 2e5 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = a * a % M)
    if (b & 1) ret = 1ll * ret * a % M;
  return ret;
}
int n, m;
int i, j, k, t;
int a[maxn], pre[maxn], suf[maxn];
long long ans;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  ans = 1ll * n * (n - 1) / 2;
  for (i = 1; i <= n; i++) {
    pre[i] = i - 1;
    while (pre[i] != 0 && (a[pre[i]] | a[i]) == a[i]) pre[i] = pre[pre[i]];
  }
  for (i = n; i >= 1; i--) {
    suf[i] = i + 1;
    while (suf[i] != n + 1 && a[suf[i]] != a[i] && (a[suf[i]] | a[i]) == a[i])
      suf[i] = suf[suf[i]];
  }
  for (i = 1; i <= n; i++) ans -= (i - pre[i]) * (suf[i] - i) - 1;
  printf("%d\n", ans);
}
