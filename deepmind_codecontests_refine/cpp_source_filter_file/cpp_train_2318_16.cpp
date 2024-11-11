#include <bits/stdc++.h>
int read() {
  static int c, x;
  while ((c = getchar()) < 48) {
  }
  x = c & 15;
  while ((c = getchar()) >= 48) x = x * 10 + (c & 15);
  return x;
}
int readalpha() {
  static int c;
  while ((c = getchar()) < 48) {
  }
  return c;
}
const int K = 20;
bool s[K], t[K];
int per[K];
int mn[1 << K], mx[1 << K];
int main() {
  const int n = read(), m = read(), k = read();
  memset(mn, 0x3f, sizeof mn);
  memset(mx, 0xc0, sizeof mx);
  int tot = k, vs = 0, vt = 0, ans = -1, pos = 0;
  for (int i = 0; i != k; ++i) {
    per[i] = i;
    if (readalpha() & 1) {
      s[i] = true;
      vs |= 1 << i;
      --tot;
    }
  }
  for (int i = 0; i != k; ++i) {
    if (readalpha() & 1) {
      t[i] = true;
      vt |= 1 << i;
      --tot;
    }
  }
  mn[vs] = 0;
  mx[vt] = 0;
  for (int i = 1; i <= n; ++i) {
    const int x = read() - 1, y = read() - 1;
    std::swap(per[x], per[y]);
    vs = 0;
    vt = 0;
    for (int j = 0; j != k; ++j) {
      vs |= s[j] << per[j];
      vt |= t[j] << per[j];
    }
    mn[vs] = std::min(mn[vs], i);
    mx[vt] = std::max(mx[vt], i);
  }
  for (int i = 1 << k; i--;) {
    int c = 0;
    for (int j = 0; j != k; ++j) {
      if (i >> j & 1) {
        ++c;
      } else {
        mx[i] = std::max(mx[i], mx[i | 1 << j]);
        mn[i] = std::min(mn[i], mn[i | 1 << j]);
      }
    }
    if (mx[i] - mn[i] > m && c > ans) {
      ans = c;
      pos = i;
    }
  }
  ans = (ans << 1) + tot;
  printf("%d\n%d %d\n", ans, mn[pos] + 1, mx[pos]);
  return 0;
}
