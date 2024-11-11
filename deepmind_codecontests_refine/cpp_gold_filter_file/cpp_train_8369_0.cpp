#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 9;
char c[N];
long long Xpow(long long b, long long p) {
  if (!p) return 1;
  long long h = Xpow(b, p >> 1);
  long long ret = h * h % 1000000007;
  if (p & 1) ret *= b;
  ret %= 1000000007;
  return ret;
}
long long to_B10(int b, int n) {
  long long res = 0;
  for (__typeof(n) i = 0; i < n; ++i) {
    res *= b;
    res %= 1000000007;
    res += c[i] - '0';
    res %= 1000000007;
  }
  return res;
}
int main() {
  scanf("%s", c);
  int n = strlen(c);
  long long e = Xpow(2, n - 1);
  long long x = to_B10(2, n);
  long long ans = e * x;
  ans %= 1000000007;
  printf("%I64d", ans);
  return 0;
}
