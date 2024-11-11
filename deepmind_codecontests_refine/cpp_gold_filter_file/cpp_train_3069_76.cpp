#include <bits/stdc++.h>
int main() {
  char s[12][12], w[70], b[70];
  int w1 = 0, b1 = 0;
  for (int i = 0; i < 8; i++) scanf("%s", s[i]);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] >= 'A' && s[i][j] <= 'Z')
        w[w1++] = s[i][j] + 32;
      else if (s[i][j] >= 'a' && s[i][j] <= 'z')
        b[b1++] = s[i][j];
      else
        continue;
    }
  }
  int lenw = strlen(w), lenb = strlen(b);
  int answ = 0, ansb = 0;
  for (int i = 0; i < lenw; i++) {
    if (w[i] == 'q')
      answ += 9;
    else if (w[i] == 'r')
      answ += 5;
    else if (w[i] == 'b')
      answ += 3;
    else if (w[i] == 'n')
      answ += 3;
    else if (w[i] == 'p')
      answ += 1;
    else
      continue;
  }
  for (int i = 0; i < lenb; i++) {
    if (b[i] == 'q')
      ansb += 9;
    else if (b[i] == 'r')
      ansb += 5;
    else if (b[i] == 'b')
      ansb += 3;
    else if (b[i] == 'n')
      ansb += 3;
    else if (b[i] == 'p')
      ansb += 1;
    else
      continue;
  }
  if (answ > ansb)
    printf("White\n");
  else if (answ < ansb)
    printf("Black\n");
  else
    printf("Draw\n");
  return 0;
}
