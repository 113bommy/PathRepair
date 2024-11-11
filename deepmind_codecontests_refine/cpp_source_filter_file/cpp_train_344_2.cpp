#include <bits/stdc++.h>
using namespace std;
char prm[5005];
char nb[5005];
int idx[27];
int tk[5005];
int frq[27];
char rs[5005];
FILE *f1 = stdin;
int main() {
  fscanf(f1, "%s%s", prm, nb);
  int n = strlen(prm), i;
  sort(prm, prm + n);
  int nt = strlen(nb);
  for (i = 0; i < 5005; i++) tk[i] = 0;
  for (i = 0; i < 27; i++) frq[i] = 0;
  for (i = 0; i < n; i++) frq[prm[i] - 'a']++;
  int z;
  char eq = '1';
  for (i = 0; i < nt; i++) {
    z = nb[i] - 'a';
    while (frq[z] == 0 && z < 26) z++;
    if (z == 26) break;
    frq[z]--;
    if (z > (nb[i] - 'a')) {
      eq = '0';
      rs[i] = z + 'a';
      i++;
      break;
    }
    rs[i] = z + 'a';
  }
  int x = i - 1;
  if (z == 26 && eq == '0') {
    printf("-1");
    exit(0);
  }
  if ((z == 26 || nt < n) && eq == '1') {
    for (; x >= 0; x--) {
      z = rs[x] - 'a' + 1;
      while (frq[z] == 0 && z < 26) z++;
      frq[rs[x] - 'a']++;
      if (z != 26) {
        rs[x] = z + 'a';
        frq[z]--;
        i = x + 1;
        break;
      }
    }
    if (x == -1) {
      printf("-1\n");
      exit(0);
    }
  }
  for (; i < n; i++) {
    z = 0;
    while (frq[z] == 0 && z < 26) z++;
    rs[i] = z + 'a';
    frq[z]--;
  }
  printf("%s", rs);
  scanf("%*d");
}
