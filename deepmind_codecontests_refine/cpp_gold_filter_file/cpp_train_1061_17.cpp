#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int foot, inches, aux;
  scanf("%d", &n);
  while (1) {
    foot = n / 36;
    aux = n % 36;
    inches = aux / 3;
    if (aux % 3 == 2) inches += 1;
    if (inches >= 12)
      n = inches * 3 + foot * 36;
    else
      break;
  }
  printf("%d %d", foot, inches);
}
