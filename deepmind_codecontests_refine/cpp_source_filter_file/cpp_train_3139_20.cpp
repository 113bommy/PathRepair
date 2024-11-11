#include <bits/stdc++.h>
using namespace std;
const int mod = 123456789;
const int maxn = 1e5 + 5;
void read(int &a) {
  a = 0;
  int d = 1;
  char ch;
  while (ch = getchar(), ch > '9' || ch < '0')
    if (ch == '-') d = -1;
  a = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') a = a * 10 + ch - '0';
  a *= d;
}
void write(int x) {
  if (x < 0) putchar(45), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long a[2 * maxn], minx = 0x3fffffff;
int main() {
  long long H;
  int u, n;
  long long sum = 0;
  scanf("%lld", &H);
  read(n);
  for (register int i = 1; i <= n; i++) {
    int x;
    read(x);
    a[i] = a[i - 1] + x;
    if (minx > a[i]) {
      minx = a[i];
      u = i;
    }
  }
  if (minx >= 0 || ((H - minx) > 0 && a[n] >= 0)) return puts("-1"), 0;
  long long k = 0;
  if (H + minx <= 0) {
    for (register int i = 1; i <= n; i++)
      if (H + a[i] <= 0) {
        write(i);
        putchar('\n');
        return 0;
      }
  }
  k = H / abs(a[n]);
  k -= abs(minx) / abs(a[n]);
  H += k * a[n];
  while (H + minx > 0) {
    k++;
    H += a[n];
  }
  long long ans = k * n;
  for (register int i = 1; i <= n; i++)
    if (H + a[i] <= 0) {
      printf("%lld\n", ans + i);
      break;
    }
  return 0;
}
