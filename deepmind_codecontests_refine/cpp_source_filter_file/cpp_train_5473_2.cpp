#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, spo, cpo;
  int dir, i, l;
  char s[2], ss[10];
  bool flag;
  char cc[205];
  while (scanf("%d%d%d", &n, &spo, &cpo) != EOF) {
    scanf("%s%s", s, ss);
    if (strcmp(ss, "head") == 0) {
      if (cpo == 1) dir = n;
      dir = 1;
    } else {
      if (cpo == n) dir = 1;
      dir = n;
    }
    scanf("%s", cc);
    l = strlen(cc);
    flag = false;
    for (i = 0; i < l; i++) {
      if (cc[i] == '0') {
        if (dir == 1) {
          if (spo > cpo && spo < n)
            spo++;
          else if (spo < cpo && spo > 1)
            spo--;
          cpo--;
          if (cpo == 1) dir = 0;
          if (cpo == spo) {
            flag = true;
            break;
          }
        } else {
          if (spo > cpo && spo < n)
            spo++;
          else if (spo < cpo && spo > 1)
            spo--;
          cpo++;
          if (cpo == n) dir = 1;
          if (cpo == spo) {
            flag = true;
            break;
          }
        }
      } else {
        spo = 0;
        if (dir == 1) {
          cpo--;
          if (cpo == 1) dir = n;
          spo = n;
          if (cpo == spo) {
            flag = true;
            break;
          }
        } else {
          cpo++;
          if (cpo == n) dir = 1;
          spo = 1;
          if (cpo == spo) {
            flag = true;
            break;
          }
        }
      }
    }
    if (flag == true)
      printf("Controler %d\n", i + 1);
    else
      printf("Stowaway\n");
  }
  return 0;
}
