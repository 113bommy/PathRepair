#include <bits/stdc++.h>
using namespace std;
struct laptops {
  int kalite;
  int para;
} dizi[100006];
bool operator<(laptops a, laptops b) { return a.para < b.para; }
int main() {
  int plp = 0;
  int a;
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    cin >> dizi[i].para >> dizi[i].kalite;
  }
  sort(dizi, dizi + a);
  for (int p = 0; p < a - 1; p++) {
    if (dizi[p].kalite > dizi[p + 1].kalite) {
      printf("Happy Alex");
      plp = 2;
      return 0;
    }
  }
  if (plp != 2) {
    printf("Poor Alex");
  }
}
