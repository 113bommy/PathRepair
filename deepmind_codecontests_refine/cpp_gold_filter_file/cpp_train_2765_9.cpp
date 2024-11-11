#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    T t = bigmod(p, e / 2, M);
    return (t * t) % M;
  }
  return (bigmod(p, e - 1, M) * p) % M;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T multimod(T a, T b, T m) {
  T ans = 0ll;
  a %= m, b %= m;
  while (b) {
    if (b & 1ll) ans = m - ans > a ? (ans + a) : (ans + a - m);
    b >>= 1ll;
    a = (m - a) > a ? a + a : a + a - m;
  }
  return (T)ans;
}
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
long long arr[(200000 + 7)];
long long sum[(200000 + 7)];
long long dp[(200000 + 7)][2];
int n;
long long solve(int ind, bool is) {
  if (ind == n - 1) {
    if (is) return -sum[ind];
    return sum[ind];
  }
  long long &ret = dp[ind][is];
  if (ret + 1) return ret;
  ret = solve(ind + 1, is);
  if (!is) {
    ret = max(ret, sum[ind] + solve(ind + 1, is ^ 1));
  } else {
    ret = min(ret, solve(ind + 1, is ^ 1) - sum[ind]);
  }
  return ret;
}
int main() {
  int j, i;
  int a, t, b, u, v, cases = 1;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    sum[0] = arr[0];
    if (i) sum[i] = sum[i - 1] + arr[i];
  }
  memset(dp, -1, sizeof dp);
  long long res = solve(1, 0);
  printf("%lld\n", res);
  return 0;
}
