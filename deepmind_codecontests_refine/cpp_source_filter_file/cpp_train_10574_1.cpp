#include <bits/stdc++.h>
int main() {
  char s[1000];
  scanf("%s", s);
  int count[4];
  int unknown[4];
  count[0] = count[1] = count[2] = count[3] = -1;
  unknown[0] = unknown[1] = unknown[2] = unknown[3] = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '!') {
      unknown[i % 4]++;
    }
    if (s[i] == 'r') count[0] = i % 4;
    if (s[i] == 'b') count[1] = i % 4;
    if (s[i] == 'y') count[2] = i % 4;
    if (s[i] == 'g') count[3] = i % 4;
  }
  for (int i = 0; i < 4; i++) {
    if (i) printf(" ");
    printf("%d", unknown[count[i]]);
  }
  printf("\n");
}
