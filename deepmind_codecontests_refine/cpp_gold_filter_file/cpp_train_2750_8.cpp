#include <bits/stdc++.h>
using namespace std;
bool comprobarNum(vector<int> aux, int num) {
  for (int i = 0; i < aux.size(); i++) {
    if (aux[i] == num) {
      return true;
    }
  }
  return false;
}
int main() {
  int n, aux;
  cin >> n;
  vector<int> s;
  vector<int> numR;
  int contador = 1;
  while (n--) {
    cin >> aux;
    if (comprobarNum(s, aux)) {
      numR.push_back(aux);
    } else {
      s.push_back(aux);
    }
  }
  int max = 1;
  for (int i = 0; i < numR.size(); i++) {
    for (int j = 0; j < numR.size(); j++) {
      if (numR[j] == numR[i]) {
        contador++;
      }
    }
    if (contador > max) max = contador;
    contador = 1;
  }
  cout << max << " " << s.size();
  return 0;
}
