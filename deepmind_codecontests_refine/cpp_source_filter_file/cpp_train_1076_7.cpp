#include <bits/stdc++.h>
using namespace std;
const int n = 100001;
int a[n];
void qs(int q, int w, int *s) {
  int e = q, r = w, t = a[s[q + (rand() % (w - q + 1))]], y;
  do {
    while (a[s[e]] < t) e++;
    while (a[s[r]] > t) r--;
    if (e <= r) {
      y = s[e];
      s[e] = s[r];
      s[r] = y;
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs(q, r, s);
  if (e < w) qs(e, w, s);
}
int *sfms(int *a, int q) {
  int w, e, r, t = 0, t1, c, i, *s = new int[q], *d = new int[q],
               *f = new int[q], *g = new int[q], *h = new int[q];
  for (w = 0; w < q; w++) s[w] = w;
  qs(0, q - 1, s);
  d[s[0]] = 0;
  for (w = 1; w < q; w++) {
    if (a[s[w]] != a[s[w - 1]]) t++;
    d[s[w]] = t;
  }
  t++;
  for (i = 1; (i < q) && (t < q); i <<= 1) {
    for (w = 0; w < t; w++) g[w] = -1;
    for (w = q - 1; w >= 0; w--) {
      h[d[s[w]]] = w;
      e = s[w] + i;
      if (e >= q) e -= q;
      e = d[e];
      f[s[w]] = g[e];
      g[e] = s[w];
    }
    t1 = -1;
    for (w = 0; w < t; w++) {
      r = -1;
      for (e = g[w]; e >= 0; e = f[e]) {
        c = d[e];
        s[h[c]] = e;
        h[c]++;
        if (r != c) {
          r = c;
          t1++;
        }
        d[e] = t1;
      }
    }
    t = t1 + 1;
    e = r = -1;
    for (w = 0; w < q; w++) {
      if (e != d[s[w]]) {
        e = d[s[w]];
        r++;
      }
      d[s[w]] = r;
    }
  }
  delete (d);
  delete (f);
  delete (g);
  delete (h);
  return s;
}
int d[n], f[n], h[n * 5], h1[n * 5];
void qs1(int q, int w) {
  int e = q, r = w, y = q + (rand() % (w - q + 1)), t = h[y], t1 = h1[y];
  do {
    while ((h[e] < t) || ((h[e] == t) && (h1[e] < t1))) e++;
    while ((h[r] > t) || ((h[r] == t) && (h1[r] > t1))) r--;
    if (e <= r) {
      y = h[e];
      h[e] = h[r];
      h[r] = y;
      y = h1[e];
      h1[e] = h1[r];
      h1[r] = y;
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs1(q, r);
  if (e < w) qs1(e, w);
}
int main() {
  int q, w, e, r, t, *s, y;
  scanf("%d", &q);
  for (w = 0; w < q; w++) scanf("%d", &a[w]);
  a[q] = -1;
  q++;
  s = sfms(a, q);
  t = 0;
  for (w = 0; w < q; w++) f[s[w]] = w;
  for (w = 0; w < q; w++) {
    if (w == q - 1) {
      t = d[f[w]] = 0;
      continue;
    }
    t = max(t - 1, 0);
    e = s[f[w] + 1];
    for (; (w + t < q) && (e + t < q); t++)
      if (a[w + t] != a[e + t]) break;
    d[f[w]] = t;
  }
  t = 0;
  for (w = 0; w < q; w++) {
    r = q;
    for (e = w;; e++) {
      r = min(r, d[e]);
      if (!r) break;
      if (r >= abs(s[w] - s[e + 1])) {
        h[t] = abs(s[w] - s[e + 1]);
        h1[t] = min(s[w], s[e + 1]);
        t++;
      }
    }
  }
  if (t) qs1(0, t - 1);
  y = 0;
  for (w = 0; w < t; w++)
    if (y <= h1[w]) y = h1[w] + h[w];
  printf("%d\n", q - y - 1);
  for (w = y; w < q - 1; w++) printf("%d ", a[w]);
  return 0;
}
