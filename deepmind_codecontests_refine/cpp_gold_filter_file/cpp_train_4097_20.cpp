#include <bits/stdc++.h>
using namespace std;
char novaStringLex[100000];
int *ocorrencias;
int t;
void teste(char *string) {
  while ((*string) != '\0') {
    printf("%c", *string);
    string++;
  }
}
void novaString(char *string) {
  char c;
  int i;
  if (*string != '\0') {
    for (i = 25; i >= 0; i--) {
      if (ocorrencias[i]) {
        c = i + 97;
        break;
      }
    }
    while ((*string) != c && (*string) != '\0') {
      ocorrencias[(*string) - 97]--;
      string++;
    }
    novaStringLex[t] = (*string);
    t++;
    ocorrencias[(*string) - 97]--;
    novaString(++string);
  }
}
int main() {
  char string[100000];
  int size, i;
  t = 0;
  ocorrencias = (int *)calloc(26, sizeof(int));
  scanf("%s", string);
  size = strlen(string);
  for (i = 0; i < size; i++) {
    ocorrencias[string[i] - 97]++;
  }
  novaString(string);
  printf("%s\n", novaStringLex);
  free(ocorrencias);
  return 0;
}
