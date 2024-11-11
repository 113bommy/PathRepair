#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int ans1 = max(3 * a / 10, a - (a / 250) * c);
  int ans2 = max(3 * b / 10, b - (b / 250) * d);
  if (ans1 > ans2)
    printf("Misha\n");
  else if (ans2 > ans1)
    printf("Vasya");
  else
    printf("Tie\n");
  return 0;
}
