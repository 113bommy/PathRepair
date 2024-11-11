#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar())
    sum = ((sum << 1) + (sum << 3) + (ch ^ 48));
  return f ? -sum : sum;
}
void write(const long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long inf = 99824435312345;
long long n, a[1100000], ans = inf;
int main() {
  n = read();
  for (register long long i = (1); i <= (n); i++) a[i] = read();
  for (register long long i = (1); i <= (n); i++)
    for (register long long j = (i + 1); j <= (n); j++) {
      long long lft = a[i] - 1, sum1 = 1, sum2 = 0;
      for (register long long k = (i + 1); k <= (j); k++)
        sum1 += lft / a[k], lft %= a[k];
      long long tmp = lft = a[i] - 1 - lft + a[j];
      if (tmp == a[i]) continue;
      for (register long long k = (1); k <= (n); k++)
        sum2 += lft / a[k], lft %= a[k];
      if (sum1 < sum2) ans = min(ans, tmp);
    }
  write(ans == inf ? -1 : ans);
}
