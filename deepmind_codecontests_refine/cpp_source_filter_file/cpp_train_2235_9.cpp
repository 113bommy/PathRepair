#include <bits/stdc++.h>
using namespace std;
char a[10], b[10];
char na[10], nb[10];
int main(void) {
  scanf("%s %s", a, b);
  int lena = strlen(a), lenb = strlen(b);
  int mmax = 0;
  for (int i = 0; i < max(lena, lenb); i++)
    mmax = max(a[i] - '0', mmax), mmax = max(mmax, b[i] - '0');
  mmax++;
  for (int i = 0; i < lena; i++) na[i] = a[lena - i - 1] - '0';
  for (int i = 0; i < lena; i++) nb[i] = b[lena - i - 1] - '0';
  int ost = 0;
  for (int i = 0; i < max(lena, lenb); i++) {
    if (ost + na[i] + nb[i] >= mmax)
      ost = 1;
    else
      ost = 0;
  }
  if (ost)
    printf("%d", max(lena, lenb) + 1);
  else
    printf("%d", max(lena, lenb));
  return 0;
}
