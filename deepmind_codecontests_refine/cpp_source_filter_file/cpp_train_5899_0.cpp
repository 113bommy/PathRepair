#include <bits/stdc++.h>
int main() {
  char vet[5000];
  int x;
  int conta = 0, contb = 0, contc = 0;
  int a = 1, b = 0, c = 0;
  scanf("%s", vet);
  x = strlen(vet);
  for (int i = 0; i < x; i++) {
    if (vet[0] != 'a') {
      printf("NO");
      return 0;
    }
    if (vet[i] == 'a' and a == 1 and b == 0 and c == 0) {
      conta++;
    } else if (vet[i] == 'a' and a != 1) {
      printf("NO");
      return 0;
    } else if (vet[i] == 'b' and a == 1) {
      b = 1;
      a = 0;
      contb++;
    } else if (vet[i] == 'b' and a == 0 and b == 1 and c == 0) {
      contb++;
    } else if (vet[i] == 'b' and b != 1) {
      printf("NO");
      return 0;
    } else if (vet[i] == 'c' and b == 1) {
      c = 1;
      b = 0;
      contc++;
    } else if (vet[i] == 'c' and a == 0 and b == 0 and c == 1) {
      contc++;
    } else if (vet[i] == 'c' and c != 1) {
      printf("NO");
      return 0;
    }
  }
  if (conta == 0 or contb == 0 or contc == 0) {
    printf("NO");
    return 0;
  }
  if (contc <= conta or contc <= contb)
    printf("YES");
  else
    printf("NO");
  return 0;
}
