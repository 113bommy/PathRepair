#include <bits/stdc++.h>
char* strrev(char*);
int main() {
  char s[105];
  char t[105];
  scanf("%s", s);
  scanf("%s", t);
  char* q;
  q = strrev(s);
  if (strcmp(q, t) == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}
char* strrev(char* s) {
  char* p = s;
  char t;
  int i;
  int len = strlen(p);
  for (i = 0; i < len / 2; i++) {
    t = p[i];
    p[i] = p[(len)-1 - i];
    p[(len)-1 - i] = t;
  }
  return s;
}
