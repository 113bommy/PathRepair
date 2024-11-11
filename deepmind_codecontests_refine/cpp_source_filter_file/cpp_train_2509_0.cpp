#include <bits/stdc++.h>
using namespace std;
int sw[400010], b[400010], dap[200010], cnt, n, m, a[200010], str[400010],
    plen[400010], w;
void manacher() {
  int r = -1, p = -1;
  for (int i = 0; i < w; ++i) {
    if (i <= r)
      plen[i] = min((2 * p - i >= 0) ? plen[2 * p - i] : 0, r - i);
    else
      plen[i] = 0;
    while (i - plen[i] - 1 >= 0 && i + plen[i] + 1 < w &&
           str[i - plen[i] - 1] == str[i + plen[i] + 1]) {
      plen[i] += 1;
    }
    if (i + plen[i] > r) {
      r = i + plen[i];
      p = i;
    }
  }
}
int main() {
  int i;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = n; i < n * 2; i++) a[i] = a[i - n] + m;
  for (i = 0; i <= n * 2 - 2; i++) b[i] = a[i + 1] - a[i];
  for (i = 0; i <= n * 2 - 2; i++) {
    str[w++] = b[i];
    str[w++] = -1;
  }
  str[--w] = 0;
  manacher();
  for (i = 0; i <= w / 2; i++) {
    if (plen[i] != i) sw[(i + 1) % n] = 1;
  }
  for (i = 0; i < n; i++) {
    if (sw[i] == 0) dap[++cnt] = (a[i] + a[0]) % m;
  }
  sort(dap + 1, dap + cnt + 1);
  printf("%d\n", cnt);
  for (i = 1; i <= cnt; i++) printf("%d ", dap[i]);
  return 0;
}
