#include <bits/stdc++.h>
using namespace std;
long long x, y, z, i, j, n, m, k, s1, s2, s3, s4, mod, l, r, N, t, maxx, minn;
double w, v, q, h, hh, ww1, ww2;
long long a[245][245];
int main() {
  scanf("%lld", &n);
  x = 1;
  for (i = 2; i <= 200; i++) {
    x += i;
    if (x == n) {
      k = i + 1;
      break;
    }
    if (x > n) {
      k = i;
      break;
    }
  }
  printf("%lld\n", k);
  x = 1;
  y = 1;
  for (l = 1; l < k; l++) {
    for (i = l; i < k; i++) {
      a[l][i] = x;
      x++;
    }
    for (i = l + 1; i <= k; i++) {
      a[i][l] = y;
      y++;
    }
  }
  for (i = 1; i <= k; i++) {
    for (j = 1; j < k; j++) {
      printf("%lld ", a[i][j]);
    }
    printf("\n");
  }
}
