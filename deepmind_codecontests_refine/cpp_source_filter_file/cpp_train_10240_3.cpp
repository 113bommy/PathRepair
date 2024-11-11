#include <bits/stdc++.h>
using namespace std;
inline void getint(long long &a) {
  a = 0;
  char c;
  bool neg = 0;
  while ((c = getchar()) != EOF && !isdigit(c) && c != '-')
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  do a = a * 10 + c - '0';
  while ((c = getchar()) != EOF && isdigit(c));
  if (neg) a *= -1;
  return;
}
long long n, m, k, arr[100005], psum[100005];
long long dp[100005];
int main() {
  getint(n);
  memset(dp, -1, sizeof(dp));
  for (long long i = 1; i <= n; ++i) getint(arr[i]);
  sort(arr + 1, arr + n + 1, greater<int>());
  for (long long i = 1; i <= n; ++i) psum[i] = psum[i - 1] + arr[i];
  dp[n] = dp[n - 1] = psum[n] - psum[1];
  getint(k);
  for (; k; k--) {
    getint(m);
    m = (((m) < (n)) ? (m) : (n));
    if (dp[m] == -1) {
      long long &ret = dp[m];
      ret = 0;
      long long kali = 0, cur = 1, ambil = 1, rg = 1;
      while (cur < n) {
        ambil = cur + rg - 1;
        ambil = (((ambil) < (n)) ? (ambil) : (n));
        ret += kali * (psum[ambil] - psum[cur - 1]);
        cur += rg;
        rg *= m;
        ++kali;
      }
    }
    printf("%I64d\n", dp[m]);
  }
  return 0;
}
