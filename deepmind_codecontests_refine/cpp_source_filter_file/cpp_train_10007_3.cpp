#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[5];
  char temp1[0], temp2[0];
  int too, too1, too2, too3;
  int Temp, Temp2, Temp3, Temp4;
  bool c = false;
  scanf("%s", &s);
  temp1[0] = s[0];
  temp2[0] = s[1];
  too = temp1[0] - 48;
  too1 = temp2[0] - 48;
  too2 = too * 10 + too1;
  temp1[0] = s[3];
  temp2[0] = s[4];
  too = temp1[0] - 48;
  too1 = temp2[0] - 48;
  too3 = too * 10 + too1;
  Temp = too2 / 10;
  Temp2 = too2 % 10;
  Temp3 = too3 / 10;
  Temp4 = too3 % 10;
  while (c == false) {
    Temp4++;
    if (Temp4 == 10) {
      Temp4 = 0;
      Temp3++;
    }
    if (Temp3 == 6) {
      Temp3 = 0;
      Temp2++;
    }
    if (Temp2 == 9 && Temp < 2) {
      Temp2 = 0;
      Temp++;
    } else if (Temp2 == 4 && Temp == 2) {
      Temp2 = 0;
      Temp = 0;
    }
    if (Temp == Temp4 && Temp2 == Temp3) c = true;
  }
  printf("%d%d:%d%d", Temp, Temp2, Temp3, Temp4);
  return 0;
}
