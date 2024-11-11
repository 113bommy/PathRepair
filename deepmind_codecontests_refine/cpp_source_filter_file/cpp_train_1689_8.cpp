#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  char p[104], h[104];
  int zm1[30], zm2[30];
  int plen, hlen, flag;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", &p);
    scanf("%s", &h);
    plen = strlen(p);
    hlen = strlen(h);
    if (plen > hlen) {
      printf("NO\n");
      continue;
    }
    memset(zm1, 0, sizeof(zm1));
    for (int i = 0; i < plen; i++) {
      zm1[p[i] - 'a']++;
    }
    if (plen == hlen) {
      flag = 1;
      memset(zm2, 0, sizeof(zm2));
      for (int i = 0; i < plen; i++) {
        zm2[p[i] - 'a']++;
      }
      for (int j = 0; j < 26; j++) {
        if (zm1[j] != zm2[j]) {
          flag = 0;
          printf("NO\n");
          break;
        }
      }
      if (flag) {
        printf("YES\n");
      }
      continue;
    }
    for (int i = 0; i <= hlen - plen; i++) {
      flag = 1;
      memset(zm2, 0, sizeof(zm2));
      for (int j = i; j < i + plen; j++) {
        zm2[h[j] - 'a']++;
      }
      for (int j = 0; j < 26; j++) {
        if (zm1[j] != zm2[j]) {
          flag = 0;
          break;
        }
      }
      if (flag == 1) {
        printf("YES\n");
        break;
      }
    }
    if (flag == 0) printf("NO\n");
  }
}
