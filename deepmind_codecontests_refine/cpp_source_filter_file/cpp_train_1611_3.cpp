#include <bits/stdc++.h>
const int mod = 1e9 + 7;
long long a, b, c, Ans[114514], cnt[114514];
inline long long read() {
  long long s = 0, f = 1;
  char ch;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    s = (s << 1) + (s << 3) + ch - '0';
  return s * f;
}
int ans, re;
inline void solve(int dep, long long x, long long y) {
  if (!x || !y) return;
  if (x == y) {
    cnt[ans = dep] = x;
    for (int i = 0; i <= dep; ++i) Ans[i] = cnt[i];
    ++re;
  }
  long long c = y % b;
  cnt[dep] = c;
  if (c % a != x % a) return;
  solve(dep + 1, (x - c) / a, (y - c) / b);
}
int main() {
  a = read(), b = read(), c = read();
  if (a == b && b == c) {
    if (a == 1)
      puts("-1");
    else
      puts("2");
    return 0;
  }
  if (a == b) {
    puts("0");
    return 0;
  }
  if (b == c) {
    puts("1");
    return 0;
  }
  re = 0;
  solve(0, b, c);
  printf("%d\n", re);
  return 0;
}
