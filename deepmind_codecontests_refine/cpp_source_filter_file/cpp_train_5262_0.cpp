#include <bits/stdc++.h>
using namespace std;
bool isLeap(int y) {
  if (y % 100 == 0 || (y % 4 == 0 && y % 100 != 0))
    return true;
  else
    return false;
}
int add(int y) {
  if (isLeap(y))
    return 366 % 7;
  else
    return 365 % 7;
}
int main() {
  int y, Add = 0, y_aux;
  scanf("%d", &y);
  y_aux = y;
  do {
    y_aux++;
    Add += add(y_aux);
  } while (Add % 7 != 0 || (isLeap(y_aux) != isLeap(y)));
  printf("%d\n", y_aux);
}
