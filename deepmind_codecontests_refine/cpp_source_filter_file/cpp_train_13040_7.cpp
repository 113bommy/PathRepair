#include <bits/stdc++.h>
using namespace std;
const long long N = 60;
long long t;
long long n;
long long a[N], b[N];
inline long long read() {
  long long ret = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch) && ch ^ '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) {
    ret = (ret << 1) + (ret << 3) + (ch ^ '0');
    ch = getchar();
  }
  return ret * f;
}
inline void print(long long Num) {
  if (Num < 0) {
    Num = -Num;
    putchar('-');
  }
  if (Num > 10) print(Num / 10);
  putchar(Num % 10 + '0');
  return;
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    long long Mina = 0x7fffffff;
    long long Minb = 0x7fffffff;
    long long ans = 0;
    for (register long long i = 1; i <= n; ++i)
      a[i] = read(), Mina = min(Mina, a[i]);
    for (long long i = 1; i <= n; ++i) b[i] = read(), Minb = min(Minb, b[i]);
    for (long long i = 1; i <= n; ++i) {
      ans += max(a[i] - Mina, b[i] - Minb);
    }
    print(ans);
    puts("");
  }
  return 0;
}
