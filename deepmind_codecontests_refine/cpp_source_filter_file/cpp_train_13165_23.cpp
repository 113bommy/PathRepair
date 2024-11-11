#include <bits/stdc++.h>
using namespace std;
int main() {
  int sticks[10];
  memset(sticks, 0, sizeof(sticks));
  sticks[0] = 2;
  sticks[1] = 6;
  sticks[2] = 2;
  sticks[3] = 3;
  sticks[4] = 3;
  sticks[5] = 4;
  sticks[6] = 2;
  sticks[7] = 5;
  sticks[8] = 1;
  sticks[9] = 2;
  char str[3];
  scanf("%s", str);
  printf("%d\n", sticks[str[0] - '0'] * sticks[str[1] - '0']);
  return 0;
}
