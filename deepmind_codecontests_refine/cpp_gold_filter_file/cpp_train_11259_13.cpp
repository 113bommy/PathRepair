#include <bits/stdc++.h>
const int maxn = 1e5 + 100;
int s[maxn], d[maxn];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; ++i) scanf("%d%d", s + i, d + i);
  int mn = 0x3f3f3f3f, pos = 0;
  for (int i = 1; i <= n; ++i) {
    if (t <= s[i]) {
      if (s[i] < mn) mn = s[i], pos = i;
      continue;
    }
    int k = (t - s[i]) / d[i];
    if ((t - s[i]) % d[i]) ++k;
    if (k * d[i] + s[i] <= mn) mn = k * d[i] + s[i], pos = i;
  }
  printf("%d\n", pos);
}
