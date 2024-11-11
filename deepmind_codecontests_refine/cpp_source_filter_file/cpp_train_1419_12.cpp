#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b;
  bool swapped = false;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a > b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    swapped = true;
  }
  long long tot = a;
  long long temp = b;
  while (temp % a != 0) {
    tot += temp % a;
    temp += b;
  }
  long long kecil = temp - tot;
  if (swapped) {
    kecil = kecil ^ tot;
    tot = kecil ^ tot;
    kecil = kecil ^ tot;
  }
  if (kecil < tot) {
    printf("Misha");
  } else if (kecil == tot) {
    printf("Equal");
  } else {
    printf("Dasha");
  }
  return 0;
}
