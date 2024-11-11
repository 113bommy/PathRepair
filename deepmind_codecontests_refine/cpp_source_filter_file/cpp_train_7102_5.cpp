#include <bits/stdc++.h>
using namespace std;
char s[200003];
long long k;
struct pos {
  char c;
  int nom;
};
pos a[100003];
pos b[100003];
pos c[100003];
void mergesort(pos *a, pos *b, int n) {
  int i, i1, i0, iRight, iEnd, width, j;
  for (width = 1; width < n; width *= 2)
    for (i = 0; i < n; i += width * 2) {
      i0 = i;
      i1 = iRight = min(i + width, n);
      iEnd = min(i + width * 2, n);
      for (j = i; j < iEnd; j++)
        if (i0 < iRight && (i1 == iEnd || a[i0].c <= a[i1].c))
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = b[j];
    }
}
int main() {
  scanf("%s", s);
  scanf("%I64d", &k);
  int i, j, jj;
  for (i = 0; s[i]; i++) {
    a[i].nom = i;
    a[i].c = s[i];
  }
  int n = i;
  if (k > ((n * (n + 1)) >> 1)) {
    printf("No such line.\n");
    return 0;
  }
  long long sum;
  long long add;
  int coun = n;
  while (k > 0) {
    mergesort(a, c, coun);
    sum = 0;
    i = 0;
    while (i < coun) {
      add = 0;
      j = i;
      while (j < coun && a[j].c == a[i].c) j++;
      for (jj = i; jj < j; jj++) add += n - a[jj].nom;
      if (sum + add >= k) break;
      sum += add;
      i = j;
    }
    printf("%c", a[i].c);
    k -= sum;
    k -= j - i;
    coun = 0;
    for (jj = i; jj < j; jj++) {
      if (a[jj].nom != n - 1) {
        b[coun].c = s[a[jj].nom + 1];
        b[coun++].nom = a[jj].nom + 1;
      }
    }
    for (jj = 0; jj < coun; jj++) a[jj] = b[jj];
  }
}
