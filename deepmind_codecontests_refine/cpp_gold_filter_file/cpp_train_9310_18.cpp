#include <bits/stdc++.h>
using namespace std;
string elimina(string x, int l, int r) {
  string nu = x.substr(0, l);
  nu += x.substr(r, x.size() - r);
  return nu;
}
string dot(string x) {
  bool tacha[x.size()];
  memset(tacha, 0, sizeof tacha);
  for (int i = 2; i < x.size(); i++) {
    if (x[i - 1] == 'a' & !tacha[i - 1] & x[i] == 't' & !tacha[i]) {
      tacha[i - 1] = 1, tacha[i] = 1;
      x[i - 1] = '@';
      x = elimina(x, i, i + 1);
      break;
    }
  }
  return x;
}
string punto(string x) {
  bool tacha[x.size()];
  memset(tacha, 0, sizeof tacha);
  for (int i = 2; i < x.size(); i++) {
    if (x[i - 2] == 'd' & !tacha[i - 2] & x[i - 1] == 'o' & !tacha[i - 1] &
        x[i] == 't' & !tacha[i]) {
      tacha[i - 2] = 1, tacha[i - 1] = 1, tacha[i] = 1;
      x[i - 2] = '.';
      x = elimina(x, i - 1, i + 1);
    }
  }
  return x;
}
bool veri(string x) {
  for (int i = 2; i < x.size(); i++) {
    if (x[i - 2] == 'd' & x[i - 1] == 'o' & x[i] == 't') {
      return true;
    }
  }
  return false;
}
int main() {
  string letra;
  cin >> letra;
  while (veri(letra)) {
    letra = punto(letra);
  }
  letra = dot(letra);
  if (letra[0] == '.') {
    cout << "dot";
    if (letra[letra.size() - 1] == '.') {
      cout << letra.substr(1, letra.size() - 2);
      cout << "dot";
    } else {
      cout << letra.substr(1, letra.size() - 1);
    }
  } else {
    if (letra[letra.size() - 1] == '.') {
      cout << letra.substr(0, letra.size() - 1);
      cout << "dot";
    } else {
      cout << letra << endl;
    }
  }
}
