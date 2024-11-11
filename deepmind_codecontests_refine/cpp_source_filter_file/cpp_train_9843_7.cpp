#include <bits/stdc++.h>
using namespace std;
char a1[200000], a2[200000];
int s1[200000], s2[200000], d1[200000], d2[200000];
long long rot(long long q, long long w, long long e, long long r, long long t,
              long long y) {
  return (e - q) * (y - w) - (t - q) * (r - w);
}
int cmp(long long c1, long long c2, long long v1, long long v2) {
  long long S = rot(s1[0], s2[0], c1, c2, v1, v2);
  if (S < 0) {
    return -1;
  }
  if (S > 0) {
    return 1;
  }
  long long len1 = (c1 - s1[0]) * (c1 - s1[0]) + (c2 - s2[0]) * (c2 - s2[0]);
  long long len2 = (v1 - s1[0]) * (v1 - s1[0]) + (v2 - s2[0]) * (v2 - s2[0]);
  if (len1 < len2) {
    return -1;
  }
  if (len1 > len2) {
    return 1;
  }
  return 0;
}
void qs(int q, int w) {
  int e = q, r = w, y = q + (rand() % (w - q + 1));
  int t1 = s1[y], t2 = s2[y];
  do {
    while (cmp(s1[e], s2[e], t1, t2) < 0) e++;
    while (cmp(s1[r], s2[r], t1, t2) > 0) r--;
    if (e <= r) {
      swap(s1[e], s1[r]);
      swap(s2[e], s2[r]);
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs(q, r);
  if (e < w) qs(e, w);
}
int cmp2(int c1, int c2, int v1, int v2) {
  if (c1 < v1) {
    return -1;
  }
  if (c1 > v1) {
    return 1;
  }
  if (c2 < v2) {
    return -1;
  }
  if (c2 > v2) {
    return 1;
  }
  return 0;
}
void qs2(int q, int w) {
  int e = q, r = w, y = q + (rand() % (w - q + 1));
  int t1 = a1[y], t2 = a2[y];
  do {
    while (cmp2(a1[e], a2[e], t1, t2) < 0) e++;
    while (cmp2(a1[r], a2[r], t1, t2) > 0) r--;
    if (e <= r) {
      swap(a1[e], a1[r]);
      swap(a2[e], a2[r]);
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs2(q, r);
  if (e < w) qs2(e, w);
}
int q, lAns1, lAns2, numV;
int sch(int e, int r) {
  int c1 = 0, c, v;
  for (v = 1 << 17; v; v >>= 1) {
    c = c1 + v;
    if ((c < numV) && (cmp2(a1[c], a2[c], e, r) <= 0)) {
      c1 = c;
    }
  }
  if ((a1[c1] != e) || (a2[c1] != r)) {
    return 0;
  }
  return 1;
}
void check(int e, int r, int de, int dr) {
  if (sch(e + de, r) + sch(e, r + dr) == 2) {
    lAns1 = (1 + de) / 2;
    lAns2 = (1 + dr) / 2;
  }
}
int main() {
  int w, e, r, t;
  for (scanf("%d", &q); q; scanf("%d", &q)) {
    scanf("%d", &numV);
    for (w = 0; w < numV; w++) {
      scanf("%d%d", &s1[w], &s2[w]);
      s1[w]--;
      s2[w]--;
      a1[w] = s1[w];
      a2[w] = s2[w];
    }
    qs2(0, numV - 1);
    for (w = 1; w < numV; w++) {
      if ((s2[w] < s2[0]) || ((s2[w] == s2[0]) && (s1[w] < s1[0]))) {
        swap(s1[w], s1[0]);
        swap(s2[w], s2[0]);
      }
    }
    qs(1, numV - 1);
    t = 0;
    for (w = 1; w < numV; w++) {
      while (!((t == 0) ||
               (rot(s1[t - 1], s2[t - 1], s1[t], s2[t], s1[w], s2[w]) < 0))) {
        t--;
      }
      t++;
      s1[t] = s1[w];
      s2[t] = s2[w];
    }
    t++;
    for (w = 0; w < t; w++) {
      check(s1[w], s2[w], 1, 1);
      check(s1[w], s2[w], 1, -1);
      check(s1[w], s2[w], -1, 1);
      check(s1[w], s2[w], -1, -1);
      d1[w] = s1[w] + lAns1;
      d2[w] = s2[w] + lAns2;
    }
    r = 0;
    for (w = 1; w < t; w++) {
      if ((d1[w] != d1[r]) || (d2[w] != d2[r])) {
        r++;
        d1[r] = d1[w];
        d2[r] = d2[w];
      }
    }
    while ((d1[r] == d1[0]) && (d2[r] == d2[0])) {
      r--;
    }
    t = r + 1;
    r = 0;
    for (e = 1; e < t; e++) {
      if ((d1[e] < d1[r]) || ((d1[e] == d1[r]) && (d2[e] < d2[r]))) {
        r = e;
      }
    }
    cout << t << "\n";
    e = r;
    do {
      printf("%d %d\n", d1[e], d2[e]);
      e++;
      if (e == t) {
        e = 0;
      }
    } while (e != r);
  }
  return 0;
}
