#include <bits/stdc++.h>
using namespace std;
int n, s, i, j, k, a, b, w, l1, l2, c, lw, v[109][109], t[109][109], tl, tc, p1,
    p2, t1, t2, d1, d2;
int main() {
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      cin >> v[i][j] >> t[i][j];
      if (j > 0) t[i][j] += t[i][j - 1];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      p1 = p2 = l1 = l2 = tl = 0;
      for (; p1 < s && p2 < s;) {
        if (t[i][l1] <= t[j][l2])
          tc = t[i][l1] - tl;
        else
          tc = t[j][l2] - tl;
        d1 = p1;
        d2 = p2;
        p1 += v[i][l1] * tc;
        p2 += v[j][l2] * tc;
        if (d1 != 0 && d1 < d2 && p1 >= p2)
          if (p1 != p2 || p1 != s) c++;
        if (d2 != 0 && d1 > d2 && p1 <= p2)
          if (p1 != p2 || p1 != s) c++;
        if (t[i][l1] < t[j][l2]) {
          tl = t[i][l1];
          l1++;
        } else {
          if (t[j][l2] < t[i][l1]) {
            tl = t[j][l2];
            l2++;
          } else {
            tl = t[j][l2];
            l1++;
            l2++;
          }
        }
      }
    }
  }
  cout << c;
}
