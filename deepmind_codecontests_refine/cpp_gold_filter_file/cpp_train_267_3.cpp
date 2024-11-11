#include <bits/stdc++.h>
using namespace std;
int main() {
  int ntrang, ngaydau, toida, heso, doclai, kq, tong;
  while (scanf("%d %d %d %d %d", &ntrang, &ngaydau, &toida, &heso, &doclai) >
         0) {
    kq = 0;
    tong = 0;
    while (ntrang > tong) {
      if (kq == 0) {
        tong += (ngaydau);
      } else {
        tong += (min(toida, heso * kq + ngaydau) - doclai);
      }
      kq++;
    }
    printf("%d\n", kq);
  }
  return 0;
}
