#include <bits/stdc++.h>
using namespace std;
char st1[222];
char st2[222];
int boo[222];
int main() {
  int n;
  while (gets(st1) != NULL && gets(st2) != NULL) {
    memset(boo, 0, sizeof(boo));
    int l1 = strlen(st1);
    int l2 = strlen(st2);
    int bb = 1;
    for (int i = 0; i < l2; i++) {
      int b = 0;
      if (st2[i] == ' ') continue;
      for (int j = 0; j < l1; j++) {
        if (st2[i] == st1[j] && boo[j] == 0) {
          boo[j] = 1;
          b = 1;
          break;
        }
      }
      if (!b) {
        bb = 0;
        break;
      }
    }
    if (bb)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
