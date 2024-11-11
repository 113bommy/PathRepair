#include <bits/stdc++.h>
using namespace std;
char s[17][13];
char a[13], b[13];
int g[13][13];
int len[17];
int ans[17];
int n, m;
int rec;
string d[17];
string e[17];
void mergesort(string *a, string *b, int n) {
  int i, i0, i1, iRight, iEnd, width, j;
  for (width = 1; width < n; width *= 2)
    for (i = 0; i < n; i += width * 2) {
      i0 = i;
      i1 = iRight = min(i + width, n);
      iEnd = min(i + width * 2, n);
      for (j = i; j < iEnd; j++)
        if (i0 < iRight && (i1 == iEnd || a[i0] < a[i1]))
          b[j] = a[i0++];
        else
          b[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = b[j];
    }
}
int main() {
  scanf("%d %d", &n, &m);
  int i, j;
  int ind1, ind2;
  for (i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (len[i] = 0; s[i][len[i]]; len[i]++)
      ;
  }
  int l1, l2;
  for (i = 0; i < m; i++) {
    scanf("%s %s", a, b);
    for (l1 = 0; a[l1]; l1++)
      ;
    for (l2 = 0; b[l2]; l2++)
      ;
    for (ind1 = 0; ind1 < n; ind1++)
      if (len[ind1] == l1) {
        for (j = 0; j < l1; j++) {
          if (s[ind1][j] != a[j]) break;
        }
        if (j == l1) break;
      }
    for (ind2 = 0; ind2 < n; ind2++)
      if (len[ind2] == l2) {
        for (j = 0; j < l2; j++) {
          if (s[ind2][j] != b[j]) break;
        }
        if (j == l2) break;
      }
    g[ind1][ind2] = g[ind2][ind1] = -1;
  }
  int temp;
  int res[17];
  int coun, coun2;
  for (i = 1; i < (1 << n); i++) {
    temp = i;
    coun = 0;
    coun2 = 0;
    while (temp > 0) {
      if ((temp & 1) > 0) res[coun++] = coun2;
      coun2++;
      temp >>= 1;
    }
    for (l1 = 0; l1 < coun; l1++)
      for (l2 = l1 + 1; l2 < coun; l2++)
        if (g[res[l1]][res[l2]] < 0) {
          l1 = 20;
          break;
        }
    if (l1 < 19 && coun > rec) {
      rec = coun;
      for (j = 0; j < coun; j++) ans[j] = res[j];
    }
  }
  printf("%d\n", rec);
  for (i = 0; i < rec; i++) d[i] = s[ans[i]];
  mergesort(d, e, rec);
  for (i = 0; i < rec; i++) cout << d[i] << endl;
  return 0;
}
