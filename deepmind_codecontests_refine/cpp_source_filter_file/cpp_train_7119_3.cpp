#include <bits/stdc++.h>
using namespace std;
string I, F;
bool bisiesto(int ano) {
  if (ano % 400 == 0) {
    return true;
  } else {
    if (ano % 4 == 0 && ano % 100 != 0) return true;
  }
  return false;
}
int smano(int ano) {
  int suma = 0;
  for (int i = 0; i < ano; i++) {
    if (bisiesto(i))
      suma += 366;
    else
      suma += 365;
  }
  return suma;
}
int mess(int mes, int ano) {
  int sm = 0;
  for (int k = 1; k <= mes; k++) {
    switch (k) {
      case 1:
        sm += 31;
        break;
      case 3:
        sm += 31;
        break;
      case 5:
        sm += 31;
        break;
      case 7:
        sm += 31;
        break;
      case 8:
        sm += 31;
        break;
      case 10:
        sm += 31;
        break;
      case 12:
        sm += 31;
        break;
      case 4:
        sm += 30;
        break;
      case 6:
        sm += 30;
        break;
      case 9:
        sm += 30;
        break;
      case 11:
        sm += 30;
        break;
      case 2:
        if (bisiesto(ano)) {
          sm += 29;
          break;
        } else {
          sm += 28;
          break;
        }
    }
  }
  return sm;
}
int main() {
  cin >> I >> F;
  int ano, mes, dia, sum1 = 0, sum2 = 0;
  I.replace(4, 1, " ");
  I.replace(7, 1, " ");
  F.replace(4, 1, " ");
  F.replace(7, 1, " ");
  istringstream isi(I);
  istringstream isf(F);
  isi >> ano >> mes >> dia;
  sum1 = smano(ano) + mess(mes, ano) + dia;
  isf >> ano >> mes >> dia;
  sum2 = smano(ano) + mess(mes, ano) + dia;
  if (sum1 > sum2)
    cout << sum1 - sum2;
  else
    cout << sum2 - sum1;
}
