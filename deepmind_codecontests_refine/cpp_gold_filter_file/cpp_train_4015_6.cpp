#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string cad;
  vector<int> lista;
  cin >> n;
  cin >> cad;
  int cont = 0;
  for (int i = 0; i < n; i++) {
    if (cad[i] == 'B') {
      cont++;
    } else {
      if (cont > 0) lista.push_back(cont);
      cont = 0;
    }
    if (i == n - 1 && cont > 0) lista.push_back(cont);
  }
  if (lista.empty())
    cout << 0 << endl;
  else {
    cout << lista.size() << endl;
    for (int i = 0; i < lista.size(); i++) cout << lista[i] << " ";
    cout << endl;
  }
  return 0;
}
