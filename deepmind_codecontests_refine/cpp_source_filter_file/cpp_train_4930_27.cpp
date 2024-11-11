#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 500 + 5, inf = 0x3f3f3f3f, P = 19650827;
long long n, m, a[N], l[N], r[N], c1[N], c2[N];
double ans[N];
template <class t>
void rd(t &x) {
  x = 0;
  int w = 0;
  char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
}
int main() {
  rd(n);
  for (int i = 1; i <= n; ++i) rd(a[i]);
  a[0] = a[n + 1] = -10000010;
  for (int i = n; i; --i) {
    if (a[i + 1] < a[i])
      r[i] = i + 1;
    else
      for (int j = r[i + 1]; j <= n + 1; j = r[j])
        if (a[j] < a[i]) {
          r[i] = j;
          break;
        }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] <= a[i])
      l[i] = i - 1;
    else
      for (int j = l[i + 1]; j >= 0; j = l[j])
        if (a[j] < a[i]) {
          l[i] = j;
          break;
        }
  }
  for (int i = 1; i <= n; ++i) l[i] = i - l[i], r[i] = r[i] - i;
  for (int i = 1, x, y; i <= n; ++i) {
    x = l[i], y = r[i];
    if (x > y) swap(x, y);
    c1[1] += a[i], c1[x + 1] -= a[i];
    c2[x + 1] += a[i] * x, c2[y + 1] -= a[i] * x;
    c2[y + 1] += a[i] * (x + y), c2[x + y] -= a[i] * (x + y);
    c1[x + y] += a[i], c1[y + 1] -= a[i];
  }
  long long C1 = 0, C2 = 0;
  for (int i = 1; i <= n; ++i) {
    C1 += c1[i], C2 += c2[i];
    ans[i] = (double)((C1 * i) + C2) / (double)(n - i + 1);
  }
  rd(m);
  for (int i = 1, x; i <= m; ++i) rd(x), printf("%.9lf\n", ans[x]);
  return 0;
}
