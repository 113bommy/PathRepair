#include <bits/stdc++.h>
struct pairs {
  char origen[30];
  char destino[30];
  int momento;
} pares[1010];
int amigos[1010];
int main() {
  int n, d;
  int t;
  int i, j;
  int k = 0;
  int t2;
  int y;
  int flag;
  scanf("%d%d", &n, &d);
  for (i = 1; i <= n; i++) {
    scanf("%s%s%d", pares[i].origen, pares[i].destino, &pares[i].momento);
  }
  for (i = 1; i < n; i++) {
    for (j = i + 1; j <= n; j++) {
      t = pares[j].momento - pares[i].momento;
      if (t > d) break;
      if (!strcmp(pares[i].origen, pares[j].destino) &&
          !strcmp(pares[i].destino, pares[j].origen) && t > 0) {
        flag = 0;
        for (y = 0; y < k && !flag; y++) {
          if ((!strcmp(pares[amigos[y]].origen, pares[i].origen) &&
               !strcmp(pares[amigos[y]].destino, pares[i].destino)) ||
              (!strcmp(pares[amigos[y]].origen, pares[i].destino) &&
               !strcmp(pares[amigos[y]].destino, pares[i].origen))) {
            flag = 1;
          }
        }
        if (!flag) {
          amigos[k++] = j;
        }
      }
    }
  }
  printf("%d\n", k);
  for (i = 0; i < k; i++) {
    printf("%s %s\n", pares[amigos[i]].origen, pares[amigos[i]].destino);
  }
  return 0;
}
