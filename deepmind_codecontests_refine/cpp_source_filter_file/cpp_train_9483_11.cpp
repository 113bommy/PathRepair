#include <bits/stdc++.h>
using namespace std;
int main() {
  int zaidimu, pinigai;
  int kainos_zaid[1001], kainos_pinigu[1001];
  int temp_z = 0, temp_p = 0;
  int kiekis = 0;
  cin >> zaidimu >> pinigai;
  for (int i = 0; i < zaidimu; i++) {
    cin >> kainos_zaid[i];
  }
  for (int i = 0; i < pinigai; i++) {
    cin >> kainos_pinigu[i];
  }
  while (temp_z < zaidimu || temp_p < pinigai) {
    if (kainos_zaid[temp_z] <= kainos_pinigu[temp_p]) {
      kiekis++;
      temp_z++;
      temp_p++;
    } else
      temp_z++;
  }
  cout << kiekis;
  return 0;
}
