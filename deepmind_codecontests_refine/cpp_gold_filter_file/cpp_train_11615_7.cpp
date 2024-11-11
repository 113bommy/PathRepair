#include <bits/stdc++.h>
using namespace std;
int main() {
  int f, a, b;
  scanf("%d", &f);
  scanf("%d:%d", &a, &b);
  if (b > 59) b %= 10;
  if (a > f or a == 24) a %= 10;
  if (a == 0 and f == 12) a = 10;
  printf("%02d:%02d", a, b);
}
