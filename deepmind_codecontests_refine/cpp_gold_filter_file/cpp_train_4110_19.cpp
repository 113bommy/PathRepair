#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int Misha_Points = max(((3 * a) / 10), (a - (a / 250) * c));
  int Vasya_Points = max(((3 * b) / 10), (b - (b / 250) * d));
  if (Misha_Points > Vasya_Points)
    printf("Misha\n");
  else if (Misha_Points < Vasya_Points)
    printf("Vasya\n");
  else
    printf("Tie\n");
  return 0;
}
