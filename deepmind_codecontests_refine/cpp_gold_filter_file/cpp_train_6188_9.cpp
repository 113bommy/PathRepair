#include <bits/stdc++.h>
int main() {
  long long unsigned int days, a, b;
  scanf("%llu", &days);
  scanf("%llu", &a);
  scanf("%llu", &b);
  int w;
  long long unsigned int aux;
  for (int i = 0; i < days; i++) {
    scanf("%i", &w);
    aux = ((w * a) % b) / a;
    printf("%llu ", aux);
  }
  return 0;
}
