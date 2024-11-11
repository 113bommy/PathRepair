#include <bits/stdc++.h>
using std::min;
const int N = 4e5 + 7;
const long long INF = 1e17;
int n;
long long X, Y;
char s[N];
inline int read() {
  int now = 0;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); now = now * 10 + c - '0', c = getchar())
    ;
  return now;
}
int main() {
  n = read(), X = read(), Y = read(), scanf("%s", s + 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (s[i] == '0') ++cnt;
  if (!cnt) return putchar('0'), 0;
  if (cnt == n) return printf("%I64d", Y), 0;
  long long zero = 0, one = 0;
  if (s[1] == '0')
    ++zero;
  else
    ++one;
  for (int i = 2; i <= n; ++i)
    if (s[i] == '1' && s[i - 1] == '0')
      ++zero;
    else if (s[i] == '0' && s[i - 1] == '1')
      ++one;
  printf("%I64d",
         min((zero - 1ll) * X + Y,
             min(zero * Y, min((one - 1ll) * X + 2ll * Y, one * Y + Y))));
  return 0;
}
