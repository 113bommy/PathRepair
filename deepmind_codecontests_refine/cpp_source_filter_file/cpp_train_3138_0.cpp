#include <bits/stdc++.h>
using namespace std;
const int nmax = 5e4;
int suma(int n, int a[nmax]) {
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  return sum;
}
int primulDivizor(int x) {
  int ok = 0;
  for (int i = 2; i < x / 2; i++)
    if (x % i == 0 && ok == 0) ok = i;
  return ok;
}
int main() {
  int n;
  cin >> n;
  int a[nmax];
  for (int i = 0; i < n; i++) cin >> a[i];
  int sumaInitial = suma(n, a);
  int sumaMinima = sumaInitial;
  sort(a, a + n);
  int j = n - 1;
  int aux0, auxj;
  int sumaFinal;
  for (int j = n - 1; j >= n; j--)
    for (int i = 2; i <= a[j] / 2; i++)
      if (a[j] % i == 0) {
        sumaFinal = sumaInitial - a[j] + a[j] / i - a[0] + i * a[0];
        if (sumaFinal < sumaMinima) sumaMinima = sumaFinal;
      }
  cout << sumaMinima;
}
