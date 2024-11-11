#include <bits/stdc++.h>
using namespace std;
int n;
double a[200003];
double b[200003];
void mergesort(double *a, double *b, int n) {
  int i, i0, i1, iRight, iEnd, width, j;
  for (width = 1; width < n; width *= 2)
    for (i = 0; i + width < n; i += width * 2) {
      i0 = i;
      i1 = iRight = i + width;
      iEnd = min(i + width * 2, n);
      for (j = i; i0 < iRight; j++)
        if (i1 == iEnd || a[i0] < a[i1])
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < i1; j++) a[j] = b[j];
    }
}
double pos1, pos2, pos3;
int main() {
  scanf("%d", &n);
  int i;
  double ep = 0.00000001;
  for (i = 0; i < n; i++) {
    scanf("%f", &a[i]);
    a[i] += ep;
  }
  mergesort(a, b, n);
  double l, r, re;
  l = 0.0000000;
  r = 2000000000.0000;
  int it = 50;
  while (it > 0) {
    it--;
    re = (l + r) / 2.0;
    int pos = 0;
    double p1 = -1.00;
    double p2 = -1.00;
    double p3 = -1.00;
    for (i = 1; i < n; i++) {
      if (((double)a[i] - (double)a[pos]) / 2.0 + ep > re) {
        if (p1 < -ep)
          p1 = (a[i - 1] + a[pos]) / 2.00;
        else if (p2 < -ep)
          p2 = (a[i - 1] + a[pos]) / 2.00;
        else
          break;
        pos = i;
      }
    }
    p3 = ((double)a[n - 1] + (double)a[pos]) / 2.00;
    if (i == n) {
      pos1 = p1;
      pos2 = p2;
      pos3 = p3;
      if (pos1 < -ep) pos1 = ep;
      if (pos2 < -ep) pos2 = ep;
      if (pos3 < -ep) pos3 = ep;
      r = re;
    } else
      l = re;
  }
  printf("%.20f\n", r);
  printf("%.20f %.20f %.20f\n", pos1, pos2, pos3);
  return 0;
}
