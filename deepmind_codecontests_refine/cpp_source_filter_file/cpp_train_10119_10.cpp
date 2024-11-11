#include <bits/stdc++.h>
using namespace std;
long long d, n, a, b, mak, minim, t, sel, selmak, tes[10][10], num, ang[10];
int main() {
  memset(tes, 0, sizeof(tes));
  scanf("%I64d %I64d", &d, &n);
  for (a = 0; a < n; a++) ang[a] = a + 1;
  for (a = 0; a < d; a++) {
    scanf("%I64d", &num);
    for (b = n - 1; b >= 0; b--) {
      tes[a][b] = num % 10;
      num /= 10;
    }
  }
  selmak = 1000000;
  do {
    mak = 0;
    minim = 100000000;
    for (a = 0; a < d; a++) {
      t = 0;
      for (int i = 0; i < n; i++) t = (t * 10) + tes[a][ang[i] - 1];
      if (t > mak) mak = t;
      if (t < minim) minim = t;
    }
    sel = mak - minim;
    if (sel < selmak) selmak = sel;
  } while (next_permutation(ang, ang + n));
  printf("%I64d\n", selmak);
  cin >> a;
  return 0;
}
