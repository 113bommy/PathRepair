#include <bits/stdc++.h>
using namespace std;
int main() {
  int numero, aux, i = 1, sum = 0;
  cin >> numero;
  aux = numero;
  while (numero > 0) {
    numero -= i;
    i++;
  }
  if (sum == numero) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
