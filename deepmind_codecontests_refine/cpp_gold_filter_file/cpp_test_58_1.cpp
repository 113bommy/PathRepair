#include <bits/stdc++.h>
using namespace std;
int i, j, n, t, k1[10000], k2[10000], cz1 = 0, cz11 = 0;
char s1[10000], s2[10000];
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &t);
    scanf("%s", s1);
    scanf("%s", s2);
    for (i = 0; i < strlen(s1); i++) {
      k1[i] = s1[i] - '0';
      if (k1[i] == 0) {
        cz1++;
      }
    }
    for (i = 0; i < strlen(s2); i++) {
      k2[i] = s2[i] - '0';
      if (k2[i] == 0) {
        cz1++;
      }
    }
    if (cz1 == 0) {
      printf("YES\n");
    } else {
      for (j = 0; j < t; j++) {
        if (k1[j] != 0 && k2[j] != 0) {
          cz11++;
        }
      }
      if (cz11 >= 1) {
        printf("NO\n");
      } else {
        printf("YES\n");
      }
    }
    cz1 = 0, cz11 = 0;
  }
}
