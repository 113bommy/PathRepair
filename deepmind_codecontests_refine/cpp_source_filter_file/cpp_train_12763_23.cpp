#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int p[1000010];
int d[2000010];
int main() {
  int n, i, y = 0, z = 0, q = 0;
  long long s = 0, x = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    p[i] = a[i] - i;
    x += abs(p[i]);
    d[p[i] + n]++;
  }
  s = x;
  for (i = n + 1; i <= 2 * n; i++) q += d[i];
  for (i = 1; i < n; i++) {
    s += 2 * a[n - i + 1] - n;
    d[p[n - i + 1] + n]--;
    d[p[n - i + 1] + n + n]++;
    q++;
    s += n - q - q;
    if (s < x) {
      x = s;
      y = i;
    }
    q -= d[n + i];
  }
  printf("%I64d %d\n", x, y);
  return 0;
}
