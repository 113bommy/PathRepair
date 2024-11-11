#include <bits/stdc++.h>
int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
bool hehe(int a) { return ((min(a, 25) + a) % (2 + a % 3)) > 0; }
int main() {
  for (int i = 21; i <= 50; i++) {
    printf("%d\n", hehe(i));
  }
  return 0;
}
