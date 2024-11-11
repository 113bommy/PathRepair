#include <bits/stdc++.h>
using namespace std;
int l, _, n;
char s[10];
int main() {
  scanf("%d", &_);
  while (_--) {
    getchar();
    scanf("IAO'%s", s);
    l = strlen(s);
    sscanf(s, "%d", &n);
    if (l == 1) {
      if (0 <= n && n <= 8) printf("199%s", s);
      if (n == 9) printf("1989");
    }
    if (l == 2) {
      if (0 <= n && n <= 98) printf("20%s", s);
      if (n == 99) printf("1999");
    }
    if (l == 3) {
      if (n <= 98)
        printf("3%s", s);
      else
        printf("2%s", s);
    }
    if (l == 4) {
      if (n <= 3098)
        printf("1%s", s);
      else
        printf("%s", s);
    }
    if (l == 5) {
      if (n <= 13098)
        printf("1%s", s);
      else
        printf("%s", s);
    }
    if (l == 6) {
      if (n <= 1113098)
        printf("1%s", s);
      else
        printf("%s", s);
    }
    if (l == 7) {
      if (n <= 1113098)
        printf("1%s", s);
      else
        printf("%s", s);
    }
    if (l == 8) {
      if (n <= 11113098)
        printf("1%s", s);
      else
        printf("%s", s);
    }
    if (l == 9) {
      if (n <= 111113098)
        printf("1%s", s);
      else
        printf("%s", s);
    }
    puts("");
  }
  return 0;
}
