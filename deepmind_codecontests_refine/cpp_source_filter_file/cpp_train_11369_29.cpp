#include <bits/stdc++.h>
char buf[1000000];
int main() {
  scanf("%s", buf);
  int dent = 0;
  for (int i = 0; buf[i]; i++) {
    switch (buf[i]) {
      case '<':
        if (buf[i + 1] == '/') --dent;
        for (int j = dent; j--;) printf(" ");
        printf("<");
        break;
      case '>':
        printf(">\n");
        ++dent;
        break;
      case '/':
        dent--;
      default:
        printf("%c", buf[i]);
        break;
    }
  }
}
