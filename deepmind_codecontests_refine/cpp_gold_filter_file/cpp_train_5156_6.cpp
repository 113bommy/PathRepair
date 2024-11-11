#include <bits/stdc++.h>
char ch[10];
int main(void) {
  scanf("%s", ch);
  int a = (ch[0] - '0') * 10000 + (ch[2] - '0') * 1000 + (ch[4] - '0') * 100 +
          (ch[3] - '0') * 10 + (ch[1] - '0');
  long long s = (long long)a;
  for (int i = 0; i < 4; i++) s = (s * a) % 100000;
  printf("%.5I64d", s);
}
