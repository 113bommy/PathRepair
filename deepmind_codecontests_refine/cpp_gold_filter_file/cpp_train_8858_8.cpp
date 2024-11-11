#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long read() {
  long long f = 1, sum = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    sum = (sum << 1) + (sum << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f * sum;
}
void write(long long re) {
  if (re > 9) write(re / 10);
  putchar(re % 10 + '0');
}
long long n, ans[N], b[N], a[N];
int main() {
  n = read();
  for (long long i = 1; i <= n - 1; i++) {
    long long x = read(), y = read();
    if (x > y) swap(x, y);
    a[i] = x;
    if (y != n) {
      puts("NO");
      return 0;
    }
  }
  a[n] = n;
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) {
    if (!b[a[i]]) {
      ans[i] = a[i];
      b[a[i]] = 1;
    } else {
      for (long long j = 1; j <= i - 1; j++) {
        if (!b[j]) {
          ans[i] = j;
          b[j] = 1;
          break;
        }
      }
      if (!ans[i]) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (long long i = 1; i <= n - 1; i++)
    printf("%lld %lld\n", ans[i], ans[i + 1]);
  return 0;
}
