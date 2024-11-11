#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, maisha, vasya;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  maisha = max((3 * a) / 10, (a - (a / 250) * c));
  vasya = max((3 * b) / 10, (b - (b / 250) * d));
  if (maisha < vasya) {
    printf("Vasya\n");
  } else if (maisha > vasya) {
    printf("Misha\n");
  } else {
    printf("Tie\n");
  }
  return 0;
}
