#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
char str[5];
int main() {
  int t = 0, x = 0;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    cin >> str;
    if (strcmp(str, "++X") == 0 || strcmp(str, "X++") == 0) {
      x++;
    } else
      x--;
  }
  printf("%d", t);
  return 0;
}
