#include <bits/stdc++.h>
using namespace std;
template <class _Tp>
_Tp gcd(_Tp a, _Tp b) {
  return (b == 0) ? (a) : (gcd(b, a % b));
}
const int inf = 1000000000;
const long long Inf = 1000000000000000000ll;
char buf[1 << 23], *p1 = buf, *p2 = buf;
int getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 23, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0, f = 0;
  char c = getc();
  while (!isdigit(c)) (c == '-') && (f = 1), c = getc();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getc();
  return f ? -x : x;
}
const int K = 105;
const int N = 100005;
int n, k, l[K], r[K], dp[N], lst[N], q[N];
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= k; ++i) {
    l[i] = read();
    r[i] = read();
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= k; ++i) {
    memcpy(lst, dp, sizeof(dp));
    int L = 1, R = 0;
    for (int j = r[i]; j >= 0; --j) {
      while (L <= R && lst[q[R]] >= lst[r[i] - j]) R--;
      q[++R] = r[i] - j;
      while (L <= R && q[L] < l[i] - j) ++L;
      dp[j] = min(dp[j], lst[q[L]] + 1);
    }
    L = 1, R = 0;
    for (int j = 0; j <= r[i]; ++j) {
      while (L <= R && lst[q[R]] >= lst[j]) R--;
      q[++R] = j;
      while (L <= R && q[L] < j + l[i] - r[i]) ++L;
      dp[j] = min(dp[j], lst[q[L]] + 2);
    }
  }
  if (dp[n] == 0x3f3f3f3f) {
    puts("Hungry");
    return 0;
  }
  printf("Full\n%d\n", dp[n]);
  return 0;
}
