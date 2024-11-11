#include <bits/stdc++.h>
using namespace std;
int main() {
  string cadena1;
  int cont = 0, cont1 = 0;
  getline(cin, cadena1);
  for (int i = 0; i < cadena1.size(); i++) {
    if (cadena1[i] == cadena1[i + 1]) {
      cont1++;
    }
    if (cadena1[i] != cadena1[i + 1]) {
      cont++;
      cont1 = 0;
    }
    if (cont1 == 5) {
      cont++;
      cont1 = 5;
    }
  }
  cout << cont;
  return 0;
}
