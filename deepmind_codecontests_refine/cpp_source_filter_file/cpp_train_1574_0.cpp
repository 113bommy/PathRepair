#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, A, i, j, c, s;
  cin >> n >> k >> A;
  int b[10], l[10];
  for (i = 0; i < 10; ++i) l[i] = 100;
  for (i = 0; i < n; ++i) cin >> b[i] >> l[i];
  int m[10], p[10];
  memset(m, 0, sizeof(m));
  long double cur, res = 0.0, t, tmp;
  for (int i0 = 0; i0 <= k && l[0] + 10 * i0 <= 100; ++i0) {
    for (int i1 = 0; i0 + i1 <= k && l[1] + 10 * i1 <= 100; ++i1) {
      for (int i2 = 0; i0 + i1 + i2 <= k && l[2] + 10 * i2 <= 100; ++i2) {
        for (int i3 = 0; i0 + i1 + i2 + i3 <= k && l[3] + 10 * i3 <= 100;
             ++i3) {
          for (int i4 = 0; i0 + i1 + i2 + i3 + i4 <= k && l[4] + 10 * i4 <= 100;
               ++i4) {
            for (int i5 = 0;
                 i0 + i1 + i2 + i3 + i4 + i5 <= k && l[5] + 10 * i5 <= 100;
                 ++i5) {
              for (int i6 = 0; i0 + i1 + i2 + i3 + i4 + i5 + i6 <= k &&
                               l[6] + 10 * i6 <= 100;
                   ++i6) {
                for (int i7 = 0; i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 <= k &&
                                 l[7] + 10 * i7 <= 100;
                     ++i7) {
                  m[0] = i0;
                  m[1] = i1;
                  m[2] = i2;
                  m[3] = i3;
                  m[4] = i4;
                  m[5] = i5;
                  m[6] = i6;
                  m[7] = i7;
                  cur = 0.0;
                  memset(p, 0, sizeof(p));
                  p[0] = -1;
                  while (p[n] == 0) {
                    j = 0;
                    while (p[j] == 1) {
                      p[j] = 0;
                      ++j;
                    }
                    ++p[j];
                    if (j == n) break;
                    t = 1.0;
                    c = 0;
                    s = 0;
                    for (j = 0; j < n; ++j) {
                      if (p[j]) {
                        ++c;
                        t *= (l[j] + 10 * m[j]) * 0.01;
                      } else {
                        t *= (100 - l[j] - 10 * m[j]) * 0.01;
                        s += b[j];
                      }
                    }
                    if (2 * c > n)
                      cur += t;
                    else
                      cur += t * A / (A + s);
                  }
                  if (cur > res) res = cur;
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%.10llf", res);
  return 0;
}
