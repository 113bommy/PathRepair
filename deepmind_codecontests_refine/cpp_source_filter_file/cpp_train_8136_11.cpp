#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-7;
const double pi = acos(-1.0);
const int maxx = 100010;
const int mod = int(1e9 + 7);
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
    ;
}
inline void readll(long long int &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
    ;
}
inline void reads(char *s) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  s[0] = ch;
  for (int i = 1; (!blank(ch = nc())); ++i) {
    s[i] = ch;
  }
}
};  // namespace fastIO
long long a[maxx], b[maxx];
long long dp[3][maxx];
int main() {
  long long n;
  fastIO::readll(n);
  for (int i = 0; i < n; ++i) {
    fastIO::readll(a[i]);
  }
  for (int i = 0; i < n; ++i) {
    fastIO::readll(b[i]);
  }
  dp[0][n - 1] = 0;
  dp[1][n - 1] = a[n - 1];
  dp[2][n - 1] = b[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    dp[0][i] = dp[2][0];
    for (int j = 0; j < 2; ++j) {
      dp[0][i] = dp[0][i] > dp[j][i + 1] ? dp[0][i] : dp[j][i + 1];
    }
    dp[1][i] =
        (dp[0][i + 1] > dp[2][i + 1] ? dp[0][i + 1] : dp[2][i + 1]) + a[i];
    dp[2][i] =
        (dp[0][i + 1] > dp[1][i + 1] ? dp[0][i + 1] : dp[1][i + 1]) + b[i];
  }
  long long ans = dp[2][0];
  for (int i = 0; i < 2; ++i) {
    ans = ans > dp[i][0] ? ans : dp[i][0];
  }
  printf("%lld\n", ans);
  return 0;
}
