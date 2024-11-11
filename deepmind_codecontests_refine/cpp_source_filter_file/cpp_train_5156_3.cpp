#include <bits/stdc++.h>
char csu[7];
int isu;
long long su;
int main() {
  char tmp;
  scanf("%s", csu);
  {
    tmp = csu[1];
    csu[1] = csu[2];
    csu[2] = tmp;
  };
  {
    tmp = csu[3];
    csu[3] = csu[4];
    csu[4] = tmp;
  };
  {
    tmp = csu[2];
    csu[2] = csu[3];
    csu[3] = tmp;
  };
  {
    tmp = csu[3];
    csu[3] = csu[4];
    csu[4] = tmp;
  };
  isu = atoi(csu);
  su = isu;
  su *= su;
  su %= 100000;
  su *= su;
  su %= 100000;
  su *= isu;
  su %= 100000;
  printf("%lld", su);
}
