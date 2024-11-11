#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000,1000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
char s[1000005];
unsigned long long n, hs[1000005], p[1000005];
inline bool f(long long x) {
  unsigned long long now = hs[x] * p[1000004],
                     end = (hs[n] - hs[n - x]) * p[1000004 - (n - x)];
  if (now != end) return false;
  long long cnt = 0;
  for (long long i = x; i <= n; i++)
    if ((hs[i] - hs[i - x]) * p[1000004 - (i - x)] == now) cnt++;
  return cnt >= 3;
}
unsigned long long a[1000005], sz = 0;
int main(void) {
  gets(s + 1);
  n = strlen(s + 1);
  p[0] = 1;
  for (long long i = 1; i <= 1000004; i++) p[i] = p[i - 1] * 29LL;
  for (long long i = 1; i <= n; i++)
    hs[i] = hs[i - 1] + (s[i] - 'a' + 1) * p[i];
  for (long long i = 1; i <= n; i++) {
    unsigned long long now = hs[i] * p[1000004],
                       end = (hs[n] - hs[n - i]) * p[1000004 - (n - i)];
    if (now == end) a[sz++] = i;
  }
  long long l = -1, r = sz + 1;
  while (r - l > 1) {
    long long m = (l + r) >> 1LL;
    if (f(a[m]))
      l = m;
    else
      r = m;
  }
  if (l == -1) {
    puts("Just a legend");
    exit(0);
  }
  for (long long i = 1; i <= a[l]; i++) putchar(s[i]);
  printf("\n");
  return 0;
}
