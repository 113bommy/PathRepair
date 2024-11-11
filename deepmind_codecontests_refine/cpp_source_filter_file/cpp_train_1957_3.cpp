#include <stdio.h>

int main() {
  int N;
  char S[10002];
  scanf("%d %s", &N, S);

  for(int i = 0; S[i] != '\0'; i++) {
    S[i] = 'A' + (S[i] - 'A' + N) % 26);
  }

  printf("%s\n", S);
  
  return 0;
}