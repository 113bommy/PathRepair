#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int L = n / 100000;
  int R = n % 100000;
  int ans = 0;
  if (L == 0) {
    for (int i = 1; i <= R; ++i) {
      int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, c = 0;
      for (int j = i; j > 0; j /= 10) {
        int d = j % 10;
        if (h[d] == 0) {
          ++h[d], ++c;
          if (c > 2) break;
        }
      }
      if (c <= 2) ++ans;
    }
  } else {
    for (int i = 1; i < 100000; ++i) {
      int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, c = 0;
      for (int j = i; j > 0; j /= 10) {
        int d = j % 10;
        if (h[d] == 0) {
          ++h[d], ++c;
          if (c > 2) break;
        }
      }
      if (c <= 2) ++ans;
    }
    for (int i = 1; i < L; ++i) {
      int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, c = 0;
      for (int j = i; j > 0; j /= 10) {
        int d = j % 10;
        if (h[d] == 0) {
          ++h[d], ++c;
          if (c > 2) break;
        }
      }
      if (c == 1)
        ans += 9 * ((1 << 5) - 1) + 1;
      else if (c == 2)
        ans += 1 << 5;
    }
    for (int i = L; i <= L; ++i) {
      int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, c = 0;
      for (int j = i; j > 0; j /= 10) {
        int d = j % 10;
        if (h[d] == 0) {
          ++h[d], ++c;
          if (c > 2) break;
        }
      }
      if (c <= 2) {
        for (int i = 1; i <= R; ++i) {
          int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, c = 0;
          for (int j = i + L * 100000; j > 0; j /= 10) {
            int d = j % 10;
            if (h[d] == 0) {
              ++h[d], ++c;
              if (c > 2) break;
            }
          }
          if (c <= 2) ++ans;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
