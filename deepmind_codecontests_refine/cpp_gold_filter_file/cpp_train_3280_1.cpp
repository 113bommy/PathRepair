#include <bits/stdc++.h>
using namespace std;
int main() {
  int bouquet, aux, soma = 0;
  set<int> petalsI;
  set<int> petalsP;
  cin >> bouquet;
  while (bouquet--) {
    cin >> aux;
    soma = soma + aux;
    if (aux & 1 == 1)
      petalsI.insert(aux);
    else
      petalsP.insert(aux);
  }
  if (soma & 1 == 1) {
    cout << soma << endl;
  } else {
    if (petalsI.size() > 0) {
      soma = soma - *petalsI.begin();
      cout << soma << endl;
    } else {
      cout << "0" << endl;
    }
  }
  return 0;
}
