#include <bits/stdc++.h>
using namespace std;
long a, i, k, i2, i1, r, k1, j, m, h, z, t, n, nmin, d1, d2, k2;
pair<long, long> tb[30];
char we[1010][1010], we1[10000], we2[10000];
vector<string> vk;
string w1, w2;
int main() {
  a = 0;
  k1 = 0;
  vk.clear();
  gets(we1);
  k = strlen(we1);
  j = 0;
  k2 = 0;
  while (k >= 0) {
    strcpy(we[j++], we1);
    k2 = strlen(we1);
    if (k2 > k1) k1 = k2;
    if (gets(we1) == NULL) break;
    k = strlen(we1);
  }
  k2 = k1;
  for (i = 0; i < k2 + 2; i++) printf("*");
  printf("\n");
  z = 0;
  for (i = 0; i < j; i++) {
    printf("*");
    k = strlen(we[i]);
    if (k % 2 == k2 % 2) {
      for (i1 = 0; i1 < (k2 - k) / 2; i1++) printf(" ");
      printf("%s", we[i]);
      for (i1 = 0; i1 < (k2 - k) / 2; i1++) printf(" ");
      printf("*\n");
    } else {
      for (i1 = 0; i1 < (k2 - k) / 2; i1++) printf(" ");
      for (i1 = 0; i1 < z; i1++) printf(" ");
      printf("%s", we[i]);
      for (i1 = 0; i1 < (k2 - k) / 2; i1++) printf(" ");
      for (i1 = 0; i1 < 1 - z; i1++) printf(" ");
      printf("*\n");
      if (z == 1)
        z = 0;
      else
        z = 1;
    }
  }
  for (i = 0; i < k2 + 2; i++) printf("*");
  printf("\n");
  return 0;
}
