#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long adjx[] = {1, 0, -1, -1, 0, 1};
    long long adjy[] = {1, 1, 0, -1, -1, 0};
    long long c[6];
    for (long long i = 0; i < 6; i++) {
      scanf("%lld", &c[i]);
    }
    long long ans = 9e18;
    for (long long i = 0; i < 6; i++) {
      for (long long j = i + 1; j < 6; j++) {
        if (i + 3 == j) {
          continue;
        }
        bool swapped = false;
        if (adjx[i] == adjy[i]) {
          swap(i, j);
          swapped = true;
        }
        if (adjx[i] == 0) {
          long long costl = x / adjx[j];
          long long ly = costl * adjy[j];
          long long costr = (y - ly) / adjy[i];
          if (costl < 0 || costr < 0) {
            if (swapped) {
              swap(i, j);
            }
            continue;
          }
          ans = min(ans, c[j] * costl + c[i] * costr);
        } else {
          long long costl = y / adjy[j];
          long long lx = costl * adjx[j];
          long long costr = (x - lx) / adjx[i];
          if (costl < 0 || costr < 0) {
            if (swapped) {
              swap(i, j);
            }
            continue;
          }
          ans = min(ans, c[j] * costl + c[i] * costr);
        }
        if (swapped) {
          swap(i, j);
        }
      }
    }
    for (long long i = 0; i < 6; i++) {
      if (adjx[i] == 0) {
        if (x == 0 && y / adjy[i] >= 0) {
          ans = min(ans, y / adjy[i] * 1ll * c[i]);
        }
      } else if (adjy[i] == 0) {
        if (y == 0 && x / adjx[i] >= 0) {
          ans = min(ans, x / adjx[i] * 1ll * c[i]);
        }
      } else {
        if (x / adjx[i] == y / adjy[i] && x / adjx[i] >= 0) {
          ans = min(ans, x / adjx[i] * 1ll * c[i]);
        }
      }
    }
    printf("%lld\n", ans);
  }
}
