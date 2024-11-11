#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  int a;
  scanf("%d", &a);
  if (a != 5)
    printf("%d\n", (a % 3 + 1));
  else
    printf("1\n");
  return 0;
}
