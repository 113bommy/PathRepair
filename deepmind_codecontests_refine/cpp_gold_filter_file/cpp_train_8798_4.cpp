#include <bits/stdc++.h>
typedef struct {
  char palavra[15];
} AArry;
typedef struct {
  char palavra[15];
  int pos;
} AHash;
int n, key, i, j, k;
AHash nome[400000];
char lista[400000][11];
int sum;
int h(char x[]) {
  int s = strlen(x);
  sum = 0;
  int i;
  int k;
  for (i = 0; i < s; i++) {
    sum = sum * 47 + x[i];
  }
  sum = (int)fabs((double)sum);
  return sum % 400000;
}
int main(void) {
  scanf("%d", &n);
  i = 0;
  while (i < n) {
    scanf(" %[^\n]", lista[i]);
    i++;
  }
  while (i >= 0) {
    key = h(lista[i]);
    for (j = key, k = 0; k < 400000; j++, k++) {
      j = j % 400000;
      if (nome[j].pos == 0) {
        strcpy(nome[j].palavra, lista[i]);
        nome[j].pos = 1;
        printf("%s\n", lista[i]);
        break;
      } else {
        if (strcmp(nome[j].palavra, lista[i]) == 0) break;
      }
    }
    i--;
  }
  return 0;
}
