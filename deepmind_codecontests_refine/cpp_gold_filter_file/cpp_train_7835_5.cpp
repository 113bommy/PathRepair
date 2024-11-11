#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int ny2 = (MOD + 1) / 2;
const int N = 2000005;
const long double pi = acos(-1);
const long double e = exp(1);
const long double eps = 1e-8;
int a[N];
int read() {
  int x = 0, v = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; v = (ch == '-') ? (-1) : v, ch = getchar())
    ;
  for (; ch <= '9' && ch >= '0'; x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * v;
}
int main(void) {
  for (int T = read(); T--;) {
    int n = read(), s = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      s += a[i];
    }
    std::sort(a + 1, a + n + 1);
    puts(s != 0 ? "YES" : "NO");
    if (s != 0) {
      if (s > 0)
        for (int i = n; i >= 1; --i) printf("%d ", a[i]);
      else
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
      puts("");
    }
  }
  return 0;
}
