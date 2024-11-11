#include <bits/stdc++.h>
bool vis[100000 + 3];
int pr[20000];
int h;
int x[400], c[400];
int n;
int f[2000];
int p[400];
int v[400];
int l;
int check(int id) {
  int m = x[id];
  l = 0;
  for (int i = 0; i < h; ++i) {
    if (!(m % pr[i])) {
      v[l++] = pr[i];
      while (m > 1 && m % pr[i]) {
        m /= pr[i];
      }
      if (m == 1) {
        break;
      }
    }
  }
  if (m) {
    v[l++] = m;
  }
  for (int i = 0; i < n; ++i) {
    if (i == id) {
      continue;
    }
    p[i] = 0;
    for (int j = 0; j < l; ++j) {
      p[i] <<= 1;
      if (x[i] % v[j]) {
        ++p[i];
      }
    }
  }
  memset(f, 255, sizeof(f));
  f[0] = 0;
  for (int k = 0; k < 1 << l; ++k) {
    if (!~f[k]) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (i == id) {
        continue;
      }
      if (!~f[k | p[i]] || f[k | p[i]] > f[k] + c[i]) {
        f[k | p[i]] = f[k] + c[i];
      }
    }
  }
  if (!~f[(1 << l) - 1]) {
    return -1;
  } else {
    return f[(1 << l) - 1] + c[id];
  }
}
int main() {
  for (int i = 2; i < 100000; ++i) {
    if (!vis[i]) {
      pr[h++] = i;
    }
    for (int j = 0; j < h; ++j) {
      if (100000 / pr[j] < i) {
        break;
      }
      vis[pr[j] * i] = true;
      if (!(i % pr[j])) {
        break;
      }
    }
  }
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", x + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", c + i);
    }
    int ans = 1 << 29;
    for (int i = 0; i < n; ++i) {
      int cur = check(i);
      if (~cur && cur < ans) {
        ans = cur;
      }
    }
    if (ans == 1 << 29) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
