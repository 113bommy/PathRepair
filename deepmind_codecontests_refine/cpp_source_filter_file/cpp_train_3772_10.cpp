#include <bits/stdc++.h>
using namespace std;
struct ferz {
  int x, y;
  int nom;
};
ferz a[100003];
ferz b[100003];
int res[100003];
int coun[13];
void mergesort_x(ferz *a, ferz *b, int l, int r) {
  int i, i0, i1, iRight, iEnd, width, j;
  for (width = 1; width < r - l; width *= 2)
    for (i = l; i < r; i += width * 2) {
      i0 = i;
      i1 = iRight = min(i + width, r);
      iEnd = min(i + width * 2, r);
      for (j = i; j < iEnd; j++)
        if (i0 < iRight && (i1 == iEnd || a[i0].x < a[i1].x))
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = b[j];
    }
}
void mergesort_y(ferz *a, ferz *b, int l, int r) {
  int i, i0, i1, iRight, iEnd, width, j;
  for (width = 1; width < r - l; width *= 2)
    for (i = l; i < r; i += width * 2) {
      i0 = i;
      i1 = iRight = min(i + width, r);
      iEnd = min(i + width * 2, r);
      for (j = i; j < iEnd; j++)
        if (i0 < iRight && (i1 == iEnd || a[i0].y < a[i1].y))
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = b[j];
    }
}
void mergesort_sum(ferz *a, ferz *b, int l, int r) {
  int i, i0, i1, iRight, iEnd, width, j;
  for (width = 1; width < r - l; width *= 2)
    for (i = l; i < r; i += width * 2) {
      i0 = i;
      i1 = iRight = min(i + width, r);
      iEnd = min(i + width * 2, r);
      for (j = i; j < iEnd; j++)
        if (i0 < iRight &&
            (i1 == iEnd || a[i0].y + a[i0].x < a[i1].y + a[i1].x))
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = b[j];
    }
}
void mergesort_sum2(ferz *a, ferz *b, int l, int r) {
  int i, i0, i1, iRight, iEnd, width, j;
  for (width = 1; width < r - l; width *= 2)
    for (i = l; i < r; i += width * 2) {
      i0 = i;
      i1 = iRight = min(i + width, r);
      iEnd = min(i + width * 2, r);
      for (j = i; j < iEnd; j++)
        if (i0 < iRight &&
            (i1 == iEnd || a[i0].y - a[i0].x < a[i1].y - a[i1].x))
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = b[j];
    }
}
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int i, j, jj;
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a[i].y, &a[i].x);
    a[i].y--;
    a[i].x--;
    a[i].nom = i;
  }
  mergesort_y(a, b, 0, m);
  i = 0;
  while (i < m) {
    j = i;
    while (j < m && a[i].y == a[j].y) j++;
    mergesort_x(a, b, i, j);
    res[a[i].nom]++;
    if (j - 1 != i)
      res[a[j - 1].nom]++;
    else
      res[a[i].nom]--;
    for (jj = i + 1; jj < j - 1; jj++) res[a[jj].nom] += 2;
    i = j;
  }
  mergesort_x(a, b, 0, m);
  i = 0;
  while (i < m) {
    j = i;
    while (j < m && a[i].x == a[j].x) j++;
    mergesort_y(a, b, i, j);
    res[a[i].nom]++;
    if (j - 1 != i)
      res[a[j - 1].nom]++;
    else
      res[a[i].nom]--;
    for (jj = i + 1; jj < j - 1; jj++) res[a[jj].nom] += 2;
    i = j;
  }
  mergesort_sum(a, b, 0, m);
  i = 0;
  while (i < m) {
    j = i;
    while (j < m && a[i].x + a[i].y == a[j].x + a[j].y) j++;
    mergesort_y(a, b, i, j);
    res[a[i].nom]++;
    if (j - 1 != i)
      res[a[j - 1].nom]++;
    else
      res[a[i].nom]--;
    for (jj = i + 1; jj < j - 1; jj++) res[a[jj].nom] += 2;
    i = j;
  }
  mergesort_sum2(a, b, 0, m);
  i = 0;
  while (i < m) {
    j = i;
    while (j < m && a[i].y - a[i].x == a[j].y - a[j].x) j++;
    mergesort_y(a, b, i, j);
    res[a[i].nom]++;
    if (j - 1 != i)
      res[a[j - 1].nom]++;
    else
      res[a[i].nom]--;
    for (jj = i + 1; jj < j - 1; jj++) res[a[jj].nom] += 2;
    i = j;
  }
  for (i = 0; i < m; i++) coun[res[i]]++;
  printf("%d", coun[1]);
  for (i = 2; i < 9; i++) printf(" %d", coun[i]);
  printf("\n");
}
