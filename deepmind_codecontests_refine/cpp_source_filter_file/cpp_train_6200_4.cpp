#include <bits/stdc++.h>
using namespace std;
int vet[100100];
int pot2(int n);
int main() {
  int n;
  int i;
  long int cont = 0;
  int *ini, *fim;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }
  std::sort(vet, vet + n);
  for (i = 0; i < n; i++) {
    int p = pot2(vet[i]);
    ini = lower_bound(vet, vet + i, p - vet[i]);
    fim = upper_bound(vet, vet + i, p - vet[i]);
    cont += (fim - ini);
  }
  printf("%ld", cont);
}
int pot2(int n) {
  int pot = 1;
  while (pot <= n) {
    pot *= 2;
  }
  return pot;
}
