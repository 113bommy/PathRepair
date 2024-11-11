#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (!x || !y) return x > y ? x : y;
  for (int t; t = x % y; x = y, y = t)
    ;
  return y;
}
int main() {
  int a, b, s1, s2, n;
  while (~scanf("%d%d", &a, &b)) {
    n = gcd(a, b);
    s1 = a / n;
    s2 = b / n;
    if (a > b)
      s1--;
    else
      s2--;
    if (s1 > s2)
      printf("Dasha\n");
    else if (s1 == s2)
      printf("Equal\n");
    else
      printf("Masha\n");
  }
}
