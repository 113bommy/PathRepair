#include <bits/stdc++.h>
using namespace std;
char a[11], b[11], c[11];
void mergesort(char *a, char *c, int n) {
  int width, i0, i1, iRight, iEnd, i, j;
  for (width = 1; width < n; width <<= 1)
    for (i = 0; i < n; i += (width << 1)) {
      i0 = i;
      i1 = iRight = min(i + width, n);
      iEnd = min(i + (width << 1), n);
      for (j = i; j < iEnd; j++)
        if (i0 != iRight && (a[i0] <= a[i1] || i1 == iEnd))
          c[j] = a[i0++];
        else
          c[j] = a[i1++];
      for (j = i; j < iEnd; j++) a[j] = c[j];
    }
}
int main() {
  cin >> a;
  cin >> b;
  int i;
  for (i = 0; a[i]; i++)
    ;
  mergesort(a, c, i);
  i = 0;
  while (a[i] == '0' && a[i]) i++;
  char temp;
  if (a[i]) {
    temp = a[i];
    a[i] = a[0];
    a[0] = temp;
  }
  bool flag = true;
  int len1;
  int len2;
  for (len1 = 0; a[len1]; len1++)
    ;
  for (len2 = 0; b[len2]; len2++)
    ;
  if (len1 != len2) flag = false;
  if (flag)
    for (i = 0; a[i]; i++)
      if (a[i] != b[i]) flag = false;
  if (flag)
    cout << "OK" << endl;
  else
    cout << "WRONG_ANSWER" << endl;
  return 0;
}
