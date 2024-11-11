#include <bits/stdc++.h>
int ans = 13;
long long pa, pb;
long long p[14];
inline void dfs(long long a, long long b, long long c, long long ra,
                long long rb, long long jw, int inc, int d) {
  if (inc >= ans) return;
  if (!a && !b && !c && !jw) {
    ans = inc;
    pa = ra;
    pb = rb;
    return;
  }
  if (!c) {
    long long s = a + b + jw;
    int k = 0;
    while (s) {
      s /= 10;
      k++;
    }
    dfs(0, 0, 0, a * p[d] + ra, b * p[d] + rb, 0, inc + k, d);
    return;
  }
  if ((a + b + jw) % 10 == c % 10)
    dfs(a / 10, b / 10, c / 10, a % 10 * p[d] + ra, b % 10 * p[d] + rb,
        (a % 10 + b % 10 + jw) / 10, inc, d + 1);
  else {
    dfs(a * 10 + (c + 10 - b % 10 - jw) % 10, b, c, ra, rb, jw, inc + 1, d);
    dfs(a, b * 10 + (c + 10 - a % 10 - jw) % 10, c, ra, rb, jw, inc + 1, d);
    dfs(a, b, c * 10 + (a + b + jw) % 10, ra, rb, jw, inc + 1, d);
  }
}
int main() {
  int i, j;
  long long a, b, c;
  scanf("%I64d+%I64d=%I64d", &a, &b, &c);
  p[0] = 1;
  for (i = 1; i <= 13; i++) p[i] = p[i - 1] * 10;
  dfs(a, b, c, 0, 0, 0, 0, 0);
  printf("%I64d+%I64d=%I64d", pa, pb, pa + pb);
  return 0;
}
