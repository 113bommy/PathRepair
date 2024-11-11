#include <bits/stdc++.h>
char s;
char p;
int a;
int main() {
  int n;
  scanf("%d", &n);
  scanf("%c", &s);
  scanf("%c", &s);
  int i;
  for (i = 0; i < n;) {
    p = s;
    a = 0;
    for (; s == p; i++, a++, scanf("%c", &s))
      ;
    if (p == 'e' && a == 2) {
      printf("ee");
    } else if (p == 'o' && a == 2) {
      printf("oo");
    } else if (p == 'a' || p == 'e' || p == 'y' || p == 'u' || p == 'i' ||
               p == 'o') {
      printf("%c", p);
    } else {
      int j;
      for (j = 0; j < a; j++) printf("%c", p);
    }
  }
}
