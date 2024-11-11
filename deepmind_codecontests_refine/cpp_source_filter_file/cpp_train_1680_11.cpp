#include <bits/stdc++.h>
using namespace std;
template <class _Tp>
_Tp gcd(_Tp a, _Tp b) {
  return (b == 0) ? (a) : (gcd(b, a % b));
}
const long long Inf = 1000000000000000000ll;
const int inf = 1000000000;
char buf[1 << 25], *p1 = buf, *p2 = buf;
inline int getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0, f = 0;
  char c = getc();
  while (!isdigit(c)) (c == '-') && (f = 1), c = getc();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getc();
  return f ? -x : x;
}
const int N = 505;
long long dp[N];
struct node {
  long long a, b, k;
} a[N];
bool cmp(node A, node B) { return A.b > B.b; }
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) {
    a[i].a = read();
    a[i].b = read();
    a[i].k = read();
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j; --j) {
      dp[j] = max(dp[j], dp[j] + a[i].a - a[i].b * a[i].k);
      if (j) dp[j] = max(dp[j], dp[j - 1] + a[i].a - a[i].b * (j - 1));
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    if (dp[i] > ans) ans = dp[i];
  printf("%lld\n", ans);
  return 0;
}
