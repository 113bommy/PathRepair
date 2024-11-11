#include <bits/stdc++.h>
char a[100];
int b[500], cnt;
int main() {
  gets(a);
  memset(b, 0, 500);
  int x = strlen(a);
  cnt = 0;
  for (int i = 0; i < x; ++i) {
    b[(int)a[i]] += 1;
    if (b[(int)a[i]] == 1) cnt++;
  }
  if (cnt % 2 == 0)
    printf("CHAT WITH HER!\n");
  else
    printf("IGNORE HIM\n");
  return 0;
}
