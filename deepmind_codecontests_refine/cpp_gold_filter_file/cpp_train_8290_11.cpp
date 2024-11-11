#include <bits/stdc++.h>
using namespace std;
int main() {
  char psw[81];
  char numCode[10][11];
  while (scanf("%s", &psw) != EOF) {
    for (int i = 0; i < 10; i++) scanf("%s", &numCode[i]);
    char tmp[11];
    for (int j = 0; j < 8; j++) {
      for (int i = 0; i < 10; i++) tmp[i] = psw[j * 10 + i];
      for (int k = 0; k < 10; k++) {
        if (strcmp(tmp, numCode[k]) == 0) {
          printf("%d", k);
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
