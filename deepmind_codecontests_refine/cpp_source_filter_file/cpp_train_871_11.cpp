#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
bitset<100005> bs;
int qnt[50];
int nim[30] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
               9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 10};
int main() {
  int n;
  scanf("%d", &n);
  bs.set();
  int raiz = sqrt(n);
  qnt[1] = n;
  for (int i = 2; i <= raiz; ++i) {
    if (bs[i]) {
      int tam = 0;
      for (long long j = i; j <= n; j = j * i) {
        if (j <= raiz) bs[j] = 0;
        ++tam;
      }
      ++qnt[tam];
      qnt[1] -= tam;
    }
  }
  int _xor = 0;
  for (int i = (0), __ = (30); i < __; ++i) _xor ^= qnt[i] & 1 ? nim[i] : 0;
  if (_xor)
    puts("Vasya");
  else
    puts("Petya");
  return 0;
}
