#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
long long a, b, c, d, n, x[30], s = 1;
char ans[105][105], ch = 'a';
signed main() {
  a = read(), b = read(), c = read(), d = read(), n = read();
  for (long long i = 1; i <= n; i++) x[i] = read();
  if (b > d) {
    for (long long i = d + 1; i <= b; i++)
      for (long long j = a + 1; j <= a + c; j++) ans[i][j] = '.';
  } else {
    for (long long i = b + 1; i <= d; i++)
      for (long long j = 1; j <= a; j++) ans[i][j] = '.';
  }
  bool f = 0;
  for (long long i = d; i >= 1; i--) {
    if (!f) {
      for (long long j = a + 1; j <= a + c; j++) {
        ans[i][j] = ch;
        x[s]--;
        if (!x[s]) s++, ch++;
      }
      f ^= 1;
    } else {
      for (long long j = a + c; j > a; j--) {
        ans[i][j] = ch;
        x[s]--;
        if (!x[s]) s++, ch++;
      }
      f ^= 1;
    }
  }
  if (ans[1][a + 1] < ans[1][c]) reverse(ans[1] + a + 1, ans[1] + a + c + 1);
  f = 0;
  for (long long i = 1; i <= b; i++) {
    if (!f) {
      for (long long j = a; j >= 1; j--) {
        ans[i][j] = ch;
        x[s]--;
        if (!x[s]) s++, ch++;
      }
      f ^= 1;
    } else {
      for (long long j = 1; j <= a; j++) {
        ans[i][j] = ch;
        x[s]--;
        if (!x[s]) s++, ch++;
      }
      f ^= 1;
    }
  }
  puts("YES");
  for (long long i = 1; i <= max(b, d); i++) printf("%s\n", ans[i] + 1);
  return 0;
}
