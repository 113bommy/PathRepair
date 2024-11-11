#include <bits/stdc++.h>
int main() {
  int a1, a2;
  scanf("%f", &a1);
  scanf("%f", &a2);
  int big = pow(2, a1);
  int small = a2 / big;
  int kalan = a2 - small * big;
  printf("%d", kalan);
}
