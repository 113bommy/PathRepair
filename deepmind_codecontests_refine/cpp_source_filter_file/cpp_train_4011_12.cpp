#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long a = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
  return a * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar((x % 10) ^ 48);
}
inline void writen(long long x) {
  write(x);
  puts("");
}
const long long mod = 1e9 + 7;
const long long N = 1e6 + 5;
const long long inf = 0x3f3f3f3f;
const long long INF = 2147483647;
const double PI = acos(-1);
long long x, s, sum, ans, cnt;
signed main() {
  s = read();
  x = read();
  sum = (s - x) >> 1;
  if (x > s || sum * 2 + x != s || (x & sum) != 0) return puts("0"), 0;
  for (; x; x >>= 1)
    if (x & 1) cnt++;
  ans = 1 << cnt;
  if (!sum) ans -= 2;
  writen(ans);
  return 0;
}
