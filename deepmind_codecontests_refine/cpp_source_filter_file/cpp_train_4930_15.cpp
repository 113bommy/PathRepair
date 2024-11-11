#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
inline long long read() {
  long long x = 0, flag = 1;
  char v = getchar();
  while (!(v >= '0' && v <= '9')) {
    if (v == '-') flag = -1;
    v = getchar();
  }
  while ((v >= '0' && v <= '9')) {
    x = (x << 1) + (x << 3) + v - '0';
    v = getchar();
  }
  return x * flag;
}
long long n, m, k, l[maxn], r[maxn], h[maxn], x, y;
long long c1[maxn], c2[maxn], sum1, sum2;
double ans[maxn];
int main() {
  n = read();
  h[0] = h[n + 1] = -((long long)1 << 60);
  for (int i = 1; i <= n; i++) h[i] = read();
  for (int i = n; i >= 0; i--) {
    if (h[i + 1] <= h[i])
      r[i] = i + 1;
    else
      for (int j = r[i + 1]; j <= n; j = r[j])
        if (h[j] <= h[i]) {
          r[i] = j;
          break;
        }
  }
  for (int i = 1; i <= n; i++) {
    if (h[i - 1] < h[i])
      l[i] = i - 1;
    else
      for (int j = l[i - 1]; j >= 0; j = l[j])
        if (h[j] < h[i]) {
          l[i] = j;
          break;
        }
  }
  for (int i = 1; i <= n; i++) l[i] = i - l[i], r[i] = r[i] - i;
  for (int i = 1; i <= n; i++) {
    x = l[i], y = r[i];
    if (x > y) swap(x, y);
    c1[1] += h[i], c1[x + 1] -= h[i];
    c1[y + 1] -= h[i], c1[x + y] += h[i];
    c2[x + 1] += h[i] * x, c2[y + 1] -= h[i] * x;
    c2[y + 1] += h[i] * (x + y), c2[x + y] -= h[i] * (x + y);
  }
  for (int i = 1; i <= n; i++) {
    sum1 += c1[i];
    sum2 += c2[i];
    ans[i] = ((sum1 * i + sum2) * 1.0) / ((n - i + 1) * 1.0);
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    k = read();
    printf("%.9lf\n", ans[k]);
  }
  return 0;
}
