#include <bits/stdc++.h>
using namespace std;
int a[100000], s[100000], d[100000];
void qs(int q, int w) {
  int e = q, r = w, y = q + (rand() % (w - q + 1)), t = a[d[y]], t1 = s[d[y]];
  do {
    while ((a[d[e]] < t) || ((a[d[e]] == t) && (s[d[e]] > t1))) e++;
    while ((a[d[r]] > t) || ((a[d[r]] == t) && (s[d[r]] < t1))) r--;
    if (e <= r) {
      y = d[e];
      d[e] = d[r];
      d[r] = y;
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs(q, r);
  if (e < w) qs(e, w);
}
int main() {
  int q, w, e, r, t, y, v, s1[100000], s2[100000];
  long long c, *a1 = new long long[100000], a2[100000];
  c = -1;
  for (w = 0; w < 18; w++) c *= 10;
  scanf("%d", &q);
  for (w = 0; w < q; w++) {
    scanf("%d%d", &a[w], &s[w]);
    d[w] = w;
    a1[w] = a2[w] = c;
  }
  qs(0, q - 1);
  for (w = 0; w < q; w++) {
    c = s[d[w]];
    e = 0;
    if (c > a1[0]) {
      a2[0] = a1[0];
      s2[0] = s1[0];
      a1[0] = c;
      s1[0] = a[d[w]];
    } else if (c > a2[0]) {
      a2[0] = c;
      s2[0] = a[d[w]];
    }
    while ((w < q - 1) && (a[d[w + 1]] == a[d[w]])) {
      w++;
      c += s[d[w]];
      e++;
      if (c > a1[e]) {
        a2[e] = a1[e];
        s2[e] = s1[e];
        a1[e] = c;
        s1[e] = a[d[w]];
      } else if (c > a2[e]) {
        a2[e] = c;
        s2[e] = a[d[w]];
      }
    }
  }
  c = a1[0] + a2[0];
  e = s1[0];
  r = s2[0];
  t = y = 0;
  for (w = 1; w < q; w++) {
    if (a1[w] + a2[w] > c) {
      c = a1[w] + a2[w];
      e = s1[w];
      r = s2[w];
      t = y = w;
    }
    if (s1[w - 1] != s1[w]) {
      if (a1[w - 1] + a1[w] > c) {
        c = a1[w - 1] + a1[w];
        e = s1[w - 1];
        r = s1[w];
        t = w - 1;
        y = w;
      }
    } else if (a2[w - 1] + a1[w] > c) {
      c = a2[w - 1] + a1[w];
      e = s2[w - 1];
      r = s1[w];
      t = w - 1;
      y = w;
    }
    if (s1[w - 1] != s2[w])
      if (a1[w - 1] + a2[w] > c) {
        c = a1[w - 1] + a2[w];
        e = s1[w - 1];
        r = s2[w];
        t = w - 1;
        y = w;
      }
  }
  t++;
  y++;
  cout << c << "\n" << t + y << "\n";
  w = q - 1;
  for (v = 65536; v; v /= 2)
    if ((w - v >= 0) && (a[d[w - v]] >= e)) w -= v;
  e = q - 1;
  for (v = 65536; v; v /= 2)
    if ((e - v >= 0) && (a[d[e - v]] >= r)) e -= v;
  if (y > t) {
    y--;
    printf("%d ", d[e] + 1);
    e++;
  }
  while ((t) || (y)) {
    if (t) {
      t--;
      printf("%d ", d[w] + 1);
      w++;
    }
    if (y) {
      y--;
      printf("%d ", d[e] + 1);
      e++;
    }
  }
  return 0;
}
