#include <bits/stdc++.h>
int main() {
  char* in = (char*)malloc(1000);
  scanf("%s", in);
  int left = 0, right = 0, i = 0, pluspos = 0;
  for (char c = in[i]; c != '=';) {
    if (c == '+') pluspos = i;
    c = in[++i];
  }
  left = i - 1;
  for (char c = in [++i]; i < strlen(in); i++) {
    right++;
  }
  int sub = left - right;
  if (fabs(sub) == 2 || sub == 0) {
    if (sub < 0) {
      printf("%c", in[strlen(in) - 1]);
      for (int i = 0; i < strlen(in) - 1; i++) printf("%c", in[i]);
    } else if (sub > 0) {
      if (pluspos != 1) {
        for (int i = 1; i < strlen(in); i++) printf("%c", in[i]);
        printf("%c", in[0]);
      } else {
        for (int i = 1; i < strlen(in); i++)
          if (i != 2) printf("%c", in[i]);
        printf("%c", in[2]);
      }
    } else {
      printf("%s", in);
    }
  } else {
    printf("Impossible");
  }
}
