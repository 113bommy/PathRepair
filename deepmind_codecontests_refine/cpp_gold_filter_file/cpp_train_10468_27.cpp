#include <bits/stdc++.h>
using namespace std;
char a;
int r, c;
bool side(int x) {
  if (x == 1 or x == 8) return true;
  return false;
}
int type(int x, int y) {
  if (side(x) and side(y)) return 1;
  if (side(x) or side(y)) return 2;
  return 3;
}
int main() {
  scanf(" %c%d", &a, &r);
  c = a - 'a' + 1;
  int ty = type(r, c);
  if (ty == 1)
    printf("3");
  else if (ty == 2)
    printf("5");
  else
    printf("8");
  return 0;
}
