#include <bits/stdc++.h>
using namespace std;
int main() {
  string cadena;
  char extreme = 'a';
  int veces = 0;
  getline(cin, cadena);
  for (string::iterator iter = cadena.begin(); iter != cadena.end(); iter++) {
    if (*iter >= extreme) extreme = *iter;
  }
  for (string::iterator iter = cadena.begin(); iter != cadena.end(); iter++) {
    if (*iter == extreme) veces++;
  }
  for (int i = 0; i < veces; i++) {
    cout << extreme;
  }
  cout << endl;
  return 0;
}
