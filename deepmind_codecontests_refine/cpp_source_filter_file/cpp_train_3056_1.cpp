#include <bits/stdc++.h>
int main() {
  char input[107];
  char output[107];
  int i, o;
  while (1 == scanf("%s", input)) {
    i = 0;
    o = 0;
    for (; input[i]; i++) {
      if (input[i] == '/') {
        output[o++] = input[i];
        while (input[++i] == '/')
          ;
        --i;
      } else
        output[o++] = input[i];
    }
    while (output[--o] == '/')
      ;
    output[o + 1] = 0;
    printf("%s", output);
    printf("\n");
  }
  return 0;
}
