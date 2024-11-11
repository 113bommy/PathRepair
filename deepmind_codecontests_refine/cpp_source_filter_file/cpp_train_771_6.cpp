#include <bits/stdc++.h>
using namespace std;
const int M = 2 * 1e5 + 10;
int a[M];
int main() {
  long long s, n, p1, c, pos1, pos2, p2, i, ans = 1, d, x, j;
  scanf("%I64d", &n);
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  if (a[0] != -1) {
    p1 = a[0];
    pos1 = 0;
    c = 1;
  } else
    c = 0;
  s = 0;
  ans = 1;
  for (i = 1; i < n; i++) {
    if (i == 10) i = 10;
    if (c == 0) {
      if (a[i] != -1) {
        c = 1;
        p1 = a[i];
        pos1 = i;
      }
      continue;
    }
    if (c == 1) {
      if (a[i] != -1) {
        if ((a[i] - p1) % (i - pos1) != 0) {
          ans++;
          s = i;
          c = 1;
          p1 = a[i];
          pos1 = i;
        } else {
          c = 2;
          p2 = a[i];
          pos2 = i;
          d = (p2 - p1) / (pos2 - pos1);
          x = p1 + d * (s - pos1);
          if (s <= 0) {
            ans++;
            c = 1;
            p1 = a[i];
            pos1 = i;
            s = i;
          }
        }
      }
      continue;
    }
    d = (p2 - p1) / (pos2 - pos1);
    x = p1 + d * (i - pos1);
    if (a[i] == -1) {
      if (x <= 0) {
        ans++;
        c = 0;
        s = i;
      }
      continue;
    } else {
      if (x != a[i]) {
        ans++;
        s = i;
        c = 1;
        p1 = a[i];
        pos1 = i;
      }
    }
  }
  printf("%I64d", ans);
  return 0;
}
