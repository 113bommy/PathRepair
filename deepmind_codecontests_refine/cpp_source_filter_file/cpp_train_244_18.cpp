#include <bits/stdc++.h>
using namespace std;
long long a[5111], y, yy;
int lmax[5111], cnt[5111], llmax;
int N, i, j, k;
int main() {
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%I64d", &a[i]);
  for (llmax = 0, i = 1; i <= N; i++) {
    lmax[i] = 0;
    cnt[i] = 0;
    y = a[i];
    while ((y & 1) == 0) {
      y >>= 1;
      cnt[i]++;
    }
    for (j = i - 1; j >= 1; j--) {
      k = i - j;
      if (k >= cnt[i]) {
        if (a[j] % y == 0 && lmax[j] > lmax[i]) lmax[i] = lmax[j];
      } else {
        yy = y << (cnt[i] - k);
        if (a[j] % yy == 0 && ((a[j] / yy) & 1 == 1) && lmax[j] > lmax[i])
          lmax[i] = lmax[j];
      }
    }
    lmax[i]++;
    if (lmax[i] > llmax) llmax = lmax[i];
  }
  printf("%d\n", N - llmax);
  return 0;
}
