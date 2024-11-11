#include <stdio.h>

int main(void) {
  char s[4];
  scanf("%s", s);
  int ans = 700, i;
  for(i = 0; i < 3; ++i) if(s[i] == 'o') ans += 100;
  printf("%d", ans);
  return 0;
}