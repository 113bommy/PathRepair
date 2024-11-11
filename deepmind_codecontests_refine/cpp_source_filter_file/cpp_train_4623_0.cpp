#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, sgn = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * sgn;
}
const int N = 3e5 + 10;
int x[N], y[N], a[N], b[N], n;
long long ans;
bool fl1, fl2, fl3;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) x[i] = a[i] = read(), y[i] = b[i] = read();
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int mid = n + 1 >> 1;
  int dx = a[mid + 1] - a[mid], dy = b[mid + 1] - b[mid];
  if (n & 1)
    dx = min(dx, a[mid] - a[mid - 1]), dy = min(dy, b[mid] - b[mid - 1]);
  for (int i = 1; i <= n; i++)
    ans += (long long)abs(x[i] - a[mid]) + abs(y[i] - b[mid]);
  for (int i = 1; i <= n; i++) {
    if (x[i] == a[mid] && y[i] == b[mid]) fl1 = 1;
    if (x[i] > a[mid] && y[i] <= b[mid]) fl2 = 1;
    if (x[i] > a[mid] && y[i] >= b[mid]) fl3 = 1;
  }
  if (((n % 2 == 0) || fl1) && fl2 && fl3) ans = ans - min(dx, dy);
  ans <<= 1;
  printf("%lld\n", ans);
  return 0;
}
