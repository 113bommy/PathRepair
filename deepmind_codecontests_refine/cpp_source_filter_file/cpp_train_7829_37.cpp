#include <bits/stdc++.h>
using namespace std;
int main() {
  string cadena[3];
  for (int i = 0; i < 3; i++) {
    cin >> cadena[i];
  }
  if (cadena[0][0] == cadena[2][2] && cadena[0][1] == cadena[2][1] &&
      cadena[0][2] == cadena[2][0] && cadena[1][0] && cadena[1][2])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
