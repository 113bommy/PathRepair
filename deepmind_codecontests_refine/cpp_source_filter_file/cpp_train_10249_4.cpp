#include <bits/stdc++.h>
using namespace std;
int n, s, i, j, k, a, b, w, l1, l2, c, rt, lw;
double v[109][109], t[109][109], tp, tc, p1, p2, t1, t2;
int main() {
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) cin >> v[i][j] >> t[i][j];
    t[i][k] = 999999.0;
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      p1 = p2 = 0.0;
      w = lw = 0;
      t1 = t[i][0];
      t2 = t[j][0];
      for (l1 = l2 = 0;;) {
        a = b = 0;
        if (t1 > t2) {
          tc = t2;
          b = 1;
        } else {
          if (t1 < t2) {
            tc = t1;
            a = 1;
          } else {
            tc = t1;
            a = b = 1;
          }
        }
        t1 -= tc;
        t2 -= tc;
        p1 += v[i][l1] * tc;
        p2 += v[j][l2] * tc;
        if (w == 0) {
          if (p1 > p2) {
            w = 1;
            if (lw == 2) c++;
          }
          if (p1 < p2) {
            w = 2;
            if (lw == 1) c++;
          }
        } else {
          if (w == 1) {
            if (p1 < p2) {
              c++;
              w = 2;
            }
            if (p1 == p2) lw = 1, w = 0;
          } else {
            if (p1 > p2) {
              c++;
              w = 1;
            }
            if (p1 == p2) lw = 2, w = 0;
          }
        }
        if (a == 1) {
          l1++;
          t1 = t[i][l1];
        }
        if (b == 1) {
          l2++;
          t2 = t[j][l2];
        }
        if (p1 >= s && p2 >= s) break;
      }
      rt += c;
    }
  }
  cout << rt;
}
