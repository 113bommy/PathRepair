#include <bits/stdc++.h>
int n, k, c[500100];
int main() {
  while (scanf("%d%d", &n, &k) > 0) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &c[i]);
    }
    long long lo = 1, up = 2e9, val = 1;
    while (lo <= up) {
      long long mid = (lo + up) >> 1, cnt = 0;
      for (int i = 0; i < n; i++) {
        if (c[i] < mid) {
          cnt += mid - c[i];
        }
      }
      if (cnt <= k) {
        lo = mid + 1;
        val = mid;
      } else {
        up = mid - 1;
      }
    }
    int aux = k;
    for (int i = 0; i < n; i++) {
      if (c[i] < val) {
        aux -= val - c[i];
        c[i] = val;
      }
    }
    for (int i = 0; i < n and aux; i++) {
      if (c[i] == val) {
        c[i]++;
        aux--;
      }
    }
    lo = 1;
    up = 2e9;
    val = 2e9;
    while (lo <= up) {
      long long mid = (lo + up) >> 1, cnt = 0;
      for (int i = 0; i < n; i++) {
        if (c[i] > mid) {
          cnt += c[i] - mid;
        }
      }
      if (cnt <= k) {
        up = mid - 1;
        val = mid;
      } else {
        lo = mid + 1;
      }
    }
    aux = k;
    for (int i = 0; i < n; i++) {
      if (c[i] > val) {
        aux -= c[i] - val;
        c[i] = val;
      }
    }
    int p = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] == val and aux) {
        c[i]--;
        aux--;
      }
      if (c[i] < c[p]) p = i;
      if (c[i] > c[r]) r = i;
    }
    printf("%d\n", c[r] - c[p]);
  }
}
