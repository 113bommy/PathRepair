#include <bits/stdc++.h>
using namespace std;
int d, e, i, k, l, c, m, a[100], b[100], f, j, t, q, z, p, m1, m2, m3, m4;
int main(int argc, char *argv[]) {
  cin >> d >> e;
  while (e > 0) {
    c = e % 10;
    m++;
    b[m] = c;
    e = e / 10;
  }
  for (i = 1; i <= m; i++) {
    if (b[i] == 4) m1++;
    if (b[i] == 7) m2++;
  }
  for (i = d + 1; i <= 1000000; i++) {
    k = i;
    l = 0;
    q = 1;
    m3 = m4 = 0;
    memset(a, 0, sizeof(a));
    while (k > 0) {
      c = k % 10;
      l++;
      a[l] = c;
      k = k / 10;
    }
    for (j = 1; j <= l; j++) {
      if (a[j] == 4) m3++;
      if (a[j] == 7) m4++;
    }
    if (m1 == m3 && m2 == m4) {
      for (j = 1; j <= m; j++) {
        p = 0;
        for (z = q; z <= l; z++) {
          if (b[j] == a[z]) {
            p = 1;
            q = q + z;
            break;
          }
        }
        if (p == 0) break;
      }
    }
    if (p == 1) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
