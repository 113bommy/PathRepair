#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int L[200010], R[200010], a[200010], b[1010], s[200010], f[200010];
int sum(int l, int r) { return s[r] - s[l - 1]; }
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= m; ++i) s[b[i] = read()]++;
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  for (int i = 1; i <= 200000; ++i) s[i] += s[i - 1];
  a[0] = a[n + 1] = -1;
  for (int i = 1; i <= n; ++i) L[i] = (a[i - 1] + 1 == a[i]) ? L[i - 1] : i;
  for (int i = n; i >= 1; --i) R[i] = (a[i] + 1 == a[i + 1]) ? R[i + 1] : i;
  for (int i = 1; i <= n; ++i) {
    f[i] = max(f[i], f[i - 1]);
    int pre_max = -1e9;
    if (L[i] == i) f[i] = max(f[i], pre_max = f[i - 1] + sum(a[i], a[i]));
    for (int j = 1; b[j] <= a[i] && j <= m; ++j)
      if (i - a[i] + b[j] > 0) {
        int tmp = f[L[i - a[i] + b[j]] - 1] + sum(b[j], a[i]);
        f[i] = max(f[i], tmp), pre_max = max(pre_max, tmp);
      }
    for (int j = m; b[j] >= a[i] && j; --j)
      if (i - a[i] + b[j] <= n)
        f[R[i - a[i] + b[j]]] =
            max(f[R[i - a[i] + b[j]]], pre_max + sum(a[i] + 1, b[j]));
  }
  printf("%d\n", f[n]);
  return 0;
}
