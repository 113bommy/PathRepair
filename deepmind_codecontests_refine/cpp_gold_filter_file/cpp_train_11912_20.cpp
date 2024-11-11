#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int b[1000010];
int numn[6] = {1968, 1689, 6891, 1698, 1986, 1896};
int yu[6] = {1, 3, 2, 6, 4, 5};
int main() {
  gets(a);
  int num[10] = {0};
  int i;
  int size = strlen(a);
  for (i = 0; i < size; i++) num[a[i] - '0']++;
  num[1]--;
  num[6]--;
  num[8]--;
  num[9]--;
  int mod = 0;
  int k = 0;
  for (i = 9; i >= 0; i--) {
    while (num[i]--) {
      b[k++] = i;
      mod = (mod * 3 % 7 + (i % 7)) % 7;
    }
  }
  if (mod == 0) {
    printf("1869");
    for (i = 0; i < k; i++) printf("%d", b[i]);
    printf("\n");
    return 0;
  }
  int ansmod = (7 - mod) % 7;
  int ci = k % 6;
  int cc = 0;
  while (yu[cc] != ansmod) cc++;
  cc += 6;
  cc -= ci;
  cc = cc % 6;
  printf("%d", numn[yu[cc] - 1]);
  for (i = 0; i < k; i++) printf("%d", b[i]);
  printf("\n");
}
