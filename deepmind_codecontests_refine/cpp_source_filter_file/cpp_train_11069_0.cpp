#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int cnt, res = 1234567890, i, j, k, lena, lenb, popr;
char a[5005], b[5005], tmp[2005];
int main() {
  gets(a);
  gets(b);
  lena = strlen(a);
  lenb = strlen(b);
  if (lena < lenb) {
    for (i = 0; i < lena; i++) tmp[i] = a[i];
    for (i = 0; i < lenb; i++) a[i] = b[i];
    for (i = 0; i < lena; i++) b[i] = tmp[i];
    swap(lena, lenb);
    popr = lena - lenb;
  }
  for (i = lena; i < 2 * lena; i++) a[i] = 0;
  for (i = lenb; i < 2 * lena; i++) b[i] = 1;
  for (i = -lenb; i < lenb; i++) {
    cnt = 0;
    for (j = 0; j < lenb; j++) {
      if (i + j >= 0 && a[i + j] == b[j]) cnt++;
    }
    if (lenb - cnt < res) res = lenb - cnt;
  }
  printf("%d\n", res + popr);
  return 0;
}
