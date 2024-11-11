#include <bits/stdc++.h>
using namespace std;
bool verificarRX(string n) {
  if (n[0] != 'R' || n[1] > 64) {
    return false;
  }
  int i = 2;
  while (n[i] != '\0') {
    if (n[i] == 'C') {
      return true;
    }
    i++;
  }
  return false;
}
int potencia(int n) {
  int cant = 1;
  for (int i = 0; i < n - 1; i++) {
    cant *= 10;
  }
  return cant;
}
int strAEnt(string n) {
  int cant = 0;
  while (n[cant] != '\0') {
    cant++;
  }
  int valor = 0;
  int pot = potencia(cant);
  for (int i = 0; i < cant; i++, pot /= 10) {
    valor += (n[i] - 48) * pot;
  }
  return valor;
}
string extraerInt(string n, int valor) {
  string cadena = "";
  int i = valor;
  while (n[i] < 58 && n[i] != '\0') {
    cadena += n[i];
    i++;
  }
  return cadena;
}
int piso(double n) {
  int var = (int)n;
  if (var - n == 0) {
    return var - 1;
  }
  return var;
}
string intAStr(int n) {
  string solu = "";
  while (n > 0) {
    int var = n % 26;
    if (n < 27) {
      solu += n + 64;
      n = 0;
    } else if (var == 0) {
      solu += 'Z';
    } else {
      solu += var + 64;
    }
    n = piso(n / 26.0);
  }
  return solu;
}
void impReves(string n) {
  int cantidad = 0;
  while (n[cantidad] != '\0') {
    cantidad++;
  }
  for (int i = cantidad - 1; i > -1; i--) {
    cout << n[i];
  }
}
void desdeRX(string n) {
  int val = 1;
  while (n[val] < 58) {
    val++;
  }
  impReves(intAStr(strAEnt(extraerInt(n, val + 1))));
  cout << extraerInt(n, 1);
}
int potencia26(int n) {
  int cant = 1;
  for (int i = 0; i < n - 1; i++) {
    cant *= 26;
  }
  return cant;
}
int desdeStr(string n) {
  int cantidad = 0;
  while (n[cantidad] != '\0') {
    cantidad++;
  }
  int limite = cantidad - 1;
  int valor = 0;
  for (int i = 0; i < limite; i++) {
    valor += potencia26(cantidad) * (n[i] - 64);
    cantidad--;
  }
  valor += n[limite] - 64;
  return valor;
}
string extraerStr(string n) {
  string cadena = "";
  int i = 0;
  while (n[i] > 58) {
    cadena += n[i];
    i++;
  }
  return cadena;
}
void desdeAB(string n) {
  cout << 'R';
  int i = 0;
  while (n[i] > 58) {
    i++;
  }
  while (n[i] != '\0') {
    cout << n[i];
    i++;
  }
  cout << 'C';
  cout << desdeStr(extraerStr(n));
}
int main() {
  int n;
  cin >> n;
  string* datos = new string[n];
  for (int i = 0; i < n; i++) {
    cin >> datos[i];
  }
  for (int i = 0; i < n; i++) {
    if (verificarRX(datos[i])) {
      desdeRX(datos[i]);
    } else {
      desdeAB(datos[i]);
    }
    if (i != n - 1) {
      cout << '\n';
    }
  }
  return 0;
}
