#include <bits/stdc++.h>
int n;
char dirs[3001];
int rem = 0;
int cont = 0;
int right = 0;
int main() {
  scanf("%d", &n);
  scanf("%s", &dirs);
  for (int i = 0; i < n; i++) {
    if (right == 0) {
      if (dirs[i] == '.')
        cont++;
      else if (dirs[i] == 'L')
        cont = 0;
      else if (dirs[i] == 'R') {
        rem += cont;
        cont = 0;
        right = 1;
      }
    } else {
      if (dirs[i] == '.')
        cont++;
      else if (dirs[i] == 'L') {
        if (cont % 2 == 1) rem++;
        cont = 0;
        right = 0;
      }
    }
  }
  if (right == 0) rem += cont;
  printf("%d", rem);
}
